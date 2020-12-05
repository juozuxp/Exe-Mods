#pragma once
#ifndef BOTH_PEDisector_HEADER_INCLUDED
#define BOTH_PEDisector_HEADER_INCLUDED

#include "GeneralErrors.h"

#define GET_IMAGE_DOS_HEADER(PEBuffer) ((IMAGE_DOS_HEADER*)(PEBuffer))
#define GET_IMAGE_NT_HEADERS(PEBuffer) ((IMAGE_NT_HEADERS*)((char*)(PEBuffer) + GET_IMAGE_DOS_HEADER(PEBuffer)->e_lfanew))
#define GET_IMAGE_OPTIONAL_HEADER(PEBuffer) (&GET_IMAGE_NT_HEADERS(PEBuffer)->OptionalHeader)
#define GET_IMAGE_FILE_HEADER(PEBuffer) (&GET_IMAGE_NT_HEADERS(PEBuffer)->FileHeader)
#define GET_IMAGE_FIRST_SECTION(PEBuffer) (IMAGE_FIRST_SECTION(GET_IMAGE_NT_HEADERS(PEBuffer)))
#define GET_IMAGE_EXPORT_DIRECTORY(PEBuffer) ((IMAGE_EXPORT_DIRECTORY*)((char*)(PEBuffer) + GET_IMAGE_OPTIONAL_HEADER(PEBuffer)->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress))
#define GET_IMAGE_FIRST_IMPORT_DESCRIPTOR(PEBuffer) ((IMAGE_IMPORT_DESCRIPTOR*)((char*)(PEBuffer) + GET_IMAGE_OPTIONAL_HEADER(PEBuffer)->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress))
#define GET_IMAGE_BASE_RELOCATION(PEBuffer) ((IMAGE_BASE_RELOCATION*)((char*)(PEBuffer) + GET_IMAGE_OPTIONAL_HEADER(PEBuffer)->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress))

#define IS_IMAGE_EXECUTABLE(PEBuffer) (((IMAGE_DOS_HEADER*)(PEBuffer))->e_magic == *(unsigned short*)"MZ")

typedef struct _UnMappedImportDescriptor
{
	unsigned long FirstThunk;
	unsigned long OriginalFirstThunk;
	IMAGE_IMPORT_DESCRIPTOR * ImportDescriptor;
	IMAGE_SECTION_HEADER* ImportSection;
} UnMappedImportDescriptor, *PUnMappedImportDescriptor;

typedef struct _UnMappedImportHeader
{
	IMAGE_IMPORT_DESCRIPTOR* PEImportDescriptor;
	IMAGE_SECTION_HEADER* DescriptorSection;
} UnMappedImportHeader, *PUnMappedImportHeader;

typedef struct _UnMappedExportDescriptor
{
	unsigned long ExportOffset;
	IMAGE_SECTION_HEADER* ExportSection;
} UnMappedExportDescriptor, *PUnMappedExportDescriptor;

typedef struct _MappedImportDescriptor
{
	void** OriginalFirstThunk;
	void** FirstThunk;
	IMAGE_IMPORT_DESCRIPTOR* ImportDescriptor;
} MappedImportDescriptor, *PMappedImportDescriptor;

static GeneralErrorCast FindAddressSection(void* PEBuffer, void * Address, IMAGE_SECTION_HEADER** AddressHeader)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!Address)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!AddressHeader)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	IMAGE_SECTION_HEADER* SectionHeader;
	IMAGE_FILE_HEADER* FileHeader;
	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;

	DosHeader = ((IMAGE_DOS_HEADER*)PEBuffer);
	NTHeaders = ((IMAGE_NT_HEADERS*)(((char*)PEBuffer) + DosHeader->e_lfanew));
	FileHeader = &NTHeaders->FileHeader;

	SectionHeader = IMAGE_FIRST_SECTION(NTHeaders);
	for (unsigned long i = 0; i < FileHeader->NumberOfSections; i++, SectionHeader++)
		if ((((char*)Address) - ((char*)PEBuffer)) >= SectionHeader->VirtualAddress && (((char*)Address) - ((char*)PEBuffer)) < (SectionHeader->VirtualAddress + SectionHeader->SizeOfRawData))
			break;

	(*AddressHeader) = SectionHeader;
	return STATUS_SUCCESS;
}

static GeneralErrorCast FindImportByNameMapped(void * PEBuffer, const char * ImportName, MappedImportDescriptor* ImportDesc)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ImportName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!ImportDesc)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	memset(ImportDesc, 0, sizeof(MappedImportDescriptor));

	IMAGE_DOS_HEADER * DosHeader;
	IMAGE_NT_HEADERS * NTHeaders;
	IMAGE_OPTIONAL_HEADER * OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR * ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	for (; ImportDescriptor->Name; ImportDescriptor++)
	{
		void ** OriginalFirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->OriginalFirstThunk);
		void ** FirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->FirstThunk);

		if (!OriginalFirstThunk)
			OriginalFirstThunk = FirstThunk;

		for (; *OriginalFirstThunk; OriginalFirstThunk++, FirstThunk++)
		{
			if (!IMAGE_SNAP_BY_ORDINAL((unsigned long long)*OriginalFirstThunk))
			{
				IMAGE_IMPORT_BY_NAME * ImportByName = (IMAGE_IMPORT_BY_NAME*)((char*)PEBuffer + (unsigned long long)*OriginalFirstThunk);
				if (!_stricmp(ImportByName->Name, ImportName))
				{
					ImportDesc->OriginalFirstThunk = OriginalFirstThunk;
					ImportDesc->FirstThunk = FirstThunk;
					ImportDesc->ImportDescriptor = ImportDescriptor;
					return STATUS_SUCCESS;
				}
			}
		}
		
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindImportByNameUnMapped(void * PEBuffer, const char * ImportName, UnMappedImportDescriptor* ImportDesc)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ImportName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!ImportDesc)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	memset(ImportDesc, 0, sizeof(UnMappedImportDescriptor));

	IMAGE_DOS_HEADER * DosHeader;
	IMAGE_NT_HEADERS * NTHeaders;
	IMAGE_SECTION_HEADER* ImportSection;
	IMAGE_OPTIONAL_HEADER * OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR * ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	FindAddressSection(PEBuffer, (((char*)PEBuffer) + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress), &ImportSection);
	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
	for (unsigned long i = 0; (char*)ImportDescriptor - (char*)PEBuffer - ImportSection->VirtualAddress < ImportSection->SizeOfRawData && ImportDescriptor->Name; i++, ImportDescriptor++)
	{
		void ** OriginalFirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->OriginalFirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
		void ** FirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->FirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);

		if (!OriginalFirstThunk)
			OriginalFirstThunk = FirstThunk;

		for (; *OriginalFirstThunk; OriginalFirstThunk++, FirstThunk++)
		{
			if (!IMAGE_SNAP_BY_ORDINAL((unsigned long long)*OriginalFirstThunk))
			{
				IMAGE_IMPORT_BY_NAME * ImportByName = (IMAGE_IMPORT_BY_NAME*)((char*)PEBuffer + (unsigned long long)*OriginalFirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
				if (!_stricmp(ImportByName->Name, ImportName))
				{
					ImportDesc->FirstThunk = ((((char*)FirstThunk) - ImportSection->PointerToRawData + ImportSection->VirtualAddress) - ((char*)PEBuffer));
					ImportDesc->OriginalFirstThunk = ((((char*)OriginalFirstThunk) - ImportSection->PointerToRawData + ImportSection->VirtualAddress) - ((char*)PEBuffer));
					ImportDesc->ImportDescriptor = ImportDescriptor;
					ImportDesc->ImportSection = ImportSection;
					return STATUS_SUCCESS;
				}
			}
		}
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindImportByAddressMapped(void* PEBuffer, void* Address, IMAGE_IMPORT_DESCRIPTOR** ImportDesc)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!Address)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!ImportDesc)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	*ImportDesc = 0;

	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;
	IMAGE_OPTIONAL_HEADER* OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR* ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	for (; ImportDescriptor->Name; ImportDescriptor++)
	{
		void** OriginalFirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->OriginalFirstThunk);
		void** FirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->FirstThunk);

		if (!OriginalFirstThunk)
			OriginalFirstThunk = FirstThunk;

		for (; *OriginalFirstThunk; OriginalFirstThunk++, FirstThunk++)
		{
			if (!IMAGE_SNAP_BY_ORDINAL((unsigned long long) * OriginalFirstThunk))
			{
				IMAGE_IMPORT_BY_NAME* ImportByName = (IMAGE_IMPORT_BY_NAME*)((char*)PEBuffer + (unsigned long long)*OriginalFirstThunk);
				if (*FirstThunk == Address)
				{
					*ImportDesc = ImportDescriptor;
					return STATUS_SUCCESS;
				}
			}
		}
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindImportByAddressUnMapped(void * PEBuffer, void * Address, UnMappedImportDescriptor* ImportDesc)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!Address)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!ImportDesc)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	memset(ImportDesc, 0, sizeof(UnMappedImportDescriptor));

	IMAGE_DOS_HEADER * DosHeader;
	IMAGE_NT_HEADERS * NTHeaders;
	IMAGE_SECTION_HEADER* ImportSection;
	IMAGE_OPTIONAL_HEADER * OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR * ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	FindAddressSection(PEBuffer, (((char*)PEBuffer) + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress), &ImportSection);
	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
	for (; ImportDescriptor->Name; ImportDescriptor++)
	{
		void ** OriginalFirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->OriginalFirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
		void ** FirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->FirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);

		if (!OriginalFirstThunk)
			OriginalFirstThunk = FirstThunk;

		for (; *OriginalFirstThunk; OriginalFirstThunk++, FirstThunk++)
		{
			if (!IMAGE_SNAP_BY_ORDINAL((unsigned long long)*OriginalFirstThunk))
			{
				IMAGE_IMPORT_BY_NAME * ImportByName = (IMAGE_IMPORT_BY_NAME*)((char*)PEBuffer + (unsigned long long)*OriginalFirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
				if (((char*)PEBuffer + (unsigned __int64)*FirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData) == Address)
				{
					ImportDesc->ImportDescriptor = ImportDescriptor;
					ImportDesc->ImportSection = ImportSection;
					return STATUS_SUCCESS;
				}
			}
		}
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast CountImportsMapped(void* PEBuffer, unsigned long* ModuleCount, unsigned long* ImportCount)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ImportCount && !ModuleCount)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (ModuleCount)
		(*ModuleCount) = 0;
	if (ImportCount)
		(*ImportCount) = 0;

	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;
	IMAGE_OPTIONAL_HEADER* OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR* ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	for (; ImportDescriptor->Name; ImportDescriptor++)
	{
		void** OriginalFirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->OriginalFirstThunk);
		void** FirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->FirstThunk);

		if (ModuleCount)
			(*ModuleCount)++;

		if (!OriginalFirstThunk)
			OriginalFirstThunk = FirstThunk;

		for (; *OriginalFirstThunk; OriginalFirstThunk++, FirstThunk++)
			if (ImportCount)
				(*ImportCount)++;
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindImportHeaderByPENameMapped(void* PEBuffer, const char * ImportPEName, IMAGE_IMPORT_DESCRIPTOR ** Descriptor)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ImportPEName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!Descriptor)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;
	IMAGE_OPTIONAL_HEADER* OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR* ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
	for (; ImportDescriptor->Name; ImportDescriptor++)
	{
		if (!stricmp(((char*)PEBuffer) + ImportDescriptor->Name, ImportPEName))
		{
			(*Descriptor) = ImportDescriptor;
			return STATUS_SUCCESS;
		}
	}

	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindImportHeaderByPENameUnMapped(void* PEBuffer, const char* ImportPEName, UnMappedImportHeader* Descriptor)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ImportPEName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!Descriptor)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;
	IMAGE_SECTION_HEADER* ImportSection;
	IMAGE_OPTIONAL_HEADER* OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR* ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	FindAddressSection(PEBuffer, (((char*)PEBuffer) + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress), &ImportSection);
	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
	for (; ImportDescriptor->Name; ImportDescriptor++)
	{
		if (!stricmp(((char*)PEBuffer) + ImportDescriptor->Name - ImportSection->VirtualAddress + ImportSection->PointerToRawData, ImportPEName))
		{
			Descriptor->DescriptorSection = ImportSection;
			Descriptor->PEImportDescriptor = ImportDescriptor;
			return STATUS_SUCCESS;
		}
	}

	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast CountImportsUnMapped(void* PEBuffer, unsigned long * ModuleCount, unsigned long * ImportCount)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ImportCount && !ModuleCount)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (ModuleCount)
		(*ModuleCount) = 0;
	if (ImportCount)
		(*ImportCount) = 0;

	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;
	IMAGE_SECTION_HEADER* ImportSection;
	IMAGE_OPTIONAL_HEADER* OptionalHeader;
	IMAGE_IMPORT_DESCRIPTOR* ImportDescriptor;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	FindAddressSection(PEBuffer, (((char*)PEBuffer) + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress), &ImportSection);
	ImportDescriptor = (IMAGE_IMPORT_DESCRIPTOR*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
	for (; ImportDescriptor->Name; ImportDescriptor++)
	{
		void** OriginalFirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->OriginalFirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);
		void** FirstThunk = (void**)((char*)PEBuffer + ImportDescriptor->FirstThunk - ImportSection->VirtualAddress + ImportSection->PointerToRawData);

		if (ModuleCount)
			(*ModuleCount)++;

		if (!OriginalFirstThunk)
			OriginalFirstThunk = FirstThunk;

		for (; *OriginalFirstThunk; OriginalFirstThunk++, FirstThunk++)
			if (ImportCount)
				(*ImportCount)++;
	}
	return STATUS_SUCCESS;
}

static GeneralErrorCast FindExportByNameMapped(void * PEBuffer, const char * ExportName, void ** ExportAddress)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ExportName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!ExportAddress)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	*ExportAddress = 0;

	IMAGE_DOS_HEADER * DosHeader;
	IMAGE_NT_HEADERS * NTHeaders;
	IMAGE_OPTIONAL_HEADER * OptionalHeader;
	IMAGE_EXPORT_DIRECTORY * ExportDirectory;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	ExportDirectory = (IMAGE_EXPORT_DIRECTORY*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

	unsigned long * AddressesOfFunctions = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfFunctions);
	unsigned long * AddressesOfNames = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfNames);
	unsigned short * AddressOfOrdinals = (unsigned short*)((char*)PEBuffer + ExportDirectory->AddressOfNameOrdinals);

	for (unsigned long i = 0; i < ExportDirectory->NumberOfNames; i++, AddressesOfNames++, AddressOfOrdinals++)
	{
		char * RawExportName = (char*)((char*)PEBuffer + *AddressesOfNames);
		if (!_stricmp(RawExportName, ExportName))
		{
			*ExportAddress = (void*)((char*)PEBuffer + AddressesOfFunctions[*AddressOfOrdinals]);
			return STATUS_SUCCESS;
		}
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindExportByNameUnMapped(void* PEBuffer, const char* ExportName, UnMappedExportDescriptor* Export)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!ExportName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!Export)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	memset(Export, 0, sizeof(UnMappedExportDescriptor));
	
	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;
	IMAGE_SECTION_HEADER* ExportSection;
	IMAGE_OPTIONAL_HEADER* OptionalHeader;
	IMAGE_EXPORT_DIRECTORY* ExportDirectory;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	FindAddressSection(PEBuffer, (((char*)PEBuffer) + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress), &ExportSection);
	ExportDirectory = (IMAGE_EXPORT_DIRECTORY*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress - ExportSection->VirtualAddress + ExportSection->PointerToRawData);

	unsigned long* AddressesOfFunctions = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfFunctions - ExportSection->VirtualAddress + ExportSection->PointerToRawData);
	unsigned long* AddressesOfNames = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfNames - ExportSection->VirtualAddress + ExportSection->PointerToRawData);
	unsigned short* AddressOfOrdinals = (unsigned short*)((char*)PEBuffer + ExportDirectory->AddressOfNameOrdinals - ExportSection->VirtualAddress + ExportSection->PointerToRawData);

	for (unsigned long i = 0; i < ExportDirectory->NumberOfNames; i++, AddressesOfNames++, AddressOfOrdinals++)
	{
		char* RawExportName = (char*)((char*)PEBuffer + *AddressesOfNames - ExportSection->VirtualAddress + ExportSection->PointerToRawData);
		if (!_stricmp(RawExportName, ExportName))
		{
			Export->ExportSection = ExportSection;
			Export->ExportOffset = AddressesOfFunctions[*AddressOfOrdinals];
			return STATUS_SUCCESS;
		}
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindExportByAddressMapped(void * PEBuffer, void * Address, const char ** ExportName)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!Address)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!ExportName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	*ExportName = 0;

	IMAGE_DOS_HEADER * DosHeader;
	IMAGE_NT_HEADERS * NTHeaders;
	IMAGE_OPTIONAL_HEADER * OptionalHeader;
	IMAGE_EXPORT_DIRECTORY * ExportDirectory;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	ExportDirectory = (IMAGE_EXPORT_DIRECTORY*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

	unsigned long * AddressesOfFunctions = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfFunctions);
	unsigned long * AddressesOfNames = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfNames);
	unsigned short * AddressOfOrdinals = (unsigned short*)((char*)PEBuffer + ExportDirectory->AddressOfNameOrdinals);

	for (unsigned long i = 0, ii = 0; i < ExportDirectory->NumberOfFunctions; i++, AddressesOfFunctions++)
	{
		if ((void*)((char*)PEBuffer + *AddressesOfFunctions) == Address)
		{
			if (ii < ExportDirectory->NumberOfNames)
			{
				if (i == AddressOfOrdinals[ii])
					*ExportName = (const char*)((char*)PEBuffer + AddressesOfNames[ii]);
			}
			else
				*ExportName = 0;
			return STATUS_SUCCESS;
		}
		if (ii < ExportDirectory->NumberOfNames)
			if (i == AddressOfOrdinals[ii])
				ii++;
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindExportByAddressUnMapped(void* PEBuffer, void* Address, const char** ExportName)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!Address)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!ExportName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	*ExportName = 0;

	IMAGE_DOS_HEADER* DosHeader;
	IMAGE_NT_HEADERS* NTHeaders;
	IMAGE_OPTIONAL_HEADER* OptionalHeader;
	IMAGE_EXPORT_DIRECTORY* ExportDirectory;
	IMAGE_SECTION_HEADER* ExportSection;
	IMAGE_FILE_HEADER* FileHeader;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	OptionalHeader = &NTHeaders->OptionalHeader;
	FileHeader = &NTHeaders->FileHeader;

	if (!OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_MAPPED_FILE_SIZE_ZERO) | 1;

	FindAddressSection(PEBuffer, (((char*)PEBuffer) + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress), &ExportSection);
	ExportDirectory = (IMAGE_EXPORT_DIRECTORY*)((char*)PEBuffer + OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress - ExportSection->VirtualAddress + ExportSection->PointerToRawData);

	unsigned long* AddressesOfFunctions = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfFunctions - ExportSection->VirtualAddress + ExportSection->PointerToRawData);
	unsigned long* AddressesOfNames = (unsigned long*)((char*)PEBuffer + ExportDirectory->AddressOfNames - ExportSection->VirtualAddress + ExportSection->PointerToRawData);
	unsigned short* AddressOfOrdinals = (unsigned short*)((char*)PEBuffer + ExportDirectory->AddressOfNameOrdinals - ExportSection->VirtualAddress + ExportSection->PointerToRawData);

	for (unsigned long i = 0, ii = 0; i < ExportDirectory->NumberOfFunctions; i++, AddressesOfFunctions++)
	{
		if ((void*)((char*)PEBuffer + *AddressesOfFunctions - ExportSection->VirtualAddress + ExportSection->PointerToRawData) == Address)
		{
			if (ii < ExportDirectory->NumberOfNames)
			{
				if (i == AddressOfOrdinals[ii])
					*ExportName = (const char*)((char*)PEBuffer + AddressesOfNames[ii] - ExportSection->VirtualAddress + ExportSection->PointerToRawData);
			}
			else
				*ExportName = 0;
			return STATUS_SUCCESS;
		}
		if (ii < ExportDirectory->NumberOfNames)
			if (i == AddressOfOrdinals[ii])
				ii++;
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

static GeneralErrorCast FindSectionByName(void * PEBuffer, const char * SectionName, IMAGE_SECTION_HEADER ** SectionDescriptor)
{
	if (!PEBuffer)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_1) | 1;
	if (!SectionName)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_2) | 1;
	if (!SectionDescriptor)
		return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_INVALID_PARAMETER_3) | 1;

	*SectionDescriptor = 0;

	IMAGE_DOS_HEADER * DosHeader;
	IMAGE_NT_HEADERS * NTHeaders;
	IMAGE_FILE_HEADER * FileHeader;
	IMAGE_SECTION_HEADER * SectionHeader;

	DosHeader = (IMAGE_DOS_HEADER*)PEBuffer;
	NTHeaders = (IMAGE_NT_HEADERS*)((char*)PEBuffer + DosHeader->e_lfanew);
	FileHeader = &NTHeaders->FileHeader;

	SectionHeader = IMAGE_FIRST_SECTION(NTHeaders);
	for (unsigned long i = 0; i < FileHeader->NumberOfSections; i++, SectionHeader++)
	{
		if (!_stricmp((const char*)SectionHeader->Name, SectionName))
		{
			*SectionDescriptor = SectionHeader;
			return STATUS_SUCCESS;
		}
	}
	return GENERAL_ERROR_ASSEMBLE(GENERAL_ERROR_HEADER_PEDISECTOR, STATUS_NOT_FOUND) | 1;
}

#endif
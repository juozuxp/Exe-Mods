#include "Imports.h"
#include "PEDisector.h"
#include "AMD64Shell.h"
#include "BasicUtilities.h"
#include <stdio.h>

int main(unsigned long Count, const char ** Args)
{
	UnMappedImportHeader Kernel32Imports;
	IMAGE_SECTION_HEADER* TextSection;
	IMAGE_SECTION_HEADER* NewSection;
	IMAGE_IMPORT_BY_NAME* ImportName;
	IMAGE_FILE_HEADER* FileHeader;
	IMAGE_DOS_HEADER * FileDos;
	IMAGE_NT_HEADERS * FileNts;
	
	HANDLE FileHandle;
	HMODULE Kernel32;

	unsigned long Relativity;
	unsigned long FileSize;
	void* ImportLocation;
	char Path[MAX_PATH];
	void* ShellDump;
	void* FileDump;

	if (Count <= 1)
	{
		printf("Mssing Exe\r\n");
		system("pause");
		exit(0);
	}

	FileHandle = CreateFileA(Args[1], GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	FileSize = GetFileSize(FileHandle, 0);

	FileSize = ((FileSize + 0x400) & ~(0x400 - 1));

	FileDump = VirtualAlloc(0, FileSize + 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	ReadFile(FileHandle, FileDump, FileSize, 0, 0);
	CloseHandle(FileHandle);

	FileDos = ((IMAGE_DOS_HEADER*)FileDump);
	FileNts = ((IMAGE_NT_HEADERS*)(((char*)FileDump) + FileDos->e_lfanew));

	FileHeader = &FileNts->FileHeader;
	
	NewSection = IMAGE_FIRST_SECTION(FileNts) + FileHeader->NumberOfSections;
	FileHeader->NumberOfSections++;

	NewSection->Characteristics = IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ | IMAGE_SCN_MEM_WRITE;
	NewSection->SizeOfRawData = 0x1000;
	NewSection->PointerToRawData = FileSize;
	NewSection->VirtualAddress = FileNts->OptionalHeader.SizeOfImage;
	NewSection->Misc.VirtualSize = 0x1000;

	strcpy(((char*)NewSection->Name), "nottext");

	FileNts->OptionalHeader.SizeOfImage += NewSection->SizeOfRawData;

	Relativity = 0;
	FindImportHeaderByPENameUnMapped(FileDump, "Kernel32.dll", &Kernel32Imports);

	Kernel32 = GetModuleHandleA("Kernel32.dll");
	ImportName = ((IMAGE_IMPORT_BY_NAME*)(((char*)FileDump) + (*(unsigned long long*)(((char*)FileDump) + Kernel32Imports.PEImportDescriptor->OriginalFirstThunk - Kernel32Imports.DescriptorSection->VirtualAddress + Kernel32Imports.DescriptorSection->PointerToRawData)) - Kernel32Imports.DescriptorSection->VirtualAddress + Kernel32Imports.DescriptorSection->PointerToRawData));

	ImportLocation = GetProcAddress(Kernel32, ImportName->Name);
	char Shell[] =
	{
		PUSH_QREG(RCX, Relativity),
		PUSH_QREG(RDX, Relativity),
		PUSH_QREG(RDI, Relativity),
		PUSH_QREG(RBX, Relativity),
		SUB_QREG_DWORD(RSP, (((0x20 + MAX_PATH + sizeof(WIN32_FIND_DATAA)) + 0x8) & ~(0x8 - 1)), Relativity),
		MOV_QREG_PTR_RIP_DWORD_OFFSET(RDI, Kernel32Imports.PEImportDescriptor->FirstThunk - (NewSection->VirtualAddress + Relativity), Relativity),
		MOV_DREG_DWORD(ECX, MAX_PATH, Relativity),
		LEA_QREG_PTR_RSP_BYTE_OFFSET(RSI, 0x20, Relativity),
		MOV_QREG_QREG(RDX, RSI, Relativity),
		LEA_QREG_PTR_QREG_DWORD_OFFSET(RAX, RDI, ((char*)GetProcAddress(Kernel32, "GetCurrentDirectoryA") - ((char*)ImportLocation)), Relativity),
		CALL_QREG(RAX, Relativity),
		ADD_QREG_QREG(RSI, RAX, Relativity),
		MOV_QREG_QWORD(RCX, *((void**)"\\ExeMods"), Relativity),
		MOV_PTR_QREG_QREG(RSI, RCX, Relativity),
		ADD_QREG_BYTE(RSI, sizeof(void*), Relativity),
		MOV_QREG_QWORD(RCX, *((void**)"\\*"), Relativity),
		MOV_PTR_QREG_QREG(RSI, RCX, Relativity),
		SUB_QREG_QREG(RSI, RAX, Relativity),
		SUB_QREG_BYTE(RSI, sizeof(void*), Relativity),
		MOV_QREG_QREG(RCX, RSI, Relativity),
		LEA_QREG_PTR_RSP_DWORD_OFFSET(RDX, 0x20 + MAX_PATH, Relativity),
		LEA_QREG_PTR_QREG_DWORD_OFFSET(RAX, RDI, ((char*)GetProcAddress(Kernel32, "FindFirstFileA") - ((char*)ImportLocation)), Relativity),
		CALL_QREG(RAX, Relativity),
		MOV_QREG_QREG(RBX, RAX, Relativity),
		MOV_QREG_QWORD(RAX, *((void**)"ExeMods\\"), Relativity),
		MOV_PTR_QREG_QREG(RSI, RAX, Relativity),
		LEA_QREG_PTR_RSP_DWORD_OFFSET(RDX, 0x20 + MAX_PATH + ((unsigned long)GetStructElementOffset(WIN32_FIND_DATAA, cFileName)), Relativity), // 0x8 0x0
		MOV_QREG_QREG(RCX, RDX, Relativity), // 0x3 0x8
		CMP_PTR_QREG_BYTE(RCX, '.', Relativity), // 0x3 0x0 0xB
		JE_RIP_BYTE_OFFSET(0xA, Relativity), // 0x2 0x3 0xE
		CMP_PTR_QREG_BYTE(RCX, '\0', Relativity), // 0x3 0x0 0x5 0x10
		INC_QREG(RCX, Relativity), // 0x3 0x3 0x8 0x13
		JE_RIP_BYTE_OFFSET(0x31, Relativity), // 0x2 0x0 0x6 0xB 0x16
		JMP_RIP_BYTE_OFFSET(-0xF, Relativity), // 0x2 0x2 0x8 0xD 0x18
		CMP_PTR_QREG_DWORD(RCX, (*(unsigned long*)".dll"), Relativity), // 0x6 0x4 0x1A
		JNE_RIP_DWORD_OFFSET(0x21, Relativity), // 0x6 0xA 0x20
		LEA_QREG_PTR_QREG_BYTE_OFFSET(RAX, RSI, sizeof("ExeMods\\") - 1, Relativity), // 0x4 0x10 0x26
		PUSH_QREG(RSI, Relativity), // 0x1 0x14 0x2A
		PUSH_QREG(RDI, Relativity), // 0x1 0x15 0x2B
		MOV_QREG_QREG(RDI, RAX, Relativity), // 0x3 0x16 0x2C
		MOV_QREG_QREG(RSI, RDX, Relativity), // 0x3 0x19 0x2F
		MOV_DREG_DWORD(ECX, sizeof(WIN32_FIND_DATAA::cFileName), Relativity), // 0x5 0x1C 0x32
		REP_MOVS_BYTE_PTR(Relativity), // 0x2 0x21 0x37
		POP_QREG(RDI, Relativity), // 0x1 0x23 0x39
		POP_QREG(RSI, Relativity), // 0x1 0x24 0x3A
		MOV_QREG_QREG(RCX, RSI, Relativity), // 0x3 0x25 0x3B
		LEA_QREG_PTR_QREG_DWORD_OFFSET(RAX, RDI, ((char*)GetProcAddress(Kernel32, "LoadLibraryA") - ((char*)ImportLocation)), Relativity), // 0x7 0x28 0x3E
		CALL_QREG(RAX, Relativity), // 0x2 0x2F 0x45
		MOV_QREG_QREG(RCX, RBX, Relativity), // 0x3 0x31 0x47
		LEA_QREG_PTR_RSP_DWORD_OFFSET(RDX, 0x20 + MAX_PATH, Relativity), // 0x8 0x4A
		LEA_QREG_PTR_QREG_DWORD_OFFSET(RAX, RDI, ((char*)GetProcAddress(Kernel32, "FindNextFileA") - ((char*)ImportLocation)), Relativity), // 0x7 0x52
		CALL_QREG(RAX, Relativity), // 0x2 0x59
		TEST_DREG_DREG(EAX, EAX, Relativity), // 0x2 0x5B
		JNE_RIP_DWORD_OFFSET(-0x63, Relativity), // 0x6 0x5D
		ADD_QREG_DWORD(RSP, (((0x20 + MAX_PATH) + 0x8) & ~(0x8 - 1)), Relativity),
		POP_QREG(RBX, Relativity),
		POP_QREG(RDI, Relativity),
		POP_QREG(RDX, Relativity),
		POP_QREG(RCX, Relativity),
		JMP_RIP_DWORD_OFFSET(FileNts->OptionalHeader.AddressOfEntryPoint - (NewSection->VirtualAddress + Relativity), Relativity),
	};

	memcpy(((char*)FileDump) + NewSection->PointerToRawData, Shell, sizeof(Shell));

	FileNts->OptionalHeader.AddressOfEntryPoint = NewSection->VirtualAddress;
	
	strcpy(Path, Args[1]);
	char* Extention = strstr(Path, ".");
	memmove(Extention + sizeof("Infected") - 1, Extention, strlen(Extention) + 1);
	memcpy(Extention, "Infected", sizeof("Infected") - 1);

	FileHandle = CreateFileA(Path, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	WriteFile(FileHandle, FileDump, FileSize + 0x1000, 0, 0);
	CloseHandle(FileHandle);
}
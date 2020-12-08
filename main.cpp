#include "Imports.h"
#include "PEDisector.h"
#include "BasicUtilities.h"
#include <stdio.h>

#define SHELL_RELATIVITY MainRelativity

#include "x86_x64Shell.h"

int main(unsigned long Count, const char ** Args)
{
	UnMappedImportHeader Kernel32Imports;
	IMAGE_SECTION_HEADER* TextSection;
	IMAGE_SECTION_HEADER* NewSection;
	IMAGE_IMPORT_BY_NAME* ImportName;
	IMAGE_FILE_HEADER* FileHeader;
	IMAGE_DOS_HEADER* FileDos;
	IMAGE_NT_HEADERS32* FileNts;
	
	HANDLE FileHandle;
	HMODULE Kernel32;

	unsigned long MainRelativity;
	unsigned long RelativityCP1;
	unsigned long RelativityCP2;
	unsigned long RelativityCP3;
	unsigned long RelativityCP4;
	unsigned long RelativityCP5;

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
	FileNts = ((IMAGE_NT_HEADERS32*)(((char*)FileDump) + FileDos->e_lfanew));

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

	FindImportHeaderByPENameUnMapped(FileDump, "Kernel32.dll", &Kernel32Imports);

	Kernel32 = GetModuleHandleA("Kernel32.dll");
	ImportName = ((IMAGE_IMPORT_BY_NAME*)(((char*)FileDump) + (*(unsigned long long*)(((char*)FileDump) + Kernel32Imports.PEImportDescriptor->OriginalFirstThunk - Kernel32Imports.DescriptorSection->VirtualAddress + Kernel32Imports.DescriptorSection->PointerToRawData)) - Kernel32Imports.DescriptorSection->VirtualAddress + Kernel32Imports.DescriptorSection->PointerToRawData));

	ImportLocation = GetProcAddress(Kernel32, ImportName->Name);

	MainRelativity = 0;

	RelativityCP1 = 0;
	RelativityCP2 = 0;
	RelativityCP3 = 0;
	RelativityCP4 = 0;
	RelativityCP5 = 0;
	D_C_S(Shell,
		PUSHQ_R(RCX),
		PUSHQ_R(RDX),
		PUSHQ_R(RDI),
		PUSHQ_R(RBX),
		PFX_REXW, SUB_RM_D(LR(RSP), (((0x20 + MAX_PATH + sizeof(WIN32_FIND_DATAA)) + 0x8) & ~(0x8 - 1))),
		PFX_REXW, MOVD_R_RM(R_REL_DO(RDI, Kernel32Imports.PEImportDescriptor->FirstThunk - (NewSection->VirtualAddress + MainRelativity))),
		MOV_R_D(ECX, MAX_PATH),
		PFX_REXW, LEAD_R_M(R_MRSP_BO(RSI, 0x20)),
		PFX_REXW, MOVD_RM_R(LR_R(RDX, RSI)),
		PFX_REXW, LEAD_R_M(R_MR_DO(RAX, RDI, ((char*)GetProcAddress(Kernel32, "GetCurrentDirectoryA") - ((char*)ImportLocation)))),
		CALLQ_RM(LR(RAX)),
		PFX_REXW, ADDD_RM_R(LR_R(RSI, RAX)),
		MOV_R_Q(RCX, *((void**)"\\ExeMods")),
		PFX_REXW, MOVD_RM_R(MR_R(RSI, RCX)),
		PFX_REXW, ADDD_RM_B(LR(RSI), sizeof(void*)),
		MOV_R_Q(RCX, *((void**)"\\*")),
		PFX_REXW, MOVD_RM_R(MR_R(RSI, RCX)),
		PFX_REXW, SUBD_RM_R(LR_R(RSI, RAX)),
		PFX_REXW, SUBD_RM_B(LR(RSI), sizeof(void*)),
		PFX_REXW, MOVD_RM_R(LR_R(RCX, RSI)),
		PFX_REXW, LEAD_R_M(R_MRSP_DO(RDX, 0x20 + MAX_PATH)),
		PFX_REXW, LEAD_R_M(R_MR_DO(RAX, RDI, ((char*)GetProcAddress(Kernel32, "FindFirstFileA") - ((char*)ImportLocation)))),
		CALLQ_RM(LR(RAX)),
		PFX_REXW, XORD_RM_R(LR_R(RCX, RCX)),
		PFX_REXW, NOTD_RM(LR(RCX)),
		PFX_REXW, CMPD_RM_R(LR_R(RAX, RCX)),
		JE_RD(RelativityCP5 - MainRelativity),
		PFX_REXW, MOVD_RM_R(LR_R(RBX, RAX)),
		MOV_R_Q(RAX, *((void**)"ExeMods\\")),
		PFX_REXW, MOVD_RM_R(MR_R(RSI, RAX)),
		R_CP(RelativityCP1, PFX_REXW, LEAD_R_M(R_MRSP_DO(RDX, 0x20 + MAX_PATH + ((unsigned long)GetStructElementOffset(WIN32_FIND_DATAA, cFileName))))),
		PFX_REXW, MOVD_RM_R(LR_R(RCX, RDX)),
		R_CP(RelativityCP3, CMP_RM_B(MR(RCX), '.')),
		JE_RB(RelativityCP2 - MainRelativity),
		CMP_RM_B(MR(RCX), '\0'),
		PFX_REXW, INCD_RM(LR(RCX)),
		JE_RB(RelativityCP4 - MainRelativity),
		JMP_RB(RelativityCP3 - MainRelativity),
		R_CP(RelativityCP2, CMP_RM_D(MR(RCX), (*(unsigned long*)".dll"))),
		JNE_RD(RelativityCP4 - MainRelativity),
		PFX_REXW, LEAD_R_M(R_MR_BO(RAX, RSI, sizeof("ExeMods\\") - 1)),
		PUSHQ_R(RSI),
		PUSHQ_R(RDI),
		PFX_REXW, MOVD_RM_R(LR_R(RDI, RAX)),
		PFX_REXW, MOVD_RM_R(LR_R(RSI, RDX)),
		MOV_RM_D(LR(ECX), sizeof(WIN32_FIND_DATAA::cFileName)),
		PFX_REPE, MOVSB,
		POPQ_R(RDI),
		POPQ_R(RSI),
		PFX_REXW, MOVD_RM_R(LR_R(RCX, RSI)),
		PFX_REXW, LEAD_R_M(R_MR_DO(RAX, RDI, ((char*)GetProcAddress(Kernel32, "LoadLibraryA") - ((char*)ImportLocation)))),
		CALLQ_RM(LR(RAX)),
		R_CP(RelativityCP4, PFX_REXW, MOVD_RM_R(LR_R(RCX, RBX))),
		PFX_REXW, LEAD_R_M(R_MRSP_DO(RDX, 0x20 + MAX_PATH)),
		PFX_REXW, LEAD_R_M(R_MR_DO(RAX, RDI, ((char*)GetProcAddress(Kernel32, "FindNextFileA") - ((char*)ImportLocation)))),
		CALLQ_RM(LR(RAX)),
		TESTD_RM_R(LR_R(EAX, EAX)),
		JNE_RD(RelativityCP1 - MainRelativity),
		PFX_REXW, MOVD_RM_R(LR_R(RCX, RBX)),
		PFX_REXW, LEAD_R_M(R_MR_DO(RAX, RDI, ((char*)GetProcAddress(Kernel32, "CloseHandle") - ((char*)ImportLocation)))),
		CALLQ_RM(LR(RAX)),
		R_CP(RelativityCP5, PFX_REXW, ADD_RM_D(LR(RSP), ((0x20 + MAX_PATH) + 0x8) & ~(0x8 - 1))),
		POPQ_R(RBX),
		POPQ_R(RDI),
		POPQ_R(RDX),
		POPQ_R(RCX),
		JMP_RD(FileNts->OptionalHeader.AddressOfEntryPoint - (NewSection->VirtualAddress + MainRelativity))
	);

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
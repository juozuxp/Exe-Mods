#pragma once
#include "BasicUtilities.h"

#ifndef BOTH_AMD64Shell_HEADER_INCLUDED
#define BOTH_AMD64Shell_HEADER_INCLUDED

#pragma region TYPES

#define BYTEPTR(byte) ((byte) & 0xFF) // byte ptr [Size: 0x1]
#define WORDPTR(word) ((word) & 0xFF), (((word) >> 8) & 0xFF) // word ptr [Size: 0x2]
#define DWORDPTR(dword) ((dword) & 0xFF), (((dword) >> 8) & 0xFF), (((dword) >> 16) & 0xFF), (((dword) >> 24) & 0xFF) // dword ptr [Size: 0x4]
#define QWORDPTR(qword) ((qword) & 0xFF), (((qword) >> 8) & 0xFF), (((qword) >> 16) & 0xFF), (((qword) >> 24) & 0xFF), (((qword) >> 32) & 0xFF), (((qword) >> 40) & 0xFF), (((qword) >> 48) & 0xFF), (((qword) >> 56) & 0xFF) // qword ptr [Size: 0x8]

#define BYTECAST(byte) ((unsigned char)(byte)) // byte [Size: 0x1]
#define WORDCAST(word) ((unsigned short)(word)) // word [Size: 0x2]
#define DWORDCAST(dword) ((unsigned long)(dword)) // dword [Size: 0x4]
#define QWORDCAST(qword) ((unsigned long long)(qword)) // qword [Size: 0x8]

#pragma endregion

#pragma region REGISTERS

#define RAX 0x00 // rax
#define RCX 0x01 // rcx
#define RDX 0x02 // rdx
#define RBX 0x03 // rbx
#define RSP 0x04 // rsp
#define RBP 0x05 // rbp
#define RSI 0x06 // rsi
#define RDI 0x07 // rdi

#define EAX 0x00 // eax
#define ECX 0x01 // ecx
#define EDX 0x02 // edx
#define EBX 0x03 // ebx
#define ESP 0x04 // esp
#define EBP 0x05 // ebp
#define ESI 0x06 // esi
#define EDI 0x07 // edi

#define AX 0x00 // ax
#define CX 0x01 // cx
#define DX 0x02 // dx
#define BX 0x03 // bx
#define SP 0x04 // sp
#define BP 0x05 // bp
#define SI 0x06 // si
#define DI 0x07 // di

#define AL 0x00 // al
#define CL 0x01 // cl
#define DL 0x02 // dl
#define BL 0x03 // bl
#define SPL 0x04 // spl
#define BPL 0x05 // bpl
#define SIL 0x06 // sil
#define DIL 0x07 // dil

#define AH 0x00 // ah
#define CH 0x01 // ch
#define DH 0x02 // dh
#define BH 0x03 // bh
#define SPH 0x04 // sph
#define BPH 0x05 // bph
#define SIH 0x06 // sih
#define DIH 0x07 // dih

#define R8 0x00 // r8
#define R9 0x01 // r9
#define R10 0x02 // r10
#define R11 0x03 // r11
#define R12 0x04 // r12
#define R13 0x05 // r13
#define R14 0x06 // r14
#define R15 0x07 // r15

#define R8D 0x00 // r8d
#define R9D 0x01 // r9d
#define R10D 0x02 // r10d
#define R11D 0x03 // r11d
#define R12D 0x04 // r12d
#define R13D 0x05 // r13d
#define R14D 0x06 // r14d
#define R15D 0x07 // r15d

#define R8W 0x00 // r8w
#define R9W 0x01 // r9w
#define R10W 0x02 // r10w
#define R11W 0x03 // r11w
#define R12W 0x04 // r12w
#define R13W 0x05 // r13w
#define R14W 0x06 // r14w
#define R15W 0x07 // r15w

#define R8B 0x00 // r8b
#define R9B 0x01 // r9b
#define R10B 0x02 // r10b
#define R11B 0x03 // r11b
#define R12B 0x04 // r12b
#define R13B 0x05 // r13b
#define R14B 0x06 // r14b
#define R15B 0x07 // r15b

#define XMM0 0x00 // xmm0
#define XMM1 0x01 // xmm1
#define XMM2 0x02 // xmm2
#define XMM3 0x03 // xmm3
#define XMM4 0x04 // xmm4
#define XMM5 0x05 // xmm5
#define XMM6 0x06 // xmm6
#define XMM7 0x07 // xmm7

#define XMM8 0x00 // xmm8
#define XMM9 0x01 // xmm9
#define XMM10 0x02 // xmm10
#define XMM11 0x03 // xmm11
#define XMM12 0x04 // xmm12
#define XMM13 0x05 // xmm13
#define XMM14 0x06 // xmm14
#define XMM15 0x07 // xmm15

#define CR0 0x00 // cr0
#define CR1 0x01 // cr1
#define CR2 0x02 // cr2
#define CR3 0x03 // cr3
#define CR4 0x04 // cr4
#define CR5 0x05 // cr5
#define CR6 0x06 // cr6
#define CR7 0x07 // cr7
#define CR8 0x08 // cr8
#define CR9 0x09 // cr9
#define CR10 0x10 // cr10
#define CR11 0x11 // cr11
#define CR12 0x12 // cr12
#define CR13 0x13 // cr13
#define CR14 0x14 // cr14
#define CR15 0x15 // cr15

#pragma endregion

#pragma region PUSH_INSTRUCTIONS

#define PUSH_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, (BYTEPTR(reg) + 0x50)) // push reg [Size: 0x1]
#define PUSH_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x41, (BYTEPTR(reg) + 0x50)) // push reg [Size: 0x2]

#define REX_PUSH_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x40, (BYTEPTR(reg) + 0x50)) // rex push reg [Size: 0x2]
#define REX_PUSH_QRREG(reg, relativity) PUSH_QRREG(reg, relativity) // rex push reg [Size: 0x2]

#define PUSHF(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0x9C) // pushf [Size: 0x1]
#define REX_PUSHF(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x40, 0x9C // rex pushf [Size: 0x2]

#define PUSH_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0x30)) // push [reg] [Size: 0x2] [reg: no rbp, rsp]
#define PUSH_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, (BYTEPTR(reg) + 0x70), BYTEPTR(BYTECAST(byte_offset))) // push [reg + byte_offset] [Size: 0x3] [reg: no rbp, rsp]
#define PUSH_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, (BYTEPTR(reg) + 0xB0), DWORDPTR(DWORDCAST(dword_offset))) // push [reg + dword_offset] [Size: 0x6] [reg: no rbp, rsp]

#define PUSH_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, 0x34, 0x24) // push [rsp] [Size: 0x3]
#define PUSH_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xFF, 0x74, 0x24, BYTEPTR(BYTECAST(byte_offset))) // push [rsp + byte_offset] [Size: 0x4]
#define PUSH_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xFF, 0xB4, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // push [rsp + dword_offset] [Size: 0x7]

#define PUSH_PTR_RBP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, 0x75, BYTEPTR(BYTECAST(byte_offset))) // push [rbp + byte_offset] [Size: 0x3]
#define PUSH_PTR_RBP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, 0xB5, DWORDPTR(DWORDCAST(dword_offset))) // push [rbp + dword_offset] [Size: 0x6]

#define PUSH_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0x30)) // push [reg] [Size: 0x3]
#define PUSH_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xFF, (BYTEPTR(reg) + 0x70), BYTEPTR(BYTECAST(byte_offset))) // push [reg + byte_offset] [Size: 0x4]
#define PUSH_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xFF, (BYTEPTR(reg) + 0xB0), DWORDPTR(DWORDCAST(dword_offset))) // push [reg + dword_offset] [Size: 0x7]

#define REX_PUSH_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x40, 0xFF, (BYTEPTR(reg) + 0x30)) // rex push [reg] [Size: 0x3] [reg: no rbp, rsp]
#define REX_PUSH_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x40, 0xFF, (BYTEPTR(reg) + 0x70), BYTEPTR(BYTECAST(byte_offset))) // rex push [reg + byte_offset] [Size: 0x4] [reg: no rbp, rsp]
#define REX_PUSH_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x40, 0xFF, (BYTEPTR(reg) + 0xB0), DWORDPTR(DWORDCAST(dword_offset))) // rex push [reg + dword_offset] [Size: 0x7] [reg: no rbp, rsp]

#define REX_PUSH_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x40, 0xFF, 0x34, 0x24) // rex push [rsp] [Size: 0x4]
#define REX_PUSH_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x40, 0xFF, 0x74, 0x24, BYTEPTR(BYTECAST(byte_offset))) // rex push [rsp + byte_offset] [Size: 0x5]
#define REX_PUSH_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x40, 0xFF, 0xB4, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // rex push [rsp + dword_offset] [Size: 0x8]

#define REX_PUSH_PTR_RBP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x40, 0xFF, 0x75, BYTEPTR(BYTECAST(byte_offset))) // rex push [rbp + byte_offset] [Size: 0x4]
#define REX_PUSH_PTR_RBP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x40, 0xFF, 0xB5, DWORDPTR(DWORDCAST(dword_offset))) // rex push [rbp + dword_offset] [Size: 0x7]

#define REX_PUSH_PTR_QRREG(reg, relativity) PUSH_PTR_QRREG(reg, relativity) // rex push [reg] [Size: 0x3]
#define REX_PUSH_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) PUSH_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) // rex push [reg + byte_offset] [Size: 0x4]
#define REX_PUSH_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) PUSH_PTR_QRREG_BYTE_OFFSET(reg, dword_offset, relativity) // rex push [reg + dword_offset] [Size: 0x7]

#define PUSH_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, 0x35, DWORDPTR(DWORDCAST(dword_offset))) // rex push [rip + dword_offset] [Size: 0x6]
#define REX_PUSH_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x40, 0xFF, 0x35, DWORDPTR(DWORDCAST(dword_offset))) // rex push [rip + dword_offset] [Size: 0x7]

#define PUSH_BYTE(byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x6A, BYTEPTR(BYTECAST(byte))) // push byte [Size: 0x2]
#define PUSH_WORD(word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x68, WORDPTR(WORDCAST(word))) // push word [Size: 0x4]
#define PUSH_DWORD(dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x68, DWORDPTR(DWORDCAST(dword))) // push dword [Size: 0x5]

#define REX_PUSH_BYTE(byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x40, 0x6A, BYTEPTR(BYTECAST(byte))) // rex push byte [Size: 0x3]
#define REX_PUSH_WORD(word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x40, 0x66, 0x68, WORDPTR(WORDCAST(word))) // rex push word [Size: 0x5]
#define REX_PUSH_DWORD(dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x40, 0x68, DWORDPTR(DWORDCAST(dword))) // rex push dword [Size: 0x6]

#pragma endregion

#pragma region POP_INSTRUCTIONS

#define POP_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, (BYTEPTR(reg) + 0x58)) // pop reg [Size: 0x1]
#define POP_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x41, (BYTEPTR(reg) + 0x58)) // push reg [Size: 0x2]

#define REX_POP_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x40, (BYTEPTR(reg) + 0x58)) // rex pop reg [Size: 0x2]
#define REX_POP_QRREG(reg, relativity) POP_QRREG(reg, relativity) // rex pop reg [Size: 0x2]

#define POPF(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0x9D) // popf [Size: 0x1]
#define REX_POPF(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x40, 0x9D) // popf [Size: 0x2]

#define POP_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x8F, BYTEPTR(reg)) // pop [reg] [Size: 0x2] [reg: no rbp, rsp]
#define POP_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x8F, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // pop [reg + byte_offset] [Size: 0x3] [reg: no rbp, rsp]
#define POP_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x8F, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // pop [reg + dword_offset] [Size: 0x6] [reg: no rbp, rsp]

#define POP_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x8F, 0x04, 0x24) // pop [rsp] [Size: 0x3]
#define POP_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x8F, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // pop [rsp + byte_offset] [Size: 0x4]
#define POP_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x8F, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // pop [rsp + dword_offset] [Size: 0x7]

#define POP_PTR_RBP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x8F, 0x45, BYTEPTR(BYTECAST(byte_offset))) // pop [rbp + byte_offset] [Size: 0x3]
#define POP_PTR_RBP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x8F, 0x85, DWORDPTR(DWORDCAST(dword_offset))) // pop [rbp + dword_offset] [Size: 0x6]

#define POP_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x8F, BYTEPTR(reg)) // pop [reg] [Size: 0x3]
#define POP_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x8F, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // pop [reg + byte_offset] [Size: 0x4]
#define POP_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x8F, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // pop [reg + dword_offset] [Size: 0x7]

#define REX_POP_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x40, 0x8F, BYTEPTR(reg)) // rex pop [reg] [Size: 0x3] [reg: no rbp, rsp]
#define REX_POP_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x40, 0x8F, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // rex pop [reg + byte_offset] [Size: 0x4] [reg: no rbp, rsp]
#define REX_POP_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x40, 0x8F, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // rex pop [reg + dword_offset] [Size: 0x7] [reg: no rbp, rsp]

#define REX_POP_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x40, 0x8F, 0x04, 0x24) // rex pop [rsp] [Size: 0x4]
#define REX_POP_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x40, 0x8F, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // rex pop [rsp + byte_offset] [Size: 0x5]
#define REX_POP_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x40, 0x8F, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // rex pop [rsp + dword_offset] [Size: 0x8]

#define REX_POP_PTR_RBP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x40, 0x8F, 0x45, BYTEPTR(BYTECAST(byte_offset))) // rex pop [rbp + byte_offset] [Size: 0x4]
#define REX_POP_PTR_RBP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x40, 0x8F, 0x85, DWORDPTR(DWORDCAST(dword_offset))) // rex pop [rbp + dword_offset] [Size: 0x7]

#define REX_POP_PTR_QRREG(reg) POP_PTR_QRREG(reg) // rex pop [reg] [Size: 0x3]
#define REX_POP_PTR_QRREG_BYTE_OFFSET(reg, byte_offset) POP_PTR_QRREG_BYTE_OFFSET(reg, byte_offset) // rex pop [reg + byte_offset] [Size: 0x4]
#define REX_POP_PTR_QRREG_DWORD_OFFSET(reg, dword_offset) POP_PTR_QRREG_DWORD_OFFSET(reg, dword_offset) // rex pop [reg + dword_offset] [Size: 0x7]

#define POP_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x8F, 0x05, DWORDPTR(DWORDCAST(dword_offset))) // pop [rip + dword_offset] [Size: 0x6]
#define REX_POP_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x40, 0x8F, 0x05, DWORDPTR(DWORDCAST(dword_offset))) // rex pop [rip + dword_offset] [Size: 0x7]

#pragma endregion

#pragma region SUB_INSTRUCTIONS

#define SUB_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x83, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x4]
#define SUB_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x81, (BYTEPTR(reg) + 0xE8), DWORDPTR(DWORDCAST(dword))) // sub reg, dword [Size: 0x7]

#define SUB_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x83, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x3]
#define SUB_DREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x81, (BYTEPTR(reg) + 0xE8), DWORDPTR(DWORDCAST(dword))) // sub reg, dword [Size: 0x6]

#define SUB_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x83, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x4]
#define SUB_WREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x81, (BYTEPTR(reg) + 0xE8), WORDPTR(WORDCAST(word))) // sub reg, word [Size: 0x5]

#define SUB_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x80, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x3]

#define SUB_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x83, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x4]
#define SUB_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x81, (BYTEPTR(reg) + 0xE8), DWORDPTR(DWORDCAST(dword))) // sub reg, dword [Size: 0x7]

#define SUB_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x83, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x4]
#define SUB_DRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x81, (BYTEPTR(reg) + 0xE8), DWORDPTR(DWORDCAST(dword))) // sub reg, dword [Size: 0x7]

#define SUB_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x5]
#define SUB_WRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x81, (BYTEPTR(reg) + 0xE8), WORDPTR(WORDCAST(word))) // sub reg, word [Size: 0x6]

#define SUB_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x80, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // sub reg, byte [Size: 0x4]

#define SUB_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x2]
#define SUB_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x28, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x2]

#define SUB_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x4]
#define SUB_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x28, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]

#define SUB_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x4]
#define SUB_BREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x28, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]

#define SUB_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]
#define SUB_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x29, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x4]
#define SUB_BRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x28, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0xC0)) // sub reg0, reg1 [Size: 0x3]

#define SUB_QREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // sub reg0, [reg1] [Size: 0x3]
#define SUB_QREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // sub reg0, [reg1 + byte_offset] [Size: 0x4]
#define SUB_QREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // sub reg0, [reg1 + dword_offset] [Size: 0x7]

#define SUB_QRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // sub reg0, [reg1] [Size: 0x3]
#define SUB_QRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // sub reg0, [reg1 + byte_offset] [Size: 0x4]
#define SUB_QRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // sub reg0, [reg1 + dword_offset] [Size: 0x7]

#define SUB_QRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // sub reg0, [reg1] [Size: 0x3]
#define SUB_QRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // sub reg0, [reg1 + byte_offset] [Size: 0x4]
#define SUB_QRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // sub reg0, [reg1 + dword_offset] [Size: 0x7]

#define SUB_QREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // sub reg0, [reg1] [Size: 0x3]
#define SUB_QREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // sub reg0, [reg1 + byte_offset] [Size: 0x4]
#define SUB_QREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x2B, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // sub reg0, [reg1 + dword_offset] [Size: 0x7]

#pragma endregion

#pragma region ADD_INSTRUCTIONS

#define ADD_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x83, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x4]
#define ADD_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x81, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // add reg, dword [Size: 0x7]

#define ADD_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x83, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x3]
#define ADD_DREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x81, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // add reg, dword [Size: 0x6]

#define ADD_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x83, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x4]
#define ADD_WREG_WORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x81, (BYTEPTR(reg) + 0xC0), WORDPTR(WORDCAST(dword))) // add reg, word [Size: 0x5]

#define ADD_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x80, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x3]

#define ADD_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x83, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x4]
#define ADD_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x81, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // add reg, dword [Size: 0x7]

#define ADD_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x83, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x4]
#define ADD_DRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x81, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // add reg, dword [Size: 0x7]

#define ADD_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x5]
#define ADD_WRREG_WORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x81, (BYTEPTR(reg) + 0xC0), WORDPTR(WORDCAST(dword))) // add reg, word [Size: 0x6]

#define ADD_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x80, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // add reg, byte [Size: 0x4]

#define ADD_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x2]
#define ADD_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x00, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x2]

#define ADD_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x4]
#define ADD_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x00, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]

#define ADD_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x4]
#define ADD_BREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x00, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)} // add reg0, reg1 [Size: 0x3]

#define ADD_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]
#define ADD_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x01, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x4]
#define ADD_BRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x00, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // add reg0, reg1 [Size: 0x3]

#define ADD_QREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // add reg0, [reg1] [Size: 0x3]
#define ADD_QREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // add reg0, [reg1 + byte_offset] [Size: 0x4]
#define ADD_QREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // add reg0, [reg1 + dword_offset] [Size: 0x7]

#define ADD_QRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // add reg0, [reg1] [Size: 0x3]
#define ADD_QRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // add reg0, [reg1 + byte_offset] [Size: 0x4]
#define ADD_QRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // add reg0, [reg1 + dword_offset] [Size: 0x7]

#define ADD_QRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // add reg0, [reg1] [Size: 0x3]
#define ADD_QRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // add reg0, [reg1 + byte_offset] [Size: 0x4]
#define ADD_QRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // add reg0, [reg1 + dword_offset] [Size: 0x7]

#define ADD_QREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // add reg0, [reg1] [Size: 0x3]
#define ADD_QREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // add reg0, [reg1 + byte_offset] [Size: 0x4]
#define ADD_QREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x03, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // add reg0, [reg1 + dword_offset] [Size: 0x7]

#pragma endregion

#pragma region MOV_INSTRUCTIONS

#define MOVDQU_PTR_QREG_XMM0_XMM7(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF3, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x4] [reg: no rsp]
#define MOVDQU_PTR_QREG_BYTE_OFFSET_XMM0_XMM7(reg, byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x5] [reg: no rsp]
#define MOVDQU_PTR_QREG_DWORD_OFFSET_XMM0_XMM7(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF3, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x8] [reg: no rsp]

#define MOVDQU_PTR_QREG_XMM8_XMM15(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x44, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x5] [reg: no rsp]
#define MOVDQU_PTR_QREG_BYTE_OFFSET_XMM8_XMM15(reg, byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x44, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x6] [reg: no rsp]
#define MOVDQU_PTR_QREG_DWORD_OFFSET_XMM8_XMM15(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x44, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x9] [reg: no rsp]

#define MOVDQU_PTR_QRREG_XMM0_XMM7(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x41, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x5] [reg: no rsp]
#define MOVDQU_PTR_QRREG_BYTE_OFFSET_XMM0_XMM7(reg, byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x41, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x6]
#define MOVDQU_PTR_QRREG_DWORD_OFFSET_XMM0_XMM7(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x41, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x9]

#define MOVDQU_PTR_QRREG_XMM8_XMM15(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x45, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x5]
#define MOVDQU_PTR_QRREG_BYTE_OFFSET_XMM8_XMM15(reg, byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x45, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x6]
#define MOVDQU_PTR_QRREG_DWORD_OFFSET_XMM8_XMM15(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x45, 0x0F, 0x7F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x9]

#define MOVDQU_PTR_RSP_XMM0_XMM7(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movdqs [reg], xmm [Size: 0x5]
#define MOVDQU_PTR_RSP_BYTE_OFFSET_XMM0_XMM7(byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movdqs [rsp + byte_offset], xmm [Size: 0x6]
#define MOVDQU_PTR_RSP_DWORD_OFFSET_XMM0_XMM7(dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movdqs [rsp + dword_offset], xmm [Size: 0x9]

#define MOVDQU_PTR_RSP_XMM8_XMM15(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x44, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movdqs [rsp], xmm [Size: 0x6]
#define MOVDQU_PTR_RSP_BYTE_OFFSET_XMM8_XMM15(byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xF3, 0x44, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movdqs [rsp + byte_offset], xmm [Size: 0x7]
#define MOVDQU_PTR_RSP_DWORD_OFFSET_XMM8_XMM15(dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0xF3, 0x44, 0x0F, 0x7F, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movdqs [rsp + dword_offset], xmm [Size: 0xA]

#define MOVDQU_XMM0_XMM7_PTR_QREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF3, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x4] [reg: no rsp]
#define MOVDQU_XMM0_XMM7_PTR_QREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x5] [reg: no rsp]
#define MOVDQU_XMM0_XMM7_PTR_QREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF3, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x8] [reg: no rsp]

#define MOVDQU_XMM8_XMM15_PTR_QREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x44, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x5] [reg: no rsp]
#define MOVDQU_XMM8_XMM15_PTR_QREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x44, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x6] [reg: no rsp]
#define MOVDQU_XMM8_XMM15_PTR_QREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x44, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x9] [reg: no rsp]

#define MOVDQU_XMM0_XMM7_PTR_QRREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x41, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x5]
#define MOVDQU_XMM0_XMM7_PTR_QRREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x41, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x6]
#define MOVDQU_XMM0_XMM7_PTR_QRREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x41, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x9]

#define MOVDQU_XMM8_XMM15_PTR_QRREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x45, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movdqs [reg], xmm [Size: 0x5]
#define MOVDQU_XMM8_XMM15_PTR_QRREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x45, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movdqs [reg + byte_offset], xmm [Size: 0x6]
#define MOVDQU_XMM8_XMM15_PTR_QRREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x45, 0x0F, 0x6F, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movdqs [reg + dword_offset], xmm [Size: 0x9]

#define MOVDQU_XMM0_XMM7_PTR_RSP(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF3, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movdqs [rsp], xmm [Size: 0x5]
#define MOVDQU_XMM0_XMM7_PTR_RSP_BYTE_OFFSET(xmm, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movdqs [rsp + byte_offset], xmm [Size: 0x6]
#define MOVDQU_XMM0_XMM7_PTR_RSP_DWORD_OFFSET(xmm, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF3, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movdqs [rsp + dword_offset], xmm [Size: 0x9]

#define MOVDQU_XMM8_XMM15_PTR_RSP(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF3, 0x44, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movdqs [rsp], xmm [Size: 0x6]
#define MOVDQU_XMM8_XMM15_PTR_RSP_BYTE_OFFSET(xmm, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF3, 0x44, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movdqs [rsp + byte_offset], xmm [Size: 0x7]
#define MOVDQU_XMM8_XMM15_PTR_RSP_DWORD_OFFSET(xmm, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF3, 0x44, 0x0F, 0x6F, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movdqs [rsp + dword_offset], xmm [Size: 0xA]

#define MOVUPS_XMM0_XMM7_PTR_QREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x3] [reg: no rsp]
#define MOVUPS_XMM0_XMM7_PTR_QREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define MOVUPS_XMM0_XMM7_PTR_QREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define MOVUPS_XMM8_XMM15_PTR_QREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x4] [reg: no rsp]
#define MOVUPS_XMM8_XMM15_PTR_QREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define MOVUPS_XMM8_XMM15_PTR_QREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x8] [reg: no rsp]

#define MOVUPS_XMM0_XMM7_PTR_QRREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x3]
#define MOVUPS_XMM0_XMM7_PTR_QRREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x4]
#define MOVUPS_XMM0_XMM7_PTR_QRREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x7]

#define MOVUPS_XMM8_XMM15_PTR_QRREG(xmm, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x4]
#define MOVUPS_XMM8_XMM15_PTR_QRREG_BYTE_OFFSET(xmm, reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x45, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x5]
#define MOVUPS_XMM8_XMM15_PTR_QRREG_DWORD_OFFSET(xmm, reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x45, 0x0F, 0x10, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x8]

#define MOVUPS_XMM0_XMM7_PTR_RSP(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movups xmm, [rsp] [Size: 0x4]
#define MOVUPS_XMM0_XMM7_PTR_RSP_BYTE_OFFSET(xmm, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [rsp + byte_offset] [Size: 0x5]
#define MOVUPS_XMM0_XMM7_PTR_RSP_DWORD_OFFSET(xmm, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [rsp + dword_offset] [Size: 0x8]

#define MOVUPS_XMM8_XMM15_PTR_RSP(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movups xmm, [rsp] [Size: 0x5]
#define MOVUPS_XMM8_XMM15_PTR_RSP_BYTE_OFFSET(xmm, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x44, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [rsp + byte_offset] [Size: 0x6]
#define MOVUPS_XMM8_XMM15_PTR_RSP_DWORD_OFFSET(xmm, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x44, 0x0F, 0x10, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [rsp + dword_offset] [Size: 0x9]

#define MOVUPS_PTR_QREG_XMM0_XMM7(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x3] [reg: no rsp]
#define MOVUPS_PTR_QREG_BYTE_OFFSET_XMM0_XMM7(reg, byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define MOVUPS_PTR_QREG_DWORD_OFFSET_XMM0_XMM7(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define MOVUPS_PTR_QREG_XMM8_XMM15(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x4] [reg: no rsp]
#define MOVUPS_PTR_QREG_BYTE_OFFSET_XMM8_XMM15(reg, byte_offsetg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define MOVUPS_PTR_QREG_DWORD_OFFSET_XMM8_XMM15(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x8] [reg: no rsp]

#define MOVUPS_PTR_QRREG_XMM0_XMM7(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x4]
#define MOVUPS_PTR_QRREG_BYTE_OFFSET_XMM0_XMM7(reg, byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x5]
#define MOVUPS_PTR_QRREG_DWORD_OFFSET_XMM0_XMM7(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x8]

#define MOVUPS_PTR_QRREG_XMM8_XMM15(reg, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg))) // movups xmm, [reg] [Size: 0x4]
#define MOVUPS_PTR_QRREG_BYTE_OFFSET_XMM8_XMM15(reg, byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x45, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [reg + byte_offset] [Size: 0x5]
#define MOVUPS_PTR_QRREG_DWORD_OFFSET_XMM8_XMM15(reg, dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x45, 0x0F, 0x11, (((BYTEPTR(xmm) * 0x08) + BYTEPTR(reg)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [reg + dword_offset] [Size: 0x8]

#define MOVUPS_PTR_RSP_XMM0_XMM7(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movups xmm, [rsp] [Size: 0x4]
#define MOVUPS_PTR_RSP_BYTE_OFFSET_XMM0_XMM7(byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [rsp + byte_offset] [Size: 0x5]
#define MOVUPS_PTR_RSP_DWORD_OFFSET_XMM0_XMM7(dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [rsp + dword_offset] [Size: 0x8]

#define MOVUPS_PTR_RSP_XMM8_XMM15(xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + 0x04), 0x24) // movups xmm, [rsp] [Size: 0x5]
#define MOVUPS_PTR_RSP_BYTE_OFFSET_XMM8_XMM15(byte_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x44, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // movups xmm, [rsp + byte_offset] [Size: 0x6]
#define MOVUPS_PTR_RSP_DWORD_OFFSET_XMM8_XMM15(dword_offset, xmm, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x44, 0x0F, 0x11, ((BYTEPTR(xmm) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // movups xmm, [rsp + dword_offset] [Size: 0x9]

#define MOV_QREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x48, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0x9]
#define MOV_DREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x66, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0x9]
#define MOV_WREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x66, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0x9]
#define MOV_BREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x65, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0x8]

#define MOV_QRREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x4C, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0x9]
#define MOV_DRREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x65, 0x66, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0xA]
#define MOV_WRREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x65, 0x66, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0xA]
#define MOV_BRREG_PTR_GS_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x44, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, gs:[dword_offset] [Size: 0x9]

#define MOV_PTR_GS_DWORD_OFFSET_QREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x48, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0x9]
#define MOV_PTR_GS_DWORD_OFFSET_DREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x65, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0x8]
#define MOV_PTR_GS_DWORD_OFFSET_WREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x66, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0x9]
#define MOV_PTR_GS_DWORD_OFFSET_BREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x65, 0x88, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0x8]

#define MOV_PTR_GS_DWORD_OFFSET_QRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x4C, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0x9]
#define MOV_PTR_GS_DWORD_OFFSET_DRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0x9]
#define MOV_PTR_GS_DWORD_OFFSET_WRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x65, 0x66, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0xA]
#define MOV_PTR_GS_DWORD_OFFSET_BRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x65, 0x44, 0x88, ((BYTEPTR(reg) * 0x08) + 0x04), 0x25, DWORDPTR(DWORDCAST(dword_offset))) // mov gs:[dword_offset], reg [Size: 0x9]

#define MOV_PTR_RIP_DWORD_OFFSET_BYTE(dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xC6, 0x05, DWORDPTR(DWORDCAST(dword_offset)), BYTEPTR(BYTECAST(byte))) // mov [rip + dword_offset], byte [Size: 0x7]
#define MOV_PTR_RIP_DWORD_OFFSET_WORD(dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0xC7, 0x05, DWORDPTR(DWORDCAST(dword_offset)), WORDPTR(WORDCAST(dword))) // mov [rip + dword_offset], word [Size: 0x9]
#define MOV_PTR_RIP_DWORD_OFFSET_DWORD(dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0xC7, 0x05, DWORDPTR(DWORDCAST(dword_offset)), DWORDPTR(DWORDCAST(dword))) // mov [rip + dword_offset], dword [Size: 0xA]

#define MOV_PTR_RIP_DWORD_OFFSET_QREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x89, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x7]
#define MOV_PTR_RIP_DWORD_OFFSET_DREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x89, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x6]
#define MOV_PTR_RIP_DWORD_OFFSET_WREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x89, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x7]
#define MOV_PTR_RIP_DWORD_OFFSET_BREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x88, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x6]

#define MOV_PTR_RIP_DWORD_OFFSET_QRREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x89, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x7]
#define MOV_PTR_RIP_DWORD_OFFSET_DRREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x7]
#define MOV_PTR_RIP_DWORD_OFFSET_WRREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x8]
#define MOV_PTR_RIP_DWORD_OFFSET_BRREG(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x88, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov [rip + dword_offset], reg [Size: 0x7]

#define MOV_QREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x7]
#define MOV_DREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x6]
#define MOV_WREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x7]
#define MOV_BREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x6]

#define MOV_QRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x7]
#define MOV_DRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x7]
#define MOV_WRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x8]
#define MOV_BRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x05), DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rip + dword_offset] [Size: 0x7]

#define MOV_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x2]
#define MOV_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x88, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x2]

#define MOV_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x4]
#define MOV_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x88, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]

#define MOV_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x4]
#define MOV_BREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x88, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]

#define MOV_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]
#define MOV_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x89, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x4]
#define MOV_BRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x88, (((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0)) + 0xC0)) // mov reg0, reg1 [Size: 0x3]

#define MOV_PTR_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3] [reg0: no rsp]
#define MOV_PTR_QREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x2] [reg0: no rsp]
#define MOV_PTR_QREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3] [reg0: no rsp]
#define MOV_PTR_QREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x2] [reg0: no rsp]

#define MOV_PTR_QREG_BYTE_OFFSET_QREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_DREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x3] [reg0: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_WREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_BREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x3] [reg0: no rsp]

#define MOV_PTR_QREG_DWORD_OFFSET_QREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_DREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x6] [reg0: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_WREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_BREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x6] [reg0: no rsp]

#define MOV_PTR_RSP_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x4]
#define MOV_PTR_RSP_DREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x3]
#define MOV_PTR_RSP_WREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x4]
#define MOV_PTR_RSP_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x88, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x3]

#define MOV_PTR_RSP_BYTE_OFFSET_QREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0x89, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x5]
#define MOV_PTR_RSP_BYTE_OFFSET_DREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x89, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x4]
#define MOV_PTR_RSP_BYTE_OFFSET_WREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x89, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x5]
#define MOV_PTR_RSP_BYTE_OFFSET_BREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x88, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x4]

#define MOV_PTR_RSP_DWORD_OFFSET_QREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x89, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x7]
#define MOV_PTR_RSP_DWORD_OFFSET_QREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x89, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x6]
#define MOV_PTR_RSP_DWORD_OFFSET_QREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x89, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x7]
#define MOV_PTR_RSP_DWORD_OFFSET_QREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x88, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x6]

#define MOV_PTR_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3]
#define MOV_PTR_QRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3]
#define MOV_PTR_QRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x4]
#define MOV_PTR_QRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3]

#define MOV_PTR_QRREG_BYTE_OFFSET_QRREG(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4]
#define MOV_PTR_QRREG_BYTE_OFFSET_DRREG(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4]
#define MOV_PTR_QRREG_BYTE_OFFSET_WRREG(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x45, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x5]
#define MOV_PTR_QRREG_BYTE_OFFSET_BRREG(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4]

#define MOV_PTR_QRREG_DWORD_OFFSET_QRREG(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7]
#define MOV_PTR_QRREG_DWORD_OFFSET_DRREG(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7]
#define MOV_PTR_QRREG_DWORD_OFFSET_WRREG(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x45, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x8]
#define MOV_PTR_QRREG_DWORD_OFFSET_BRREG(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7]

#define MOV_PTR_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3]
#define MOV_PTR_QRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3]
#define MOV_PTR_QRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x4]
#define MOV_PTR_QRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3]

#define MOV_PTR_QRREG_BYTE_OFFSET_QREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4]
#define MOV_PTR_QRREG_BYTE_OFFSET_DREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4]
#define MOV_PTR_QRREG_BYTE_OFFSET_WREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x5]
#define MOV_PTR_QRREG_BYTE_OFFSET_BREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4]

#define MOV_PTR_QRREG_DWORD_OFFSET_QREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7]
#define MOV_PTR_QRREG_DWORD_OFFSET_DREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7]
#define MOV_PTR_QRREG_DWORD_OFFSET_WREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x41, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x8]
#define MOV_PTR_QRREG_DWORD_OFFSET_BREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7]

#define MOV_PTR_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3] [reg0: no rsp]
#define MOV_PTR_QREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3] [reg0: no rsp]
#define MOV_PTR_QREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x4] [reg0: no rsp]
#define MOV_PTR_QREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0))) // mov [reg0], reg1 [Size: 0x3] [reg0: no rsp]

#define MOV_PTR_QREG_BYTE_OFFSET_QRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x89, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_DRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x89, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_WRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x89, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x5] [reg0: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_BRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x88, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]

#define MOV_PTR_QREG_DWORD_OFFSET_QRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_DRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_WRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x89, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x8] [reg0: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_BRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x88, ((BYTEPTR(reg1) * 0x08) + BYTEPTR(reg0) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]

#define MOV_PTR_RSP_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x4]
#define MOV_PTR_RSP_DRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x4]
#define MOV_PTR_RSP_WRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x5]
#define MOV_PTR_RSP_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x88, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov [rsp], reg [Size: 0x4]

#define MOV_PTR_RSP_BYTE_OFFSET_QRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x4C, 0x89, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x5]
#define MOV_PTR_RSP_BYTE_OFFSET_DRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x5]
#define MOV_PTR_RSP_BYTE_OFFSET_WRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x6]
#define MOV_PTR_RSP_BYTE_OFFSET_BRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x88, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov [rsp + byte_offset], reg [Size: 0x5]

#define MOV_PTR_RSP_DWORD_OFFSET_QRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4C, 0x89, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x8]
#define MOV_PTR_RSP_DWORD_OFFSET_DRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x8]
#define MOV_PTR_RSP_DWORD_OFFSET_WRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x44, 0x89, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x9]
#define MOV_PTR_RSP_DWORD_OFFSET_BRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x88, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov [rsp + dword_offset], reg [Size: 0x8]

#define MOV_PTR_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xC6, BYTEPTR(reg), BYTEPTR(BYTECAST(byte))) // mov [reg], byte [Size: 0x3] [reg: no rsp]
#define MOV_PTR_QREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xC7, BYTEPTR(reg), WORDPTR(WORDCAST(word))) // mov [reg], word [Size: 0x5] [reg: no rsp]
#define MOV_PTR_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xC7, BYTEPTR(reg), DWORDPTR(DWORDCAST(dword))) // mov [reg], dword [Size: 0x6] [reg: no rsp]

#define MOV_PTR_QREG_BYTE_OFFSET_BYTE(reg, byte_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xC6, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset)), BYTEPTR(BYTECAST(byte))) // mov [reg + byte_offset], byte [Size: 0x4] [reg: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_WORD(reg, byte_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0xC7, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset)), WORDPTR(WORDCAST(word))) // mov [reg + byte_offset], word [Size: 0x6] [reg: no rsp]
#define MOV_PTR_QREG_BYTE_OFFSET_DWORD(reg, byte_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xC7, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset)), DWORDPTR(DWORDCAST(dword))) // mov [reg + byte_offset], dword [Size: 0x7] [reg: no rsp]

#define MOV_PTR_QREG_DWORD_OFFSET_BYTE(reg, dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xC6, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset)), BYTEPTR(BYTECAST(byte))) // mov [reg + dword_offset], byte [Size: 0x7] [reg: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_WORD(reg, dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0xC7, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset)), WORDPTR(WORDCAST(word))) // mov [reg + dword_offset], word [Size: 0x9] [reg: no rsp]
#define MOV_PTR_QREG_DWORD_OFFSET_DWORD(reg, dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0xC7, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset)), DWORDPTR(DWORDCAST(dword))) // mov [reg + dword_offset], dword [Size: 0xA] [reg: no rsp]

#define MOV_PTR_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xC6, BYTEPTR(reg), BYTEPTR(BYTECAST(byte))) // mov [reg], byte [Size: 0x4]
#define MOV_PTR_QRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x41, 0x66, 0xC7, BYTEPTR(reg), WORDPTR(WORDCAST(word))) // mov [reg], word [Size: 0x6]
#define MOV_PTR_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xC7, BYTEPTR(reg), DWORDPTR(DWORDCAST(dword))) // mov [reg], dword [Size: 0x7]

#define MOV_PTR_QRREG_BYTE_OFFSET_BYTE(reg, byte_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0xC6, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset)), BYTEPTR(BYTECAST(byte))) // mov [reg + byte_offset], byte [Size: 0x5]
#define MOV_PTR_QRREG_BYTE_OFFSET_WORD(reg, byte_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x66, 0xC7, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset)), WORDPTR(WORDCAST(word))) // mov [reg + byte_offset], word [Size: 0x7]
#define MOV_PTR_QRREG_BYTE_OFFSET_DWORD(reg, byte_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0xC7, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset)), DWORDPTR(DWORDCAST(dword))) // mov [reg + byte_offset], dword [Size: 0x8]

#define MOV_PTR_QRREG_DWORD_OFFSET_BYTE(reg, dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0xC6, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset)), BYTEPTR(BYTECAST(byte))) // mov [reg + dword_offset], byte [Size: 0x8]
#define MOV_PTR_QRREG_DWORD_OFFSET_WORD(reg, dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x41, 0x66, 0xC7, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset)), WORDPTR(WORDCAST(word))) // mov [reg + dword_offset], word [Size: 0xA]
#define MOV_PTR_QRREG_DWORD_OFFSET_DWORD(reg, dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xB, 0x41, 0xC7, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset)), DWORDPTR(DWORDCAST(dword))) // mov [reg + dword_offset], dword [Size: 0xB]

#define MOV_PTR_RSP_BYTE(byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xC6, 0x04, 0x24, BYTEPTR(BYTECAST(byte))) // mov [rsp], byte [Size: 0x4]
#define MOV_PTR_RSP_WORD(word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0xC7, 0x04, 0x24, WORDPTR(WORDCAST(word))) // mov [rsp], word [Size: 0x6]
#define MOV_PTR_RSP_DWORD(dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xC7, 0x04, 0x24, DWORDPTR(DWORDCAST(dword))) // mov [rsp], dword [Size: 0x7]

#define MOV_PTR_RSP_BYTE_OFFSET_BYTE(byte_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xC6, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset)), BYTEPTR(BYTECAST(byte))) // mov [rsp + byte_offset], byte [Size: 0x5]
#define MOV_PTR_RSP_BYTE_OFFSET_WORD(byte_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0xC7, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset)), WORDPTR(WORDCAST(word))) // mov [rsp + byte_offset], word [Size: 0x7]
#define MOV_PTR_RSP_BYTE_OFFSET_DWORD(byte_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xC7, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset)), DWORDPTR(DWORDCAST(dword))) // mov [rsp + byte_offset], dword [Size: 0x8]

#define MOV_PTR_RSP_DWORD_OFFSET_BYTE(dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xC6, 0x84, 0x24, DWORDPTR(DWORDCAST(byte_offset)), BYTEPTR(BYTECAST(byte))) // mov [rsp + dword_offset], byte [Size: 0x8]
#define MOV_PTR_RSP_DWORD_OFFSET_WORD(dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x66, 0xC7, 0x84, 0x24, DWORDPTR(DWORDCAST(byte_offset)), WORDPTR(WORDCAST(word))) // mov [rsp + dword_offset], word [Size: 0xA]
#define MOV_PTR_RSP_DWORD_OFFSET_DWORD(dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xB, 0xC7, 0x84, 0x24, DWORDPTR(DWORDCAST(byte_offset)), DWORDPTR(DWORDCAST(dword))) // mov [rsp + dword_offset], dword [Size: 0xB]

#define MOV_QREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no rsp]
#define MOV_DREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x2] [reg1: no rsp]
#define MOV_WREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no rsp]
#define MOV_BREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x8A, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x2] [reg1: no rsp]

#define MOV_QREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define MOV_DREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x3] [reg1: no rsp]
#define MOV_WREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define MOV_BREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x3] [reg1: no rsp]

#define MOV_QREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]
#define MOV_DREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x6] [reg1: no rsp]
#define MOV_WREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]
#define MOV_BREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x6] [reg1: no rsp]

#define MOV_QRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no r12, r13]
#define MOV_DRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no r12, r13]
#define MOV_WRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x4] [reg1: no r12, r13]
#define MOV_BRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x8A, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no r12, r13]

#define MOV_QRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no r12]
#define MOV_DRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no r12]
#define MOV_WRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x45, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x5] [reg1: no r12]
#define MOV_BRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no r12]

#define MOV_QRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no r12]
#define MOV_DRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no r12]
#define MOV_WRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x45, 0x8B, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x8] [reg1: no r12]
#define MOV_BRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no r12]

#define MOV_QREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no r12, r13]
#define MOV_DREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no r12, r13]
#define MOV_WREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x4] [reg1: no r12, r13]
#define MOV_BREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x8A, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no r12, r13]

#define MOV_QREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no r12]
#define MOV_DREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no r12]
#define MOV_WREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x5] [reg1: no r12]
#define MOV_BREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no r12]

#define MOV_QREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no r12]
#define MOV_DREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no r12]
#define MOV_WREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x41, 0x8B, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x8] [reg1: no r12]
#define MOV_BREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no r12]

#define MOV_QRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no rsp]
#define MOV_DRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no rsp]
#define MOV_WRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x8B, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x4] [reg1: no rsp]
#define MOV_BRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x8A, ((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1))) // mov reg0, [reg1] [Size: 0x3] [reg1: no rsp]

#define MOV_QRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define MOV_DRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define MOV_WRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x5] [reg1: no rsp]
#define MOV_BRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // mov reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]

#define MOV_QRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]
#define MOV_DRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x8B, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]
#define MOV_WRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x8B, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x8] [reg1: no rsp]
#define MOV_BRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x8A, (((BYTEPTR(reg0) * 0x08) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // mov reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define MOV_QREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x4]
#define MOV_DREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x3]
#define MOV_WREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x4]
#define MOV_BREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x3]

#define MOV_QREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x5]
#define MOV_DREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x4]
#define MOV_WREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x5]
#define MOV_BREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x4]

#define MOV_QREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x8]
#define MOV_DREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x7]
#define MOV_WREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x8]
#define MOV_BREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x7]

#define MOV_QRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x4]
#define MOV_DRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x4]
#define MOV_WRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x5]
#define MOV_BRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [rsp] [Size: 0x4]

#define MOV_QRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x4C, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x5]
#define MOV_DRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x5]
#define MOV_WRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x6]
#define MOV_BRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [rsp + byte_offset] [Size: 0x5]

#define MOV_QRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4C, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x8]
#define MOV_DRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x8]
#define MOV_WRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x44, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x9]
#define MOV_BRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [rsp + dword_offset] [Size: 0x8]

#define MOV_QRREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x4]
#define MOV_DRREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x4]
#define MOV_WRREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x45, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x5]
#define MOV_BRREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x4]

#define MOV_QRREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x4D, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x5]
#define MOV_DRREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x45, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x5]
#define MOV_WRREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x45, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x6]
#define MOV_BRREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x45, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x5]

#define MOV_QRREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4D, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x8]
#define MOV_DRREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x45, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x8]
#define MOV_WRREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x45, 0x8B, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x9]
#define MOV_BRREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x45, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x8] 

#define MOV_QREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x4]
#define MOV_DREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x4]
#define MOV_WREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x5]
#define MOV_BREG_PTR_R12(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x04), 0x24) // mov reg, [r12] [Size: 0x4]

#define MOV_QREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x49, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x5]
#define MOV_DREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x5]
#define MOV_WREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x6]
#define MOV_BREG_PTR_R12_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // mov reg, [r12 + byte_offset] [Size: 0x5]

#define MOV_QREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x49, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x8]
#define MOV_DREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x8B, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x8]
#define MOV_WREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x41, 0x8B, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x9]
#define MOV_BREG_PTR_R12_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x8A, ((BYTEPTR(reg) * 0x08) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // mov reg, [r12 + dword_offset] [Size: 0x8]

#define MOV_QREG_QWORD(reg, qword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x48, (BYTEPTR(reg) + 0xB8), QWORDPTR(QWORDCAST(qword))) // mov reg, qword [Size: 0xA]
#define MOV_DREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword))) // mov reg, dword [Size: 0x5]
#define MOV_WREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, (BYTEPTR(reg) + 0xB8), WORDPTR(WORDCAST(word))) // mov reg, word [Size: 0x4]
#define MOV_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x40, (BYTEPTR(reg) + 0xB0), BYTEPTR(BYTECAST(byte))) // mov reg, byte [Size: 0x3]

#define MOV_QRREG_QWORD(reg, qword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x49, (BYTEPTR(reg) + 0xB8), QWORDPTR(QWORDCAST(qword))) // mov reg, qword [Size: 0xA]
#define MOV_DRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x41, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword))) // mov reg, dword [Size: 0x6]
#define MOV_WRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, (BYTEPTR(reg) + 0xB8), WORDPTR(WORDCAST(word))) // mov reg, word [Size: 0x5]
#define MOV_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, (BYTEPTR(reg) + 0xB0), BYTEPTR(BYTECAST(byte))) // mov reg, byte [Size: 0x3]

#define MOV_CR0_7_QREG(cr, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x22, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov cr, reg [Size: 0x3]
#define MOV_CR8_15_QREG(cr, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x0F, 0x22, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov cr, reg [Size: 0x4]
#define MOV_QREG_CR0_7(reg, cr, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x20, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov reg, cr [Size: 0x3]
#define MOV_QREG_CR8_15(reg, cr, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x0F, 0x20, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov reg, cr [Size: 0x4]

#define MOV_CR0_7_QRREG(cr, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x22, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov cr, reg [Size: 0x4]
#define MOV_CR8_15_QRREG(cr, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x0F, 0x22, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov cr, reg [Size: 0x4]
#define MOV_QRREG_CR0_7(reg, cr, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x20, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov reg, cr [Size: 0x4]
#define MOV_QRREG_CR8_15(reg, cr, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x0F, 0x20, (((BYTEPTR(cr) * 0x8) + BYTEPTR(reg)) + 0xC0)) // mov reg, cr [Size: 0x4]

#pragma endregion

#pragma region XCHG_INSTRUCTIONS

#define XCHG_PTR_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no rsp, rbp]
#define XCHG_PTR_QREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x2] [reg0: no rsp, rbp]
#define XCHG_PTR_QREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no rsp, rbp]
#define XCHG_PTR_QREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x86, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x2] [reg0: no rsp, rbp]

#define XCHG_PTR_QREG_BYTE_OFFSET_QREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define XCHG_PTR_QREG_BYTE_OFFSET_DREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x3] [reg0: no rsp]
#define XCHG_PTR_QREG_BYTE_OFFSET_WREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define XCHG_PTR_QREG_BYTE_OFFSET_BREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x3] [reg0: no rsp]

#define XCHG_PTR_QREG_DWORD_OFFSET_QREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define XCHG_PTR_QREG_DWORD_OFFSET_DREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x6] [reg0: no rsp]
#define XCHG_PTR_QREG_DWORD_OFFSET_WREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define XCHG_PTR_QREG_DWORD_OFFSET_BREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x6] [reg0: no rsp]

#define XCHG_PTR_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no r12, r13]
#define XCHG_PTR_QRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no r12, r13]
#define XCHG_PTR_QRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x4] [reg0: no r12, r13]
#define XCHG_PTR_QRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x86, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no r12, r13]

#define XCHG_PTR_QRREG_BYTE_OFFSET_QREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no r12]
#define XCHG_PTR_QRREG_BYTE_OFFSET_DREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no r12]
#define XCHG_PTR_QRREG_BYTE_OFFSET_WREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x5] [reg0: no r12]
#define XCHG_PTR_QRREG_BYTE_OFFSET_BREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no r12]

#define XCHG_PTR_QRREG_DWORD_OFFSET_QREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no r12]
#define XCHG_PTR_QRREG_DWORD_OFFSET_DREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no r12]
#define XCHG_PTR_QRREG_DWORD_OFFSET_WREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x41, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x8] [reg0: no r12]
#define XCHG_PTR_QRREG_DWORD_OFFSET_BREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no r12]

#define XCHG_PTR_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no rsp, rbp]
#define XCHG_PTR_QREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no rsp, rbp]
#define XCHG_PTR_QREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x4] [reg0: no rsp, rbp]
#define XCHG_PTR_QREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x86, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no rsp, rbp]

#define XCHG_PTR_QREG_BYTE_OFFSET_QRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define XCHG_PTR_QREG_BYTE_OFFSET_DRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]
#define XCHG_PTR_QREG_BYTE_OFFSET_WRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x5] [reg0: no rsp]
#define XCHG_PTR_QREG_BYTE_OFFSET_BRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no rsp]

#define XCHG_PTR_QREG_DWORD_OFFSET_QRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define XCHG_PTR_QREG_DWORD_OFFSET_DRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]
#define XCHG_PTR_QREG_DWORD_OFFSET_WRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x8] [reg0: no rsp]
#define XCHG_PTR_QREG_DWORD_OFFSET_BRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no rsp]

#define XCHG_PTR_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no r12, r13]
#define XCHG_PTR_QRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no r12, r13]
#define XCHG_PTR_QRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x87, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x4] [reg0: no r12, r13]
#define XCHG_PTR_QRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x86, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0))) // xchg [reg0], reg1 [Size: 0x3] [reg0: no r12, r13]

#define XCHG_PTR_QRREG_BYTE_OFFSET_QRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no r12]
#define XCHG_PTR_QRREG_BYTE_OFFSET_DRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no r12]
#define XCHG_PTR_QRREG_BYTE_OFFSET_WRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x45, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x5] [reg0: no r12]
#define XCHG_PTR_QRREG_BYTE_OFFSET_BRREG(reg0, byte_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // xchg [reg0 + byte_offset], reg1 [Size: 0x4] [reg0: no r12]

#define XCHG_PTR_QRREG_DWORD_OFFSET_QRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no r12]
#define XCHG_PTR_QRREG_DWORD_OFFSET_DRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no r12]
#define XCHG_PTR_QRREG_DWORD_OFFSET_WRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x45, 0x87, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x8] [reg0: no r12]
#define XCHG_PTR_QRREG_DWORD_OFFSET_BRREG(reg0, dword_offset, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x86, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // xchg [reg0 + dword_offset], reg1 [Size: 0x7] [reg0: no r12]

#define XCHG_PTR_RSP_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x87, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x4]
#define XCHG_PTR_RSP_DREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x87, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x3]
#define XCHG_PTR_RSP_WREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x87, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x4]
#define XCHG_PTR_RSP_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x86, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x3]

#define XCHG_PTR_RSP_BYTE_OFFSET_QREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x5]
#define XCHG_PTR_RSP_BYTE_OFFSET_DREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x4]
#define XCHG_PTR_RSP_BYTE_OFFSET_WREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x5]
#define XCHG_PTR_RSP_BYTE_OFFSET_BREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x86, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x4]

#define XCHG_PTR_RSP_DWORD_OFFSET_QREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x8]
#define XCHG_PTR_RSP_DWORD_OFFSET_DREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x7]
#define XCHG_PTR_RSP_DWORD_OFFSET_WREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x8]
#define XCHG_PTR_RSP_DWORD_OFFSET_BREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x86, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x7]

#define XCHG_PTR_RSP_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x4]
#define XCHG_PTR_RSP_DRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x4]
#define XCHG_PTR_RSP_WRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x5]
#define XCHG_PTR_RSP_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x86, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [rsp], reg [Size: 0x4]

#define XCHG_PTR_RSP_BYTE_OFFSET_QRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x4C, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x5]
#define XCHG_PTR_RSP_BYTE_OFFSET_DRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x5]
#define XCHG_PTR_RSP_BYTE_OFFSET_WRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x6]
#define XCHG_PTR_RSP_BYTE_OFFSET_BRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x86, ((BYTEPTR(reg1) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [rsp + byte_offset], reg [Size: 0x5]

#define XCHG_PTR_RSP_DWORD_OFFSET_QRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4C, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x8]
#define XCHG_PTR_RSP_DWORD_OFFSET_DRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x8]
#define XCHG_PTR_RSP_DWORD_OFFSET_WRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x44, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x9]
#define XCHG_PTR_RSP_DWORD_OFFSET_BRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x86, ((BYTEPTR(reg1) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [rsp + dword_offset], reg [Size: 0x8]

#define XCHG_PTR_R12_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [r12], reg [Size: 0x4]
#define XCHG_PTR_R12_DREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [r12], reg [Size: 0x4]
#define XCHG_PTR_R12_WREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x87, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [r12], reg [Size: 0x5]
#define XCHG_PTR_R12_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x86, ((BYTEPTR(reg1) * 0x8) + 0x04), 0x24) // xchg [r12], reg [Size: 0x4]

#define XCHG_PTR_R12_BYTE_OFFSET_QREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x49, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x5]
#define XCHG_PTR_R12_BYTE_OFFSET_DREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x5]
#define XCHG_PTR_R12_BYTE_OFFSET_WREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x6]
#define XCHG_PTR_R12_BYTE_OFFSET_BREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x86, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x5]

#define XCHG_PTR_R12_DWORD_OFFSET_QREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x49, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x8]
#define XCHG_PTR_R12_DWORD_OFFSET_DREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x8]
#define XCHG_PTR_R12_DWORD_OFFSET_WREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x41, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x9]
#define XCHG_PTR_R12_DWORD_OFFSET_BREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x86, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x8]

#define XCHG_PTR_R12_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x87, ((BYTEPTR(reg) * 0x8) + 0x04)) // xchg [r12], reg [Size: 0x3]
#define XCHG_PTR_R12_DRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x87, ((BYTEPTR(reg) * 0x8) + 0x04)) // xchg [r12], reg [Size: 0x3]
#define XCHG_PTR_R12_WRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x87, ((BYTEPTR(reg) * 0x8) + 0x04)) // xchg [r12], reg [Size: 0x4]
#define XCHG_PTR_R12_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x86, ((BYTEPTR(reg) * 0x8) + 0x04)) // xchg [r12], reg [Size: 0x3]

#define XCHG_PTR_R12_BYTE_OFFSET_QRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x4]
#define XCHG_PTR_R12_BYTE_OFFSET_DRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x4]
#define XCHG_PTR_R12_BYTE_OFFSET_WRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x45, 0x87, ((BYTEPTR(reg) * 0x8) + 0x44), BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x5]
#define XCHG_PTR_R12_BYTE_OFFSET_BRREG(byte_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x86, ((BYTEPTR(reg) * 0x8) + 0x44), BYTEPTR(BYTECAST(byte_offset))) // xchg [r12 + byte_offset], reg [Size: 0x4]

#define XCHG_PTR_R12_DWORD_OFFSET_QRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x7]
#define XCHG_PTR_R12_DWORD_OFFSET_DRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x87, ((BYTEPTR(reg) * 0x8) + 0x84), DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x7]
#define XCHG_PTR_R12_DWORD_OFFSET_WRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x45, 0x87, (((BYTEPTR(reg) * 0x8) + 0x84), DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x8]
#define XCHG_PTR_R12_DWORD_OFFSET_BRREG(dword_offset, reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x86, ((BYTEPTR(reg) * 0x8) + 0x84), DWORDPTR(DWORDCAST(dword_offset))) // xchg [r12 + dword_offset], reg [Size: 0x7]

#pragma endregion

#pragma region LOCK_INSTRUCTIONS

#define LOCK_INC_QWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x48, 0xFF, 0x05, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x8]
#define LOCK_INC_DWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xF0, 0xFF, 0x05, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x7]
#define LOCK_INC_WORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0xF0, 0xFF, 0x05, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x8]
#define LOCK_INC_BYTE_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xF0, 0xFE, 0x05, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x7]

#define LOCK_INC_QWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x48, 0xFF, BYTEPTR(reg)) // lock inc [reg] [Size: 0x4] [reg: no rsp]
#define LOCK_INC_DWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF0, 0xFF, BYTEPTR(reg)) // lock inc [reg] [Size: 0x3] [reg: no rsp]
#define LOCK_INC_WORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xF0, 0xFF, BYTEPTR(reg)) // lock inc [reg] [Size: 0x4] [reg: no rsp]
#define LOCK_INC_BYTE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF0, 0xFE, BYTEPTR(reg)) // lock inc [reg] [Size: 0x3] [reg: no rsp]

#define LOCK_INC_QWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x48, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define LOCK_INC_DWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define LOCK_INC_WORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xF0, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define LOCK_INC_BYTE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFE, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x4] [reg: no rsp]

#define LOCK_INC_QWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF0, 0x48, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x8] [reg: no rsp]
#define LOCK_INC_DWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF0, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x7] [reg: no rsp]
#define LOCK_INC_WORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0xF0, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x8] [reg: no rsp]
#define LOCK_INC_BYTE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF0, 0xFE, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define LOCK_INC_QWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x49, 0xFF, BYTEPTR(reg)) // lock inc [reg] [Size: 0x4]
#define LOCK_INC_DWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x41, 0xFF, BYTEPTR(reg)) // lock inc [reg] [Size: 0x4]
#define LOCK_INC_WORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xF0, 0x41, 0xFE, BYTEPTR(reg)) // lock inc [reg] [Size: 0x5]
#define LOCK_INC_BYTE_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x41, 0xFE, BYTEPTR(reg)) // lock inc [reg] [Size: 0x4]

#define LOCK_INC_QWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x49, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x5]
#define LOCK_INC_DWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x41, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x5]
#define LOCK_INC_WORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0xF0, 0x41, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x6]
#define LOCK_INC_BYTE_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x41, 0xFE, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lock inc [reg + byte_offset] [Size: 0x5]

#define LOCK_INC_QWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x49, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x8]
#define LOCK_INC_DWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x41, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x8]
#define LOCK_INC_WORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0xF0, 0x41, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x9]
#define LOCK_INC_BYTE_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x41, 0xFE, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lock inc [reg + dword_offset] [Size: 0x8]

#define LOCK_INC_QWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x48, 0xFF, 0x04, 0x24) // lock inc [rsp] [Size: 0x5]
#define LOCK_INC_DWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFF, 0x04, 0x24)  // lock inc [rsp] [Size: 0x4]
#define LOCK_INC_WORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xF0, 0xFF, 0x04, 0x24)  // lock inc [rsp] [Size: 0x5]
#define LOCK_INC_BYTE_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFE, 0x04, 0x24)  // lock inc [rsp] [Size: 0x4]

#define LOCK_INC_QWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF0, 0x48, 0xFF, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock inc [rsp + byte_offset] [Size: 0x6]
#define LOCK_INC_DWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0xFF, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock inc [rsp + byte_offset] [Size: 0x5]
#define LOCK_INC_WORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0xF0, 0xFF, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock inc [rsp + byte_offset] [Size: 0x6]
#define LOCK_INC_BYTE_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0xFE, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock inc [rsp + byte_offset] [Size: 0x5]

#define LOCK_INC_QWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF0, 0x48, 0xFF, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock inc [rsp + dword_offset] [Size: 0x9] [reg: no rsp]
#define LOCK_INC_DWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0xFF, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock inc [rsp + dword_offset] [Size: 0x8] [reg: no rsp]
#define LOCK_INC_WORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0xF0, 0xFF, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock inc [rsp + dword_offset] [Size: 0x9] [reg: no rsp]
#define LOCK_INC_BYTE_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0xFE, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock inc [rsp + dword_offset] [Size: 0x8] [reg: no rsp]

#define LOCK_DEC_QWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x48, 0xFF, 0x0D, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x8]
#define LOCK_DEC_DWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xF0, 0xFF, 0x0D, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x7]
#define LOCK_DEC_WORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0xF0, 0xFF, 0x0D, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x8]
#define LOCK_DEC_BYTE_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xF0, 0xFE, 0x0D, DWORDPTR(dword_offset)) // lock inc [rip + dword_offset] [Size: 0x7]

#define LOCK_DEC_QWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x48, 0xFF, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x4] [reg: no rsp]
#define LOCK_DEC_DWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF0, 0xFF, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x3] [reg: no rsp]
#define LOCK_DEC_WORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xF0, 0xFF, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x4] [reg: no rsp]
#define LOCK_DEC_BYTE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF0, 0xFE, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x3] [reg: no rsp]

#define LOCK_DEC_QWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x48, 0xFF, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define LOCK_DEC_DWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFF, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define LOCK_DEC_WORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xF0, 0xFF, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define LOCK_DEC_BYTE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFE, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x4] [reg: no rsp]

#define LOCK_DEC_QWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x48, 0xFF, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x8] [reg: no rsp]
#define LOCK_DEC_DWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xF0, 0xFF, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x7] [reg: no rsp]
#define LOCK_DEC_WORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0xF0, 0xFF, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x8] [reg: no rsp]
#define LOCK_DEC_BYTE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xF0, 0xFE, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define LOCK_DEC_QWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x49, 0xFF, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x4] [reg: no rsp]
#define LOCK_DEC_DWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x41, 0xFF, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x4] [reg: no rsp]
#define LOCK_DEC_WORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xF0, 0x41, 0xFF, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x5] [reg: no rsp]
#define LOCK_DEC_BYTE_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0x41, 0xFE, (BYTECAST(reg) + 0x8)) // lock dec [reg] [Size: 0x4] [reg: no rsp]

#define LOCK_DEC_QWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x49, 0xFF, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define LOCK_DEC_DWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x41, 0xFF, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x5] [reg: no rsp]
#define LOCK_DEC_WORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0xF0, 0x41, 0xFF, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x6] [reg: no rsp]
#define LOCK_DEC_BYTE_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x41, 0xFE, (BYTECAST(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // lock dec [reg + byte_offset] [Size: 0x5] [reg: no rsp]

#define LOCK_DEC_QWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x49, 0xFF, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x8] [reg: no rsp]
#define LOCK_DEC_DWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x41, 0xFF, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x8] [reg: no rsp]
#define LOCK_DEC_WORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0xF0, 0x41, 0xFF, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x9] [reg: no rsp]
#define LOCK_DEC_BYTE_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0x41, 0xFE, (BYTECAST(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // lock dec [reg + dword_offset] [Size: 0x8] [reg: no rsp]

#define LOCK_DEC_QWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0x48, 0xFF, 0x0C, 0x24) // lock dec [rsp] [Size: 0x5]
#define LOCK_DEC_DWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFF, 0x0C, 0x24) // lock dec [rsp] [Size: 0x4]
#define LOCK_DEC_WORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xF0, 0xFF, 0x0C, 0x24) // lock dec [rsp] [Size: 0x5]
#define LOCK_DEC_BYTE_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xF0, 0xFE, 0x0C, 0x24) // lock dec [rsp] [Size: 0x4]

#define LOCK_DEC_QWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF0, 0x48, 0xFF, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock dec [rsp + byte_offset] [Size: 0x6]
#define LOCK_DEC_DWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0xFF, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock dec [rsp + byte_offset] [Size: 0x5]
#define LOCK_DEC_WORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0xF0, 0xFF, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock dec [rsp + byte_offset] [Size: 0x6]
#define LOCK_DEC_BYTE_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xF0, 0xFE, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // lock dec [rsp + byte_offset] [Size: 0x5]

#define LOCK_DEC_QWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0xF0, 0x48, 0xFF, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock dec [rsp + dword_offset] [Size: 0x9]
#define LOCK_DEC_DWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0xFF, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock dec [rsp + dword_offset] [Size: 0x8]
#define LOCK_DEC_WORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0xF0, 0xFF, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock dec [rsp + dword_offset] [Size: 0x9]
#define LOCK_DEC_BYTE_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0xF0, 0xFE, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lock dec [rsp + dword_offset] [Size: 0x8]

#pragma endregion

#pragma region XOR_INSTRUCTIONS

#define XOR_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x31, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x3]
#define XOR_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x31, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x2]
#define XOR_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x31, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x3]
#define XOR_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x30, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x2]

#define XOR_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x31, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x3]
#define XOR_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x31, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x3]
#define XOR_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x31, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x4]
#define XOR_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x30, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0xC0)) // xor reg0, reg1 [Size: 0x3]

#define XOR_QREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x33, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x7]
#define XOR_DREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x33, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x6]
#define XOR_WREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x33, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x7]
#define XOR_BREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x32, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x6]

#define XOR_QRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x33, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x7]
#define XOR_DRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x33, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x7]
#define XOR_WRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x33, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x8]
#define XOR_BRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x32, (BYTEPTR(reg) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // xor reg, [rip + dword_offset] [Size: 0x7]

#define XOR_QREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_DREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x2]
#define XOR_WREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_BREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x32, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x2]

#define XOR_QRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_DRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_WRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x4]
#define XOR_BRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x32, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]

#define XOR_QREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_DREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_WREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x4]
#define XOR_BREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x32, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]

#define XOR_QRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_DRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]
#define XOR_WRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x33, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x4]
#define XOR_BRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x32, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // xor reg0, [reg1] [Size: 0x3]

#define XOR_QREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x4]
#define XOR_DREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x3]
#define XOR_WREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x4]
#define XOR_BREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x32, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x3]

#define XOR_QRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x4]
#define XOR_DRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x4]
#define XOR_WRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x5]
#define XOR_BRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x32, ((BYTEPTR(reg) * 0x8) + 0x4)), 0x24 // xor reg, [rsp] [Size: 0x4]

#define XOR_QREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_DREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x3]
#define XOR_WREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_BREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x32, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x3]

#define XOR_QRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_DRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_WRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x5]
#define XOR_BRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x32, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]

#define XOR_QREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_DREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_WREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x5]
#define XOR_BREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x32, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]

#define XOR_QRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_DRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]
#define XOR_WRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x45, 0x33, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x5]
#define XOR_BRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x32, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40)), BYTEPTR(BYTECAST(byte_offset)) // xor reg0, [reg1 + byte_offset] [Size: 0x4]

#define XOR_QREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x5]
#define XOR_DREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x4]
#define XOR_WREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x33, ((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x5]
#define XOR_BREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x32, ((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x4]

#define XOR_QRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x4C, 0x33, (((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x5]
#define XOR_DRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x33, (((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x5]
#define XOR_WRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x44, 0x33, (((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x6]
#define XOR_BRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x32, (((BYTEPTR(reg) * 0x8) + 0x4)) + 0x40), 0x24, BYTEPTR(BYTECAST(byte_offset)) // xor reg, [rsp + byte_offset] [Size: 0x5]

#define XOR_QREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_DREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x6]
#define XOR_WREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_BREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x32, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x6]

#define XOR_QRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_DRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_WRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x8]
#define XOR_BRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x32, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]

#define XOR_QREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_DREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_WREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x41, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x8]
#define XOR_BREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x32, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]

#define XOR_QRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_DRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]
#define XOR_WRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x45, 0x33, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x8]
#define XOR_BRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x32, (((DWORDPTR(reg0) * 0x8) + DWORDPTR(reg1)) + 0x80)), DWORDPTR(DWORDCAST(dword_offset)) // xor reg0, [reg1 + dword_offset] [Size: 0x7]

#define XOR_QREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0x33, ((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x8]
#define XOR_DREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x33, ((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x7]
#define XOR_WREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x33, ((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x8]
#define XOR_BREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x32, ((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x7]

#define XOR_QRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4C, 0x33, (((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x8]
#define XOR_DRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x33, (((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x8]
#define XOR_WRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x44, 0x33, (((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x9]
#define XOR_BRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x32, (((DWORDPTR(reg) * 0x8) + 0x4)) + 0x80), 0x24, DWORDPTR(DWORDCAST(dword_offset)) // xor reg, [rsp + dword_offset] [Size: 0x8]

#pragma endregion

#pragma region AND_INSTRUCTIONS

#define AND_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x81, (BYTEPTR(reg) + 0xE0), DWORDPTR(DWORDCAST(dword))) // and reg, byte [Size: 0x7]
#define AND_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x83, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x4]

#define AND_DREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x81, (BYTEPTR(reg) + 0xE0), DWORDPTR(DWORDCAST(dword))) // and reg, byte [Size: 0x6]
#define AND_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x83, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x3]

#define AND_WREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x81, (BYTEPTR(reg) + 0xE0), WORDPTR(WORDCAST(word))) // and reg, word [Size: 0x5]
#define AND_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x83, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x4]

#define AND_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x80, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x3]

#define AND_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x81, (BYTEPTR(reg) + 0xE0), DWORDPTR(DWORDCAST(dword))) // and reg, byte [Size: 0x7]
#define AND_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x83, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x4]

#define AND_DRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x81, (BYTEPTR(reg) + 0xE0), DWORDPTR(DWORDCAST(dword))) // and reg, byte [Size: 0x7]
#define AND_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x83, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x4]

#define AND_WRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x81, (BYTEPTR(reg) + 0xE0), WORDPTR(WORDCAST(word))) // and reg, word [Size: 0x6]
#define AND_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x5]

#define AND_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x80, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // and reg, byte [Size: 0x4]

#define AND_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x2]
#define AND_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x20, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x2]

#define AND_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x4]
#define AND_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x20, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]

#define AND_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x4]
#define AND_BREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x20, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]

#define AND_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]
#define AND_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x21, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x4]
#define AND_BRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x20, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // and reg0, reg1 [Size: 0x3]

#pragma endregion

#pragma region NOT_INSTRUCTIONS

#define NOT_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0xF7, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x3]
#define NOT_DREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF7, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x2]
#define NOT_WREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0xF7, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x3]
#define NOT_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF6, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x2]

#define NOT_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0xF7, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x3]
#define NOT_DRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xF7, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x3]
#define NOT_WRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0xF7, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x4]
#define NOT_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xF6, (BYTEPTR(reg) + 0xD0)) // not reg [Size: 0x3]

#pragma endregion

#pragma region OR_INSTRUCTIONS

#define OR_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x81, (BYTEPTR(reg) + 0xC8), DWORDPTR(DWORDCAST(dword))) // or reg, dword [Size: 0x7]
#define OR_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x83, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x4] 

#define OR_DREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x81, (BYTEPTR(reg) + 0xC8), DWORDPTR(DWORDCAST(dword))) // or reg, dword [Size: 0x6]
#define OR_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x83, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x3]

#define OR_WREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x81, (BYTEPTR(reg) + 0xC8), WORDPTR(WORDCAST(dword))) // or reg, word [Size: 0x5]
#define OR_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x83, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x4]

#define OR_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x80, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x3]

#define OR_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x81, (BYTEPTR(reg) + 0xC8), DWORDPTR(DWORDCAST(dword))) // or reg, dword [Size: 0x7]
#define OR_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x83, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x4]

#define OR_DRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x81, (BYTEPTR(reg) + 0xC8), DWORDPTR(DWORDCAST(dword))) // or reg, dword [Size: 0x7]
#define OR_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x83, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x4]

#define OR_WRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x81, (BYTEPTR(reg) + 0xC8), WORDPTR(WORDCAST(dword))) // or reg, word [Size: 0x6]
#define OR_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x5]

#define OR_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x80, (BYTEPTR(reg) + 0xC8), BYTEPTR(BYTECAST(byte))) // or reg, byte [Size: 0x4]

#define OR_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x2]
#define OR_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x08, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x2]

#define OR_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x4]
#define OR_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x08, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]

#define OR_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x4]
#define OR_BRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x08, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]

#define OR_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]
#define OR_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x09, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x4]
#define OR_BREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x08, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // or reg0, reg1 [Size: 0x3]

#pragma endregion

#pragma region SHL_INSTRUCTIONS

#define SHL_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0xC1, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x4]
#define SHL_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xC1, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x3]
#define SHL_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xC1, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x4]
#define SHL_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xC0, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x3]

#define SHL_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0xC1, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x4]
#define SHL_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xC1, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x4]
#define SHL_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0xC1, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x5]
#define SHL_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xC0, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // shl reg, byte [Size: 0x4]

#pragma endregion

#pragma region SHR_INSTRUCTIONS

#define SHR_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0xC1, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x4]
#define SHR_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xC1, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x3]
#define SHR_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xC1, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x4]
#define SHR_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xC0, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x3]

#define SHR_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0xC1, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x4]
#define SHR_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xC1, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x4]
#define SHR_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0xC1, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x5]
#define SHR_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xC0, (BYTEPTR(reg) + 0xE8), BYTEPTR(BYTECAST(byte))) // shr reg, byte [Size: 0x4]

#pragma endregion

#pragma region MUL_INSTRUCTIONS

#define MUL_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0xF7, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x3]
#define MUL_DREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF7, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x2]
#define MUL_WREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0xF7, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x3]
#define MUL_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF6, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x2]

#define MUL_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0xF7, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x3]
#define MUL_DRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xF7, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x3]
#define MUL_WRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0xF7, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x4]
#define MUL_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xF6, (BYTEPTR(reg) + 0xE0)) // mul reg [Size: 0x3]

#pragma endregion

#pragma region INC_INSTRUCTIONS

#define INC_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0xFF, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x3]
#define INC_DREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x2]
#define INC_WREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0xFF, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x3]
#define INC_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFE, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x3]

#define INC_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0xFF, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x3]
#define INC_DRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x3]
#define INC_WRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0xFF, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x4]
#define INC_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFE, (BYTEPTR(reg) + 0xC0)) // inc reg [Size: 0x3]

#define INC_QWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0xFF, BYTEPTR(reg)) // inc qword ptr [reg] [Size: 0x3] [reg: no rsp, rbp]
#define INC_DWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, BYTEPTR(reg)) // inc dword ptr [reg] [Size: 0x2] [reg: no rsp, rbp]
#define INC_WORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0xFF, BYTEPTR(reg)) // inc word ptr [reg] [Size: 0x3] [reg: no rsp, rbp]
#define INC_BYTE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFE, BYTEPTR(reg)) // inc qword ptr [reg] [Size: 0x2] [reg: no rsp, rbp]

#define INC_QWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc qword ptr [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define INC_DWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc dword ptr [reg + byte_offset] [Size: 0x3] [reg: no rsp]
#define INC_WORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc word ptr [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define INC_BYTE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFE, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc qword ptr [reg + byte_offset] [Size: 0x3] [reg: no rsp]

#define INC_QWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [reg + dword_offset] [Size: 0x7] [reg: no rsp]
#define INC_DWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc dword ptr [reg + dword_offset] [Size: 0x6] [reg: no rsp]
#define INC_WORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc word ptr [reg + dword_offset] [Size: 0x7] [reg: no rsp]
#define INC_BYTE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFE, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [reg + dword_offset] [Size: 0x6] [reg: no rsp]

#define INC_QWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0xFF, BYTEPTR(reg)) // inc qword ptr [reg] [Size: 0x3]
#define INC_DWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, BYTEPTR(reg)) // inc dword ptr [reg] [Size: 0x3]
#define INC_WORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0xFF, BYTEPTR(reg)) // inc word ptr [reg] [Size: 0x4]
#define INC_BYTE_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFE, BYTEPTR(reg)) // inc qword ptr [reg] [Size: 0x3]

#define INC_QWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc qword ptr [reg + byte_offset] [Size: 0x4]
#define INC_DWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc dword ptr [reg + byte_offset] [Size: 0x4]
#define INC_WORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0xFF, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc word ptr [reg + byte_offset] [Size: 0x5]
#define INC_BYTE_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xFE, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // inc qword ptr [reg + byte_offset] [Size: 0x4]

#define INC_QWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [reg + dword_offset] [Size: 0x7]
#define INC_DWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc dword ptr [reg + dword_offset] [Size: 0x7]
#define INC_WORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x41, 0xFF, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc word ptr [reg + dword_offset] [Size: 0x8]
#define INC_BYTE_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xFE, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [reg + dword_offset] [Size: 0x7]

#define INC_QWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0xFF, 0x04, 0x24) // inc qword ptr [rsp] [Size: 0x4]
#define INC_DWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, 0x04, 0x24) // inc dword ptr [rsp] [Size: 0x3]
#define INC_WORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xFF, 0x04, 0x24) // inc word ptr [rsp] [Size: 0x4]
#define INC_BYTE_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFE, 0x04, 0x24) // inc qword ptr [rsp] [Size: 0x3]

#define INC_QWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0xFF, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // inc qword ptr [rsp + byte_offset] [Size: 0x5]
#define INC_DWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xFF, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // inc dword ptr [rsp + byte_offset] [Size: 0x4]
#define INC_WORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xFF, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // inc word ptr [rsp + byte_offset] [Size: 0x5]
#define INC_BYTE_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xFE, 0x44, 0x24, BYTEPTR(BYTECAST(byte_offset))) // inc qword ptr [rsp + byte_offset] [Size: 0x4]

#define INC_QWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0xFF, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [rsp + dword_offset] [Size: 0x8]
#define INC_DWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xFF, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // inc dword ptr [rsp + dword_offset] [Size: 0x7]
#define INC_WORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0xFF, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // inc word ptr [rsp + dword_offset] [Size: 0x8]
#define INC_BYTE_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xFE, 0x84, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [rsp + dword_offset] [Size: 0x7]

#define INC_QWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0xFF, 0x05, DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [rip + dword_offset] [Size: 0x7]
#define INC_DWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, 0x05, DWORDPTR(DWORDCAST(dword_offset))) // inc dword ptr [rip + dword_offset] [Size: 0x6]
#define INC_WORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0xFF, 0x05, DWORDPTR(DWORDCAST(dword_offset))) // inc word ptr [rip + dword_offset] [Size: 0x7]
#define INC_BYTE_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFE, 0x05, DWORDPTR(DWORDCAST(dword_offset))) // inc qword ptr [rip + dword_offset] [Size: 0x6]

#pragma endregion

#pragma region DEC_INSTRUCTIONS

#define DEC_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0xFF, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x3]
#define DEC_DREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x2]
#define DEC_WREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0xFF, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x3]
#define DEC_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFE, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x2]

#define DEC_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0xFF, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x3]
#define DEC_DRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x3]
#define DEC_WRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0xFF, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x4]
#define DEC_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFE, (BYTEPTR(reg) + 0xC8)) // dec reg [Size: 0x3]

#define DEC_QWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0xFF, (BYTEPTR(reg) + 0x08)) // dec qword ptr [reg] [Size: 0x3] [reg: no rsp, rbp]
#define DEC_DWORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0x08)) // dec dword ptr [reg] [Size: 0x2] [reg: no rsp, rbp]
#define DEC_WORD_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0xFF, (BYTEPTR(reg) + 0x08)) // dec word ptr [reg] [Size: 0x3] [reg: no rsp, rbp]
#define DEC_BYTE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFE, (BYTEPTR(reg) + 0x08)) // dec qword ptr [reg] [Size: 0x2] [reg: no rsp, rbp]

#define DEC_QWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0xFF, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec qword ptr [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define DEC_DWORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec dword ptr [reg + byte_offset] [Size: 0x3] [reg: no rsp]
#define DEC_WORD_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xFF, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec word ptr [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define DEC_BYTE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFE, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec qword ptr [reg + byte_offset] [Size: 0x3] [reg: no rsp]

#define DEC_QWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0xFF, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [reg + dword_offset] [Size: 0x7] [reg: no rsp]
#define DEC_DWORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec dword ptr [reg + dword_offset] [Size: 0x6] [reg: no rsp]
#define DEC_WORD_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0xFF, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec word ptr [reg + dword_offset] [Size: 0x7] [reg: no rsp]
#define DEC_BYTE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFE, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [reg + dword_offset] [Size: 0x6] [reg: no rsp]

#define DEC_QWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0xFF, (BYTEPTR(reg) + 0x08)) // dec qword ptr [reg] [Size: 0x3]
#define DEC_DWORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0x08)) // dec dword ptr [reg] [Size: 0x3]
#define DEC_WORD_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0xFF, (BYTEPTR(reg) + 0x08)) // dec word ptr [reg] [Size: 0x4]
#define DEC_BYTE_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFE, (BYTEPTR(reg) + 0x08)) // dec qword ptr [reg] [Size: 0x3]

#define DEC_QWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0xFF, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec qword ptr [reg + byte_offset] [Size: 0x4]
#define DEC_DWORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xFF, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec dword ptr [reg + byte_offset] [Size: 0x4]
#define DEC_WORD_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0xFF, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec word ptr [reg + byte_offset] [Size: 0x5]
#define DEC_BYTE_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xFE, (BYTEPTR(reg) + 0x48), BYTEPTR(BYTECAST(byte_offset))) // dec qword ptr [reg + byte_offset] [Size: 0x4]

#define DEC_QWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0xFF, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [reg + dword_offset] [Size: 0x7]
#define DEC_DWORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xFF, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec dword ptr [reg + dword_offset] [Size: 0x7]
#define DEC_WORD_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x41, 0xFF, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec word ptr [reg + dword_offset] [Size: 0x8]
#define DEC_BYTE_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xFE, (BYTEPTR(reg) + 0x88), DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [reg + dword_offset] [Size: 0x7]

#define DEC_QWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0xFF, 0x0C, 0x24) // dec qword ptr [rsp] [Size: 0x4]
#define DEC_DWORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, 0x0C, 0x24) // dec dword ptr [rsp] [Size: 0x3]
#define DEC_WORD_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0xFF, 0x0C, 0x24) // dec word ptr [rsp] [Size: 0x4]
#define DEC_BYTE_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFE, 0x0C, 0x24) // dec qword ptr [rsp] [Size: 0x3]

#define DEC_QWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0xFF, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // dec qword ptr [rsp + byte_offset] [Size: 0x5]
#define DEC_DWORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xFF, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // dec dword ptr [rsp + byte_offset] [Size: 0x4]
#define DEC_WORD_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xFF, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // dec word ptr [rsp + byte_offset] [Size: 0x5]
#define DEC_BYTE_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xFE, 0x4C, 0x24, BYTEPTR(BYTECAST(byte_offset))) // dec qword ptr [rsp + byte_offset] [Size: 0x4]

#define DEC_QWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0xFF, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [rsp + dword_offset] [Size: 0x8]
#define DEC_DWORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xFF, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // dec dword ptr [rsp + dword_offset] [Size: 0x7]
#define DEC_WORD_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0xFF, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // dec word ptr [rsp + dword_offset] [Size: 0x8]
#define DEC_BYTE_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xFE, 0x8C, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [rsp + dword_offset] [Size: 0x7]

#define DEC_QWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0xFF, 0x0D, DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [rip + dword_offset] [Size: 0x7]
#define DEC_DWORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, 0x0D, DWORDPTR(DWORDCAST(dword_offset))) // dec dword ptr [rip + dword_offset] [Size: 0x6]
#define DEC_WORD_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0xFF, 0x0D, DWORDPTR(DWORDCAST(dword_offset))) // dec word ptr [rip + dword_offset] [Size: 0x7]
#define DEC_BYTE_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFE, 0x0D, DWORDPTR(DWORDCAST(dword_offset))) // dec qword ptr [rip + dword_offset] [Size: 0x6]

#pragma endregion

#pragma region CMP_INSTRUCTIONS

#define CMP_PTR_RIP_DWORD_OFFSET_DWORD(dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x81, 0x3D, DWORDPTR(DWORDCAST(dword_offset)), DWORDPTR(DWORDCAST(dword))) // cmp [rip + dword_offset], dword [Size: 0xA]
#define CMP_PTR_RIP_DWORD_OFFSET_WORD(dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x81, 0x3D, DWORDPTR(DWORDCAST(dword_offset)), WORDPTR(WORDCAST(dword))) // cmp [rip + dword_offset], word [Size: 0x9]
#define CMP_PTR_RIP_DWORD_OFFSET_BYTE(dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x80, 0x3D, DWORDPTR(DWORDCAST(dword_offset)), BYTEPTR(BYTECAST(byte))) // cmp [rip + dword_offset], byte [Size: 0x7]

#define CMP_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x81, (BYTEPTR(reg) + 0xF8), DWORDPTR(DWORDCAST(dword))) // cmp reg, dword [Size: 0x7]
#define CMP_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x83, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x4]

#define CMP_DREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x81, (BYTEPTR(reg) + 0xF8), DWORDPTR(DWORDCAST(dword))) // cmp reg, dword [Size: 0x6]
#define CMP_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x83, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x3]

#define CMP_WREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x81, (BYTEPTR(reg) + 0xF8), WORDPTR(WORDCAST(word))) // cmp reg, word [Size: 0x5]
#define CMP_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x83, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x4]

#define CMP_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x80, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x3]

#define CMP_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x81, (BYTEPTR(reg) + 0xF8), DWORDPTR(DWORDCAST(dword))) // cmp reg, dword [Size: 0x7]
#define CMP_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x83, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x4]

#define CMP_DRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x81, (BYTEPTR(reg) + 0xF8), DWORDPTR(DWORDCAST(dword))) // cmp reg, dword [Size: 0x7]
#define CMP_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x83, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x4]

#define CMP_WRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x81, (BYTEPTR(reg) + 0xF8), WORDPTR(WORDCAST(dword))) // cmp reg, word [Size: 0x6]
#define CMP_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x5]

#define CMP_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x80, (BYTEPTR(reg) + 0xF8), BYTEPTR(BYTECAST(byte))) // cmp reg, byte [Size: 0x4]

#define CMP_PTR_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x80, (BYTEPTR(reg) + 0x38), BYTEPTR(BYTECAST(byte))) // cmp [reg], byte [Size: 0x3] [reg: no rsp, rbp]
#define CMP_PTR_QREG_BYTE_OFFSET_BYTE(reg, byte_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x80, (BYTEPTR(reg) + 0x78), BYTEPTR(BYTECAST(byte_offset)), BYTEPTR(BYTECAST(byte))) // cmp [reg + byte_offset], byte [Size: 0x4] [reg: no rsp]
#define CMP_PTR_QREG_DWORD_OFFSET_BYTE(reg, dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x80, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword_offset)), BYTEPTR(BYTECAST(byte))) // cmp [reg + dword_offset], byte [Size: 0x7] [reg: no rsp]

#define CMP_PTR_QREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x83, (BYTEPTR(reg) + 0x38), WORDPTR(WORDCAST(word))) // cmp [reg], word [Size: 0x5] [reg: no rsp, rbp]
#define CMP_PTR_QREG_BYTE_OFFSET_WORD(reg, byte_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x83, (BYTEPTR(reg) + 0x78), BYTEPTR(BYTECAST(byte_offset)), WORDPTR(WORDCAST(word))) // cmp [reg + byte_offset], word [Size: 0x6] [reg: no rsp]
#define CMP_PTR_QREG_DWORD_OFFSET_WORD(reg, dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x83, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword_offset)), WORDPTR(WORDCAST(word))) // cmp [reg + dword_offset], word [Size: 0x9] [reg: no rsp]

#define CMP_PTR_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x81, (BYTEPTR(reg) + 0x38), DWORDPTR(DWORDCAST(dword))) // cmp [reg], dword [Size: 0x6] [reg: no rsp, rbp]
#define CMP_PTR_QREG_BYTE_OFFSET_DWORD(reg, byte_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x81, (BYTEPTR(reg) + 0x78), BYTEPTR(BYTECAST(byte_offset)), DWORDPTR(DWORDCAST(dword))) // cmp [reg + byte_offset], dword [Size: 0x7] [reg: no rsp]
#define CMP_PTR_QREG_DWORD_OFFSET_DWORD(reg, dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x81, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword_offset)), DWORDPTR(DWORDCAST(dword))) // cmp [reg + dword_offset], dword [Size: 0xA] [reg: no rsp]

#define CMP_PTR_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x80, (BYTEPTR(reg) + 0x38), BYTEPTR(BYTECAST(byte))) // cmp [reg], byte [Size: 0x4]
#define CMP_PTR_QRREG_BYTE_OFFSET_BYTE(reg, byte_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x80, (BYTEPTR(reg) + 0x78), BYTEPTR(BYTECAST(byte_offset)), BYTEPTR(BYTECAST(byte))) // cmp [reg + byte_offset], byte [Size: 0x5]
#define CMP_PTR_QRREG_DWORD_OFFSET_BYTE(reg, dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x80, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword_offset)), BYTEPTR(BYTECAST(byte))) // cmp [reg + dword_offset], byte [Size: 0x8]

#define CMP_PTR_QRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0x38), WORDPTR(WORDCAST(dword))) // cmp [reg], word [Size: 0x6]
#define CMP_PTR_QRREG_BYTE_OFFSET_WORD(reg, byte_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0x78), BYTEPTR(BYTECAST(byte_offset)), WORDPTR(WORDCAST(dword))) // cmp [reg + byte_offset], word [Size: 0x7]
#define CMP_PTR_QRREG_DWORD_OFFSET_WORD(reg, dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x66, 0x41, 0x83, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword_offset)), WORDPTR(WORDCAST(dword))) // cmp [reg + dword_offset], word [Size: 0xA]

#define CMP_PTR_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x81, (BYTEPTR(reg) + 0x38), DWORDPTR(DWORDCAST(dword))) // cmp [reg], dword [Size: 0x7]
#define CMP_PTR_QRREG_BYTE_OFFSET_DWORD(reg, byte_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x41, 0x81, (BYTEPTR(reg) + 0x78), BYTEPTR(BYTECAST(byte_offset)), DWORDPTR(DWORDCAST(dword))) // cmp [reg + byte_offset], dword [Size: 0x8]
#define CMP_PTR_QRREG_DWORD_OFFSET_DWORD(reg, dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xB, 0x41, 0x81, (BYTEPTR(reg) + 0xB8), DWORDPTR(DWORDCAST(dword_offset)), DWORDPTR(DWORDCAST(dword))) // cmp [reg + dword_offset], dword [Size: 0xB]

#define CMP_PTR_RSP_BYTE(byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x80, 0x3C, 0x24, BYTEPTR(BYTECAST(byte))) // cmp [rsp], byte [Size: 0x4]
#define CMP_PTR_RSP_BYTE_OFFSET_BYTE(byte_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x80, 0x7C, 0x24, BYTEPTR(BYTECAST(byte_offset)), BYTEPTR(BYTECAST(byte))) // cmp [rsp + byte_offset], byte [Size: 0x5]
#define CMP_PTR_RSP_DWORD_OFFSET_BYTE(dword_offset, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x80, 0xBC, 0x24, DWORDPTR(DWORDCAST(dword_offset)), BYTEPTR(BYTECAST(byte))) // cmp [rsp + dword_offset], byte [Size: 0x8]

#define CMP_PTR_RSP_WORD(word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x81, 0x3C, 0x24, WORDPTR(WORDCAST(dword))) // cmp [rsp], word [Size: 0x6]
#define CMP_PTR_RSP_BYTE_OFFSET_WORD(byte_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x81, 0x7C, 0x24, BYTEPTR(BYTECAST(byte_offset)), WORDPTR(WORDCAST(dword))) // cmp [rsp + byte_offset], word [Size: 0x7]
#define CMP_PTR_RSP_DWORD_OFFSET_WORD(dword_offset, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xA, 0x66, 0x81, 0xBC, 0x24, DWORDPTR(DWORDCAST(dword_offset)), WORDPTR(WORDCAST(dword))) // cmp [rsp + dword_offset], word [Size: 0xA]

#define CMP_PTR_RSP_DWORD(dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x81, 0x3C, 0x24, DWORDPTR(DWORDCAST(dword))) // cmp [rsp], dword [Size: 0x7]
#define CMP_PTR_RSP_BYTE_OFFSET_DWORD(byte_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x81, 0x7C, 0x24, BYTEPTR(BYTECAST(byte_offset)), DWORDPTR(DWORDCAST(dword))) // cmp [rsp + byte_offset], dword [Size: 0x8]
#define CMP_PTR_RSP_DWORD_OFFSET_DWORD(dword_offset, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0xB, 0x81, 0xBC, 0x24, DWORDPTR(DWORDCAST(dword_offset)), DWORDPTR(DWORDCAST(dword))) // cmp [rsp + dword_offset], dword [Size: 0xB]

#define CMP_QREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3] [reg1: no rsp, rbp]
#define CMP_QREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define CMP_QREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define CMP_QRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3]
#define CMP_QRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4]
#define CMP_QRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7]

#define CMP_QRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3] [reg1: no rsp, rbp]
#define CMP_QRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define CMP_QRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define CMP_QREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3]
#define CMP_QREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4]
#define CMP_QREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7]

#define CMP_QREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // cmp reg, [rsp] [Size: 0x4]
#define CMP_QREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // cmp reg, [rsp + byte_offset] [Size: 0x5]
#define CMP_QREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // cmp reg, [rsp + dword_offset] [Size: 0x8]

#define CMP_QRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // cmp reg, [rsp] [Size: 0x4]
#define CMP_QRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x4C, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // cmp reg, [rsp + byte_offset] [Size: 0x5]
#define CMP_QRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4C, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // cmp reg, [rsp + dword_offset] [Size: 0x8]

#define CMP_DREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x2] [reg1: no rsp, rbp]
#define CMP_DREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x3] [reg1: no rsp]
#define CMP_DREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x6] [reg1: no rsp]

#define CMP_DRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3]
#define CMP_DRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4]
#define CMP_DRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7]

#define CMP_DRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3] [reg1: no rsp, rbp]
#define CMP_DRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define CMP_DRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define CMP_DREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3]
#define CMP_DREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4]
#define CMP_DREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7]

#define CMP_DREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x04)) // cmp reg, [rsp] [Size: 0x2]
#define CMP_DREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x44), BYTEPTR(BYTECAST(byte_offset))) // cmp reg, [rsp + byte_offset] [Size: 0x3]
#define CMP_DREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x84), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg, [rsp + dword_offset] [Size: 0x6]

#define CMP_DRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x3B, ((BYTEPTR(reg) * 0x8) + BYTEPTR(reg))) // cmp reg, [rsp] [Size: 0x3]
#define CMP_DRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x44), BYTEPTR(BYTECAST(byte_offset))) // cmp reg, [rsp + byte_offset] [Size: 0x4]
#define CMP_DRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x84), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg, [rsp + dword_offset] [Size: 0x7]

#define CMP_WREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3] [reg1: no rsp, rbp]
#define CMP_WREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define CMP_WREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x66, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define CMP_WRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x45, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) // cmp reg0, [reg1] [Size: 0x4]
#define CMP_WRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x45, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset)) // cmp reg0, [reg1 + byte_offset] [Size: 0x5]
#define CMP_WRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x45, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset)) // cmp reg0, [reg1 + dword_offset] [Size: 0x8]

#define CMP_WRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x4] [reg1: no rsp, rbp]
#define CMP_WRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x5] [reg1: no rsp]
#define CMP_WRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x44, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x8] [reg1: no rsp]

#define CMP_WREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x4]
#define CMP_WREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x5]
#define CMP_WREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x41, 0x3B, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x8]

#define CMP_WREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // cmp reg, [rsp] [Size: 0x4]
#define CMP_WREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // cmp reg, [rsp + byte_offset] [Size: 0x5]
#define CMP_WREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x66, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // cmp reg, [rsp + dword_offset] [Size: 0x8]

#define CMP_WRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // cmp reg, [rsp] [Size: 0x5]
#define CMP_WRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x44, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // cmp reg, [rsp + byte_offset] [Size: 0x6]
#define CMP_WRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x9, 0x66, 0x44, 0x3B, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // cmp reg, [rsp + dword_offset] [Size: 0x9]

#define CMP_BREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x2] [reg1: no rsp, rbp]
#define CMP_BREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x3] [reg1: no rsp]
#define CMP_BREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x6] [reg1: no rsp]

#define CMP_BRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3]
#define CMP_BRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4]
#define CMP_BRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x45, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7]

#define CMP_BRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3] [reg1: no rsp, rbp]
#define CMP_BRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define CMP_BRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x44, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define CMP_BREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // cmp reg0, [reg1] [Size: 0x3]
#define CMP_BREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4]
#define CMP_BREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0x3A, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7]

#define CMP_BREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x3A, ((BYTEPTR(reg0) * 0x8) + 0x04), 0x24) // cmp reg0, [reg1] [Size: 0x3]
#define CMP_BREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x3A, ((BYTEPTR(reg0) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x4]
#define CMP_BREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x3A, ((BYTEPTR(reg0) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x7]

#define CMP_BRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x3A, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // cmp reg0, [reg1] [Size: 0x4]
#define CMP_BRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x44, 0x3A, ((BYTEPTR(reg0) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // cmp reg0, [reg1 + byte_offset] [Size: 0x5]
#define CMP_BRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x44, 0x3A, ((BYTEPTR(reg0) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // cmp reg0, [reg1 + dword_offset] [Size: 0x8]

#define CMP_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x2]
#define CMP_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x38, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x2]

#define CMP_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x4]
#define CMP_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x38, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]

#define CMP_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x4]
#define CMP_BRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x38, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]

#define CMP_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]
#define CMP_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x39, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x4]
#define CMP_BREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x38, ((BYTEPTR(reg0) + (BYTEPTR(reg1) * 0x8)) + 0xC0)) // cmp reg0, reg1 [Size: 0x3]

#pragma endregion

#pragma region SET_INSTRUCTIONS

#define SETO_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x90, (BYTEPTR(reg) + 0xC0)) // seto reg [Size: 0x3]
#define SETO_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x90, (BYTEPTR(reg) + 0xC0)) // seto reg [Size: 0x4]

#define SETNO_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x91, (BYTEPTR(reg) + 0xC0)) // setno reg [Size: 0x3]
#define SETNO_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x91, (BYTEPTR(reg) + 0xC0)) // setno reg [Size: 0x4]

#define SETB_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x92, (BYTEPTR(reg) + 0xC0)) // setb reg [Size: 0x3]
#define SETB_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x92, (BYTEPTR(reg) + 0xC0)) // setb reg [Size: 0x4]

#define SETAE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x93, (BYTEPTR(reg) + 0xC0)) // setae reg [Size: 0x3]
#define SETAE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x93, (BYTEPTR(reg) + 0xC0)) // setae reg [Size: 0x4]

#define SETE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x94, (BYTEPTR(reg) + 0xC0)) // sete reg [Size: 0x3]
#define SETE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x94, (BYTEPTR(reg) + 0xC0)) // sete reg [Size: 0x4]

#define SETNE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x95, (BYTEPTR(reg) + 0xC0)) // setne reg [Size: 0x3]
#define SETNE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x95, (BYTEPTR(reg) + 0xC0)) // setne reg [Size: 0x4]

#define SETBE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x96, (BYTEPTR(reg) + 0xC0)) // setbe reg [Size: 0x3]
#define SETBE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x96, (BYTEPTR(reg) + 0xC0)) // setbe reg [Size: 0x4]

#define SETA_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x97, (BYTEPTR(reg) + 0xC0)) // seta reg [Size: 0x3]
#define SETA_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x97, (BYTEPTR(reg) + 0xC0)) // seta reg [Size: 0x4]

#define SETS_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x98, (BYTEPTR(reg) + 0xC0)) // sets reg [Size: 0x3]
#define SETS_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x98, (BYTEPTR(reg) + 0xC0)) // sets reg [Size: 0x4]

#define SETNS_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x99, (BYTEPTR(reg) + 0xC0)) // setns reg [Size: 0x3]
#define SETNS_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x99, (BYTEPTR(reg) + 0xC0)) // setns reg [Size: 0x4]

#define SETP_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9A, (BYTEPTR(reg) + 0xC0)) // setp reg [Size: 0x3]
#define SETP_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x9A, (BYTEPTR(reg) + 0xC0)) // setp reg [Size: 0x4]

#define SETNP_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9B, (BYTEPTR(reg) + 0xC0)) // setnp reg [Size: 0x3]
#define SETNP_BRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x9B, (BYTEPTR(reg) + 0xC0)) // setnp reg [Size: 0x4]

#define SETL_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9C, (BYTEPTR(reg) + 0xC0)) // setl reg [Size: 0x3]
#define SETL_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x9C, (BYTEPTR(reg) + 0xC0)) // setl reg [Size: 0x4]

#define SETGE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9D, (BYTEPTR(reg) + 0xC0)) // setge reg [Size: 0x3]
#define SETGE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x9D, (BYTEPTR(reg) + 0xC0)) // setge reg [Size: 0x4]

#define SETLE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9E, (BYTEPTR(reg) + 0xC0)) // setle reg [Size: 0x3]
#define SETLE_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x9E, (BYTEPTR(reg) + 0xC0)) // setle reg [Size: 0x4]

#define SETG_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9F, (BYTEPTR(reg) + 0xC0)) // setg reg [Size: 0x3]
#define SETG_BREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0x9F, (BYTEPTR(reg) + 0xC0)) // setg reg [Size: 0x4]

#define SETO_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x90, BYTEPTR(reg)) // seto [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETO_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x90, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(dword_offset))) // seto [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETO_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x90, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // seto [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETNO_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x91, BYTEPTR(reg)) // setno [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETNO_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x91, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(dword_offset))) // setno [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETNO_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x91, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setno [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETB_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x92, BYTEPTR(reg)) // setb [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETB_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x92, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(dword_offset))) // setb [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETB_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x92, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setb [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETAE_PTR_QREG(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x93, BYTEPTR(reg)) // setae [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETAE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x93, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(dword_offset))) // setae [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETAE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x93, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setae [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x94, BYTEPTR(reg)) // sete [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x94, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(dword_offset))) // sete [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x94, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // sete [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETNE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x95, BYTEPTR(reg)) // setne [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETNE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x95, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setne [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETNE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x95, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setne [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETBE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x96, BYTEPTR(reg)) // setbe [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETBE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x96, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setbe [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETBE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x96, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setbe [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETA_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x97, BYTEPTR(reg)) // seta [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETA_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x97, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // seta [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETA_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x97, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // seta [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETS_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x98, BYTEPTR(reg)) // sets [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETS_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x98, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // sets [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETS_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x98, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // sets [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETNS_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x99, BYTEPTR(reg)) // setns [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETNS_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x99, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setns [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETNS_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x99, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setns [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETP_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9A, BYTEPTR(reg)) // setp [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETP_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x9A, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setp [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETP_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x9A, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setp [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETNP_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9B, BYTEPTR(reg)) // setnp [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETNP_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x9B, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setnp [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETNP_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x9B, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setnp [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETL_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9C, BYTEPTR(reg)) // setl [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETL_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x9C, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setl [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETL_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x9C, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setl [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETGE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9D, BYTEPTR(reg)) // setge [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETGE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x9D, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setge [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETGE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x9D, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setge [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETLE_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9E, BYTEPTR(reg)) // setle [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETLE_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x9E, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setle [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETLE_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x9E, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setle [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#define SETG_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0x9F, BYTEPTR(reg)) // setg [reg] [Size: 0x3] [reg: no rsp, rbp]
#define SETG_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0x9F, (BYTEPTR(reg) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // setg [reg + byte_offset] [Size: 0x4] [reg: no rsp]
#define SETG_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x0F, 0x9F, (BYTEPTR(reg) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // setg [reg + dword_offset] [Size: 0x7] [reg: no rsp]

#pragma endregion

#pragma region REP_INSTRUCTIONS

#define REP_MOVS_BYTE_PTR(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF3, 0xA4) // rep movs BYTE PTR [rdi], [rsi] ecx - Times [Size: 0x2]
#define REP_MOVS_DWORD_PTR(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF3, 0xA5) // rep movs DWORD PTR [rdi], [rsi] ecx - Times [Size: 0x2]

#define REP_STOS_BYTE_PTR(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF3, 0xAA) // rep stos BYTE PTR [rdi], al ecx - Times [Size: 0x2]
#define REP_STOS_DWORD_PTR(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF3, 0xAB) // rep stos DWORD PTR [rdi], eax ecx - Times [Size: 0x2]

#pragma endregion

#pragma region FLAG_INSTRUCTIONS

#define CLI(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xFA) // cli [Size: 0x1]
#define STI(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xFB) // sti [Size: 0x1]

#define CMC(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xF5) // cmc [Size: 0x1]
#define CLC(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xF8) // clc [Size: 0x1]
#define STC(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xF9) // stc [Size: 0x1]

#define CLD(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xFC) // cld [Size: 0x1]
#define STD(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xFD) // std [Size: 0x1]

#pragma endregion

#pragma region TEST_INSTRUCTIONS

#define TEST_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x2]
#define TEST_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x66, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_BREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x84, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x2]
#define TEST_BHREG_BHREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x84, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xE4)) // test reg0, reg1 [Size: 0x2]

#define TEST_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x45, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x4]
#define TEST_BRREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x45, 0x84, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]

#define TEST_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x41, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x4]
#define TEST_BRREG_BREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0x84, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]

#define TEST_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]
#define TEST_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x44, 0x85, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x4]
#define TEST_BREG_BRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x44, 0x84, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // test reg0, reg1 [Size: 0x3]

#define TEST_QREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0xF7, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // test reg, dword [Size: 0x7]
#define TEST_DREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xF7, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // test reg, dword [Size: 0x6]
#define TEST_WREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0xF7, (BYTEPTR(reg) + 0xC0), WORDPTR(WORDCAST(word))) // test reg, word [Size: 0x5]
#define TEST_BREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xF6, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // test reg, byte [Size: 0x3]

#define TEST_QRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0xF7, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // test reg, dword [Size: 0x7]
#define TEST_DRREG_DWORD(reg, dword, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xF7, (BYTEPTR(reg) + 0xC0), DWORDPTR(DWORDCAST(dword))) // test reg, dword [Size: 0x7]
#define TEST_WRREG_WORD(reg, word, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0xF7, (BYTEPTR(reg) + 0xC0), WORDPTR(WORDCAST(word))) // test reg, word [Size: 0x6]
#define TEST_BRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xF6, (BYTEPTR(reg) + 0xC0), BYTEPTR(BYTECAST(byte))) // test reg, byte [Size: 0x4]

#define BT_QREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0x0F, 0xBA, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // bt reg, byte [Size: 0x5]
#define BT_DREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x0F, 0xBA, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // bt reg, byte [Size: 0x4]
#define BT_WREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x0F, 0xBA, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // bt reg, byte [Size: 0x5]

#define BT_QRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x49, 0x0F, 0xBA, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // bt reg, byte [Size: 0x5]
#define BT_DRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x41, 0x0F, 0xBA, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // bt reg, byte [Size: 0x5]
#define BT_WRREG_BYTE(reg, byte, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x66, 0x41, 0x0F, 0xBA, (BYTEPTR(reg) + 0xE0), BYTEPTR(BYTECAST(byte))) // bt reg, byte [Size: 0x6]

#define BT_QREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]
#define BT_DREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x3]
#define BT_WREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x66, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]

#define BT_QRREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]
#define BT_DRREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x45, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]
#define BT_WRREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x45, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x5]

#define BT_QREG_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]
#define BT_DREG_DRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x44, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]
#define BT_WREG_WRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x44, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x5]

#define BT_QRREG_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]
#define BT_DRREG_DREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x4]
#define BT_WRREG_WREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x66, 0x41, 0x0F, 0xA3, (((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0)) + 0xC0)) // bt reg0, reg1 [Size: 0x5]

#pragma endregion

#pragma region CALL_INSTRUCTIONS

#define CALL_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0xD0)) // call reg [Size: 0x2]
#define CALL_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0xD0)) // call reg [Size: 0x3]

#define CALL_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0x10)) // call [reg] [Size: 0x2] [reg: no rsp, rbp]
#define CALL_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, (BYTEPTR(reg) + 0x50), BYTEPTR(BYTECAST(byte_offset))) // call [reg + byte_offset] [Size: 0x3] [reg: no rsp]
#define CALL_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, (BYTEPTR(reg) + 0x90), DWORDPTR(DWORDCAST(dword_offset))) // call [reg + dword_offset] [Size: 0x6] [reg: no rsp]

#define CALL_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0x10)) // call [reg] [Size: 0x3]
#define CALL_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xFF, (BYTEPTR(reg) + 0x50), BYTEPTR(BYTECAST(byte_offset))) // call [reg + byte_offset] [Size: 0x4]
#define CALL_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x41, 0xFF, (BYTEPTR(reg) + 0x90), DWORDPTR(DWORDCAST(dword_offset))) // call [reg + dword_offset] [Size: 0x6]

#define CALL_PTR_RSP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, 0x14, 0x24)  // call [reg] [Size: 0x3]
#define CALL_PTR_RSP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xFF, 0x54, 0x24, BYTEPTR(BYTECAST(byte_offset))) // call [rsp + byte_offset] [Size: 0x4]
#define CALL_PTR_RSP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xFF, 0x94, 0x24, DWORDPTR(DWORDCAST(dword_offset))) // call [rsp + dword_offset] [Size: 0x7]

#define SYSCALL(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x0F, 0x05) // syscall [Size: 0x2]

#define CALL_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xE8, DWORDPTR(DWORDCAST(dword_offset))) // call rip + dword_offset [Size: 0x5]
#define CALL_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, 0x15, DWORDPTR(DWORDCAST(dword_offset))) // call [rip + dword_offset] [Size: 0x6]

#pragma endregion

#pragma region JMP_INSTRUCTIONS

#define JMP_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0xE0)) // jmp reg [Size: 0x2]
#define JMP_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0xE0)) // jmp reg [Size: 0x3]

#define JMP_PTR_QREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xFF, (BYTEPTR(reg) + 0x20)) // jmp [reg] [Size: 0x2] [reg: no rsp, rbp]
#define JMP_PTR_QREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, (BYTEPTR(reg) + 0x60), BYTEPTR(BYTECAST(byte_offset))) // jmp [reg + byte_offset] [Size: 0x3] [reg: no rsp]
#define JMP_PTR_QREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, (BYTEPTR(reg) + 0xA0), DWORDPTR(DWORDCAST(byte_offset))) // jmp [reg + dword_offset] [Size: 0x6] [reg: no rsp]

#define JMP_PTR_QRREG(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x41, 0xFF, (BYTEPTR(reg) + 0x20)) // jmp [reg] [Size: 0x3]
#define JMP_PTR_QRREG_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x41, 0xFF, (BYTEPTR(reg) + 0x60), BYTEPTR(BYTECAST(byte_offset))) // jmp [reg + byte_offset] [Size: 0x4]
#define JMP_PTR_QRREG_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x41, 0xFF, (BYTEPTR(reg) + 0xA0), DWORDPTR(DWORDCAST(byte_offset))) // jmp [reg + dword_offset] [Size: 0x7]

#define JMP_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0xFF, (BYTEPTR(reg) + 0x20), 0x24) // jmp [rsp] [Size: 0x3]
#define JMP_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0xFF, (BYTEPTR(reg) + 0x60), 0x24, BYTEPTR(BYTECAST(byte_offset))) // jmp [rsp + byte_offset] [Size: 0x4]
#define JMP_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0xFF, (BYTEPTR(reg) + 0xA0), 0x24, DWORDPTR(DWORDCAST(byte_offset))) // jmp [rsp + dword_offset] [Size: 0x7]

#define JO_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x70, BYTEPTR(BYTECAST(byte_offset))) // jo rip + byte_offset [Size: 0x2]
#define JO_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x80, DWORDPTR(DWORDCAST(dword_offset))) // jo rip + dword_offset [Size: 0x6]

#define JNO_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x71, BYTEPTR(BYTECAST(byte_offset))) // jno rip + byte_offset [Size: 0x2]
#define JNO_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x81, DWORDPTR(DWORDCAST(dword_offset))) // jno rip + dword_offset [Size: 0x6]

#define JB_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x72, BYTEPTR(BYTECAST(byte_offset))) // jb rip + byte_offset [Size: 0x2]
#define JB_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x82, DWORDPTR(DWORDCAST(dword_offset))) // jb rip + dword_offset [Size: 0x6]

#define JAE_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x73, BYTEPTR(BYTECAST(byte_offset))) // jae rip + byte_offset [Size: 0x2]
#define JAE_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x83, DWORDPTR(DWORDCAST(dword_offset))) // jae rip + dword_offset [Size: 0x6]

#define JE_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x74, BYTEPTR(BYTECAST(byte_offset))) // je rip + byte_offset [Size: 0x2]
#define JE_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x84, DWORDPTR(DWORDCAST(dword_offset))) // je rip + dword_offset [Size: 0x6]

#define JNE_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x75, BYTEPTR(BYTECAST(byte_offset))) // jne rip + byte_offset [Size: 0x2]
#define JNE_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x85, DWORDPTR(DWORDCAST(dword_offset))) // jne rip + dword_offset [Size: 0x6]

#define JBE_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x76, BYTEPTR(BYTECAST(byte_offset))) // jbe rip + byte_offset [Size: 0x2]
#define JBE_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x86, DWORDPTR(DWORDCAST(dword_offset))) // jbe rip + dword_offset [Size: 0x6]

#define JA_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x77, BYTEPTR(BYTECAST(byte_offset))) // jbe rip + byte_offset [Size: 0x2]
#define JA_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x87, DWORDPTR(DWORDCAST(dword_offset))) // ja rip + dword_offset [Size: 0x6]

#define JS_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x78, BYTEPTR(BYTECAST(byte_offset))) // js rip + byte_offset [Size: 0x2]
#define JS_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x88, DWORDPTR(DWORDCAST(dword_offset))) // js rip + dword_offset [Size: 0x6]

#define JNS_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x79, BYTEPTR(BYTECAST(byte_offset))) // jns rip + byte_offset [Size: 0x2]
#define JNS_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x89, DWORDPTR(DWORDCAST(dword_offset))) // jns rip + dword_offset [Size: 0x6]

#define JP_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x7A, BYTEPTR(BYTECAST(byte_offset))) // jp rip + byte_offset [Size: 0x2]
#define JP_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x8A, DWORDPTR(DWORDCAST(dword_offset))) // jp rip + dword_offset [Size: 0x6]

#define JNP_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x7B, BYTEPTR(BYTECAST(byte_offset))) // jnp rip + byte_offset [Size: 0x2]
#define JNP_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x8B, DWORDPTR(DWORDCAST(dword_offset))) // jnp rip + dword_offset [Size: 0x6]

#define JL_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x7C, BYTEPTR(BYTECAST(byte_offset))) // jc rip + byte_offset [Size: 0x2]
#define JL_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x8C, DWORDPTR(DWORDCAST(dword_offset))) // jl rip + dword_offset [Size: 0x6]

#define JGE_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x7D, BYTEPTR(BYTECAST(byte_offset))) // jge rip + byte_offset [Size: 0x2]
#define JGE_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x8D, DWORDPTR(DWORDCAST(dword_offset))) // jge rip + dword_offset [Size: 0x6]

#define JLE_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x7E, BYTEPTR(BYTECAST(byte_offset))) // jle rip + byte_offset [Size: 0x2]
#define JLE_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x8E, DWORDPTR(DWORDCAST(dword_offset))) // jle rip + dword_offset [Size: 0x6]

#define JG_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0x7F, BYTEPTR(BYTECAST(byte_offset))) // jg rip + byte_offset [Size: 0x2]
#define JG_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0x0F, 0x8F, DWORDPTR(DWORDCAST(dword_offset))) // jg rip + dword_offset [Size: 0x6]

#define JMP_RIP_BYTE_OFFSET(byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xEB, BYTEPTR(BYTECAST(byte_offset))) // jmp rip + byte_offset [Size: 0x2]
#define JMP_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0xE9, DWORDPTR(DWORDCAST(dword_offset))) // jmp rip + dword_offset [Size: 0x5]

#define JMP_PTR_RIP_DWORD_OFFSET(dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x6, 0xFF, 0x25, DWORDPTR(DWORDCAST(dword_offset))) // jmp [rip + dword_offset] [Size: 0x6]

#pragma endregion

#pragma region LEA_INSTRUCTIONS

#define LEA_QREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // lea reg, [rip + dword_offset] [Size: 0x7]
#define LEA_QRREG_PTR_RIP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x5), DWORDPTR(DWORDCAST(dword_offset))) // lea reg, [rip + dword_offset] [Size: 0x7]

#define LEA_QREG_PTR_QREG_TIMES_8_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0x8D, 0x04, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0xC4), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 * 0x8 + dword_offset] [Size: 0x8] [reg1: no rsp]
#define LEA_QRREG_PTR_QRREG_TIMES_8_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4E, 0x8D, 0x04, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0xC5), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 * 0x8 + dword_offset] [Size: 0x8] [reg1: no rsp]
#define LEA_QRREG_PTR_QREG_TIMES_8_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4C, 0x8D, 0x04, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0xC5), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 * 0x8 + dword_offset] [Size: 0x8] [reg1: no rsp]
#define LEA_QREG_PTR_QRREG_TIMES_8_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4A, 0x8D, 0x04, ((BYTEPTR(reg1) * 0x8) + BYTEPTR(reg0) + 0xC5), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 * 0x8 + dword_offset] [Size: 0x8] [reg1: no rsp]

#define LEA_QREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x48, 0x8D, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // lea reg0, [reg1] [Size: 0x3] [reg1: no rsp, rbp]
#define LEA_QREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lea reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define LEA_QREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x48, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define LEA_QRREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4D, 0x8D, (((reg0) * 0x8) + (reg1))) // lea reg0, [reg1] [Size: 0x3]
#define LEA_QRREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4D, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lea reg0, [reg1 + byte_offset] [Size: 0x4]
#define LEA_QRREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4D, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 + dword_offset] [Size: 0x7]

#define LEA_QRREG_PTR_QREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x4C, 0x8D, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // lea reg0, [reg1] [Size: 0x3] [reg1: no rsp, rbp]
#define LEA_QRREG_PTR_QREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lea reg0, [reg1 + byte_offset] [Size: 0x4] [reg1: no rsp]
#define LEA_QRREG_PTR_QREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x4C, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 + dword_offset] [Size: 0x7] [reg1: no rsp]

#define LEA_QREG_PTR_QRREG(reg0, reg1, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x3, 0x49, 0x8D, ((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1))) // lea reg0, [reg1] [Size: 0x3]
#define LEA_QREG_PTR_QRREG_BYTE_OFFSET(reg0, reg1, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x49, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x40), BYTEPTR(BYTECAST(byte_offset))) // lea reg0, [reg1 + byte_offset] [Size: 0x4]
#define LEA_QREG_PTR_QRREG_DWORD_OFFSET(reg0, reg1, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x7, 0x49, 0x8D, (((BYTEPTR(reg0) * 0x8) + BYTEPTR(reg1)) + 0x80), DWORDPTR(DWORDCAST(dword_offset))) // lea reg0, [reg1 + dword_offset] [Size: 0x7]

#define LEA_QREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x48, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x4), 0x24) // lea reg, [rsp] [Size: 0x4]
#define LEA_QREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x48, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // lea reg, [rsp + byte_offset] [Size: 0x5]
#define LEA_QREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x48, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lea reg, [rsp + dword_offset] [Size: 0x8]

#define LEA_QRREG_PTR_RSP(reg, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x4, 0x4C, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x04), 0x24) // lea reg, [rsp] [Size: 0x4]
#define LEA_QRREG_PTR_RSP_BYTE_OFFSET(reg, byte_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x5, 0x4C, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x44), 0x24, BYTEPTR(BYTECAST(byte_offset))) // lea reg, [rsp + byte_offset] [Size: 0x5]
#define LEA_QRREG_PTR_RSP_DWORD_OFFSET(reg, dword_offset, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x8, 0x4C, 0x8D, ((BYTEPTR(reg) * 0x8) + 0x84), 0x24, DWORDPTR(DWORDCAST(dword_offset))) // lea reg, [rsp + dword_offset] [Size: 0x8]

#pragma endregion

#pragma region PAUSE_INSTRUCTIONS

#define PAUSE(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xF3, 0x90) // pause [Size: 0x2]

#pragma endregion

#pragma region NOP_INSTRUCTIONS

#define NOP(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0x90) // nop [Size: 0x1]

#pragma endregion

#pragma region INT_INSTRUCTIONS

#define INT3(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xCC) // int 3 [Size: 0x1]
#define INTX(x, relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x2, 0xCD, BYTEPTR(BYTECAST(x))) // int x [Size: 0x2]

#pragma endregion

#pragma region RET_INSTRUCTIONS

#define RET(relativity) INSERT_INLINECODE_8_BIT_ARRAY((relativity) += 0x1, 0xC3) // ret [Size: 0x1]

#pragma endregion

#endif
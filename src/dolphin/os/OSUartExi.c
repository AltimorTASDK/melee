#include <dolphin/types.h>

static u32 Enabled[2];

extern s32 OSGetConsoleType();

s32 InitializeUART(void)
{
    if (!(OSGetConsoleType() & 0x10000000)) {
        Enabled[0] = 0;
        return 2;
    }
    Enabled[0] = 0xA5FF005A;
    return 0;
}

s32 ReadUARTN(void)
{
    return 4;
}

extern unk_t EXIUnlock();
extern unk_t EXIDeselect();
extern unk_t EXISync();
extern unk_t EXIImm();
extern unk_t EXILock();
extern unk_t EXISelect();

#pragma push
asm unk_t WriteUARTN()
{ // clang-format off
    nofralloc
/* 8034C8BC 0034949C  7C 08 02 A6 */	mflr r0
/* 8034C8C0 003494A0  90 01 00 04 */	stw r0, 4(r1)
/* 8034C8C4 003494A4  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8034C8C8 003494A8  BF 41 00 18 */	stmw r26, 0x18(r1)
/* 8034C8CC 003494AC  3B C3 00 00 */	addi r30, r3, 0
/* 8034C8D0 003494B0  3B E4 00 00 */	addi r31, r4, 0
/* 8034C8D4 003494B4  80 AD BD 48 */	lwz r5, Enabled(r13)
/* 8034C8D8 003494B8  3C 05 5A 01 */	addis r0, r5, 0x5a01
/* 8034C8DC 003494BC  28 00 00 5A */	cmplwi r0, 0x5a
/* 8034C8E0 003494C0  41 82 00 0C */	beq lbl_8034C8EC
/* 8034C8E4 003494C4  38 60 00 02 */	li r3, 2
/* 8034C8E8 003494C8  48 00 01 C0 */	b lbl_8034CAA8
lbl_8034C8EC:
/* 8034C8EC 003494CC  38 60 00 00 */	li r3, 0
/* 8034C8F0 003494D0  38 80 00 01 */	li r4, 1
/* 8034C8F4 003494D4  38 A0 00 00 */	li r5, 0
/* 8034C8F8 003494D8  4B FF A4 89 */	bl EXILock
/* 8034C8FC 003494DC  2C 03 00 00 */	cmpwi r3, 0
/* 8034C900 003494E0  40 82 00 0C */	bne lbl_8034C90C
/* 8034C904 003494E4  38 60 00 00 */	li r3, 0
/* 8034C908 003494E8  48 00 01 A0 */	b lbl_8034CAA8
lbl_8034C90C:
/* 8034C90C 003494EC  38 9E 00 00 */	addi r4, r30, 0
/* 8034C910 003494F0  38 60 00 0D */	li r3, 0xd
/* 8034C914 003494F4  48 00 00 18 */	b lbl_8034C92C
lbl_8034C918:
/* 8034C918 003494F8  88 04 00 00 */	lbz r0, 0(r4)
/* 8034C91C 003494FC  2C 00 00 0A */	cmpwi r0, 0xa
/* 8034C920 00349500  40 82 00 08 */	bne lbl_8034C928
/* 8034C924 00349504  98 64 00 00 */	stb r3, 0(r4)
lbl_8034C928:
/* 8034C928 00349508  38 84 00 01 */	addi r4, r4, 1
lbl_8034C92C:
/* 8034C92C 0034950C  7C 1E 20 50 */	subf r0, r30, r4
/* 8034C930 00349510  7C 00 F8 40 */	cmplw r0, r31
/* 8034C934 00349514  41 80 FF E4 */	blt lbl_8034C918
/* 8034C938 00349518  3C 00 A0 01 */	lis r0, 0xa001
/* 8034C93C 0034951C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8034C940 00349520  3B 40 00 00 */	li r26, 0
/* 8034C944 00349524  3F A0 20 01 */	lis r29, 0x2001
/* 8034C948 00349528  48 00 01 4C */	b lbl_8034CA94
lbl_8034C94C:
/* 8034C94C 0034952C  38 60 00 00 */	li r3, 0
/* 8034C950 00349530  38 80 00 01 */	li r4, 1
/* 8034C954 00349534  38 A0 00 03 */	li r5, 3
/* 8034C958 00349538  4B FF 9D 31 */	bl EXISelect
/* 8034C95C 0034953C  2C 03 00 00 */	cmpwi r3, 0
/* 8034C960 00349540  40 82 00 0C */	bne lbl_8034C96C
/* 8034C964 00349544  38 00 FF FF */	li r0, -1
/* 8034C968 00349548  48 00 00 5C */	b lbl_8034C9C4
lbl_8034C96C:
/* 8034C96C 0034954C  93 A1 00 10 */	stw r29, 0x10(r1)
/* 8034C970 00349550  38 81 00 10 */	addi r4, r1, 0x10
/* 8034C974 00349554  38 60 00 00 */	li r3, 0
/* 8034C978 00349558  38 A0 00 04 */	li r5, 4
/* 8034C97C 0034955C  38 C0 00 01 */	li r6, 1
/* 8034C980 00349560  38 E0 00 00 */	li r7, 0
/* 8034C984 00349564  4B FF 91 E1 */	bl EXIImm
/* 8034C988 00349568  38 60 00 00 */	li r3, 0
/* 8034C98C 0034956C  4B FF 95 C1 */	bl EXISync
/* 8034C990 00349570  38 81 00 10 */	addi r4, r1, 0x10
/* 8034C994 00349574  38 60 00 00 */	li r3, 0
/* 8034C998 00349578  38 A0 00 01 */	li r5, 1
/* 8034C99C 0034957C  38 C0 00 00 */	li r6, 0
/* 8034C9A0 00349580  38 E0 00 00 */	li r7, 0
/* 8034C9A4 00349584  4B FF 91 C1 */	bl EXIImm
/* 8034C9A8 00349588  38 60 00 00 */	li r3, 0
/* 8034C9AC 0034958C  4B FF 95 A1 */	bl EXISync
/* 8034C9B0 00349590  38 60 00 00 */	li r3, 0
/* 8034C9B4 00349594  4B FF 9E 01 */	bl EXIDeselect
/* 8034C9B8 00349598  80 01 00 10 */	lwz r0, 0x10(r1)
/* 8034C9BC 0034959C  54 00 46 3E */	srwi r0, r0, 0x18
/* 8034C9C0 003495A0  20 00 00 10 */	subfic r0, r0, 0x10
lbl_8034C9C4:
/* 8034C9C4 003495A4  2C 00 00 00 */	cmpwi r0, 0
/* 8034C9C8 003495A8  7C 1B 03 78 */	mr r27, r0
/* 8034C9CC 003495AC  40 80 00 0C */	bge lbl_8034C9D8
/* 8034C9D0 003495B0  3B 40 FF FF */	li r26, -1
/* 8034C9D4 003495B4  48 00 00 C8 */	b lbl_8034CA9C
lbl_8034C9D8:
/* 8034C9D8 003495B8  2C 00 00 0C */	cmpwi r0, 0xc
/* 8034C9DC 003495BC  40 80 00 0C */	bge lbl_8034C9E8
/* 8034C9E0 003495C0  7C 00 F8 40 */	cmplw r0, r31
/* 8034C9E4 003495C4  41 80 00 B0 */	blt lbl_8034CA94
lbl_8034C9E8:
/* 8034C9E8 003495C8  38 60 00 00 */	li r3, 0
/* 8034C9EC 003495CC  38 80 00 01 */	li r4, 1
/* 8034C9F0 003495D0  38 A0 00 03 */	li r5, 3
/* 8034C9F4 003495D4  4B FF 9C 95 */	bl EXISelect
/* 8034C9F8 003495D8  2C 03 00 00 */	cmpwi r3, 0
/* 8034C9FC 003495DC  40 82 00 0C */	bne lbl_8034CA08
/* 8034CA00 003495E0  3B 40 FF FF */	li r26, -1
/* 8034CA04 003495E4  48 00 00 98 */	b lbl_8034CA9C
lbl_8034CA08:
/* 8034CA08 003495E8  38 81 00 14 */	addi r4, r1, 0x14
/* 8034CA0C 003495EC  38 60 00 00 */	li r3, 0
/* 8034CA10 003495F0  38 A0 00 04 */	li r5, 4
/* 8034CA14 003495F4  38 C0 00 01 */	li r6, 1
/* 8034CA18 003495F8  38 E0 00 00 */	li r7, 0
/* 8034CA1C 003495FC  4B FF 91 49 */	bl EXIImm
/* 8034CA20 00349600  38 60 00 00 */	li r3, 0
/* 8034CA24 00349604  4B FF 95 29 */	bl EXISync
/* 8034CA28 00349608  48 00 00 54 */	b lbl_8034CA7C
lbl_8034CA2C:
/* 8034CA2C 0034960C  2C 1B 00 04 */	cmpwi r27, 4
/* 8034CA30 00349610  40 80 00 0C */	bge lbl_8034CA3C
/* 8034CA34 00349614  7C 1B F8 40 */	cmplw r27, r31
/* 8034CA38 00349618  41 80 00 54 */	blt lbl_8034CA8C
lbl_8034CA3C:
/* 8034CA3C 0034961C  28 1F 00 04 */	cmplwi r31, 4
/* 8034CA40 00349620  40 80 00 0C */	bge lbl_8034CA4C
/* 8034CA44 00349624  7F FC FB 78 */	mr r28, r31
/* 8034CA48 00349628  48 00 00 08 */	b lbl_8034CA50
lbl_8034CA4C:
/* 8034CA4C 0034962C  3B 80 00 04 */	li r28, 4
lbl_8034CA50:
/* 8034CA50 00349630  38 BC 00 00 */	addi r5, r28, 0
/* 8034CA54 00349634  38 9E 00 00 */	addi r4, r30, 0
/* 8034CA58 00349638  38 60 00 00 */	li r3, 0
/* 8034CA5C 0034963C  38 C0 00 01 */	li r6, 1
/* 8034CA60 00349640  38 E0 00 00 */	li r7, 0
/* 8034CA64 00349644  4B FF 91 01 */	bl EXIImm
/* 8034CA68 00349648  7F DE E2 14 */	add r30, r30, r28
/* 8034CA6C 0034964C  7F FC F8 50 */	subf r31, r28, r31
/* 8034CA70 00349650  7F 7C D8 50 */	subf r27, r28, r27
/* 8034CA74 00349654  38 60 00 00 */	li r3, 0
/* 8034CA78 00349658  4B FF 94 D5 */	bl EXISync
lbl_8034CA7C:
/* 8034CA7C 0034965C  2C 1B 00 00 */	cmpwi r27, 0
/* 8034CA80 00349660  41 82 00 0C */	beq lbl_8034CA8C
/* 8034CA84 00349664  28 1F 00 00 */	cmplwi r31, 0
/* 8034CA88 00349668  40 82 FF A4 */	bne lbl_8034CA2C
lbl_8034CA8C:
/* 8034CA8C 0034966C  38 60 00 00 */	li r3, 0
/* 8034CA90 00349670  4B FF 9D 25 */	bl EXIDeselect
lbl_8034CA94:
/* 8034CA94 00349674  28 1F 00 00 */	cmplwi r31, 0
/* 8034CA98 00349678  40 82 FE B4 */	bne lbl_8034C94C
lbl_8034CA9C:
/* 8034CA9C 0034967C  38 60 00 00 */	li r3, 0
/* 8034CAA0 00349680  4B FF A3 D5 */	bl EXIUnlock
/* 8034CAA4 00349684  7F 43 D3 78 */	mr r3, r26
lbl_8034CAA8:
/* 8034CAA8 00349688  BB 41 00 18 */	lmw r26, 0x18(r1)
/* 8034CAAC 0034968C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8034CAB0 00349690  38 21 00 30 */	addi r1, r1, 0x30
/* 8034CAB4 00349694  7C 08 03 A6 */	mtlr r0
/* 8034CAB8 00349698  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

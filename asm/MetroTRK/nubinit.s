.include "macros.inc"

.section .text  # 0x80005940 - 0x803B7240

.global TRKInitializeNub
TRKInitializeNub:
/* 80326AD8 003236B8  7C 08 02 A6 */	mflr r0
/* 80326ADC 003236BC  90 01 00 04 */	stw r0, 4(r1)
/* 80326AE0 003236C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80326AE4 003236C4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80326AE8 003236C8  93 C1 00 08 */	stw r30, 8(r1)
/* 80326AEC 003236CC  48 00 01 0D */	bl TRKInitializeEndian
/* 80326AF0 003236D0  7C 7E 1B 79 */	or. r30, r3, r3
/* 80326AF4 003236D4  40 82 00 08 */	bne lbl_80326AFC
/* 80326AF8 003236D8  48 00 0B AD */	bl usr_put_initialize
lbl_80326AFC:
/* 80326AFC 003236DC  2C 1E 00 00 */	cmpwi r30, 0
/* 80326B00 003236E0  40 82 00 0C */	bne lbl_80326B0C
/* 80326B04 003236E4  4B FF FD 79 */	bl TRKInitializeEventQueue
/* 80326B08 003236E8  7C 7E 1B 78 */	mr r30, r3
lbl_80326B0C:
/* 80326B0C 003236EC  2C 1E 00 00 */	cmpwi r30, 0
/* 80326B10 003236F0  40 82 00 0C */	bne lbl_80326B1C
/* 80326B14 003236F4  48 00 01 89 */	bl TRKInitializeMessageBuffers
/* 80326B18 003236F8  7C 7E 1B 78 */	mr r30, r3
lbl_80326B1C:
/* 80326B1C 003236FC  2C 1E 00 00 */	cmpwi r30, 0
/* 80326B20 00323700  40 82 00 0C */	bne lbl_80326B2C
/* 80326B24 00323704  48 00 0B 85 */	bl TRKInitializeDispatcher
/* 80326B28 00323708  7C 7E 1B 78 */	mr r30, r3
lbl_80326B2C:
/* 80326B2C 0032370C  2C 1E 00 00 */	cmpwi r30, 0
/* 80326B30 00323710  40 82 00 40 */	bne lbl_80326B70
/* 80326B34 00323714  3C 60 80 4A */	lis r3, gTRKInputPendingPtr@ha
/* 80326B38 00323718  3B E3 4B 3C */	addi r31, r3, gTRKInputPendingPtr@l
/* 80326B3C 0032371C  3C 60 00 01 */	lis r3, 0x0000E100@ha
/* 80326B40 00323720  38 DF 00 00 */	addi r6, r31, 0
/* 80326B44 00323724  38 63 E1 00 */	addi r3, r3, 0x0000E100@l
/* 80326B48 00323728  38 80 00 01 */	li r4, 1
/* 80326B4C 0032372C  38 A0 00 00 */	li r5, 0
/* 80326B50 00323730  48 00 42 85 */	bl TRKInitializeIntDrivenUART
/* 80326B54 00323734  7C 60 1B 78 */	mr r0, r3
/* 80326B58 00323738  80 7F 00 00 */	lwz r3, 0(r31)
/* 80326B5C 0032373C  7C 1F 03 78 */	mr r31, r0
/* 80326B60 00323740  48 00 3A B9 */	bl TRKTargetSetInputPendingPtr
/* 80326B64 00323744  2C 1F 00 00 */	cmpwi r31, 0
/* 80326B68 00323748  41 82 00 08 */	beq lbl_80326B70
/* 80326B6C 0032374C  7F FE FB 78 */	mr r30, r31
lbl_80326B70:
/* 80326B70 00323750  2C 1E 00 00 */	cmpwi r30, 0
/* 80326B74 00323754  40 82 00 0C */	bne lbl_80326B80
/* 80326B78 00323758  48 00 0B 01 */	bl TRKInitializeSerialHandler
/* 80326B7C 0032375C  7C 7E 1B 78 */	mr r30, r3
lbl_80326B80:
/* 80326B80 00323760  2C 1E 00 00 */	cmpwi r30, 0
/* 80326B84 00323764  40 82 00 0C */	bne lbl_80326B90
/* 80326B88 00323768  48 00 3C 91 */	bl TRKInitializeTarget
/* 80326B8C 0032376C  7C 7E 1B 78 */	mr r30, r3
lbl_80326B90:
/* 80326B90 00323770  7F C3 F3 78 */	mr r3, r30
/* 80326B94 00323774  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80326B98 00323778  83 C1 00 08 */	lwz r30, 8(r1)
/* 80326B9C 0032377C  38 21 00 10 */	addi r1, r1, 0x10
/* 80326BA0 00323780  80 01 00 04 */	lwz r0, 4(r1)
/* 80326BA4 00323784  7C 08 03 A6 */	mtlr r0
/* 80326BA8 00323788  4E 80 00 20 */	blr 

.global TRKTerminateNub
TRKTerminateNub:
/* 80326BAC 0032378C  7C 08 02 A6 */	mflr r0
/* 80326BB0 00323790  90 01 00 04 */	stw r0, 4(r1)
/* 80326BB4 00323794  94 21 FF F8 */	stwu r1, -8(r1)
/* 80326BB8 00323798  48 00 0A E5 */	bl TRKTerminateSerialHandler
/* 80326BBC 0032379C  38 60 00 00 */	li r3, 0
/* 80326BC0 003237A0  38 21 00 08 */	addi r1, r1, 8
/* 80326BC4 003237A4  80 01 00 04 */	lwz r0, 4(r1)
/* 80326BC8 003237A8  7C 08 03 A6 */	mtlr r0
/* 80326BCC 003237AC  4E 80 00 20 */	blr 

.global TRKNubWelcome
TRKNubWelcome:
/* 80326BD0 003237B0  7C 08 02 A6 */	mflr r0
/* 80326BD4 003237B4  3C 60 80 3C */	lis r3, lbl_803B93A0@ha
/* 80326BD8 003237B8  90 01 00 04 */	stw r0, 4(r1)
/* 80326BDC 003237BC  38 63 93 A0 */	addi r3, r3, lbl_803B93A0@l
/* 80326BE0 003237C0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80326BE4 003237C4  48 00 43 79 */	bl TRK_board_display
/* 80326BE8 003237C8  38 21 00 08 */	addi r1, r1, 8
/* 80326BEC 003237CC  80 01 00 04 */	lwz r0, 4(r1)
/* 80326BF0 003237D0  7C 08 03 A6 */	mtlr r0
/* 80326BF4 003237D4  4E 80 00 20 */	blr 

.global TRKInitializeEndian
TRKInitializeEndian:
/* 80326BF8 003237D8  3C 60 80 4A */	lis r3, gTRKBigEndian@ha
/* 80326BFC 003237DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80326C00 003237E0  38 A3 31 70 */	addi r5, r3, gTRKBigEndian@l
/* 80326C04 003237E4  38 C0 00 01 */	li r6, 1
/* 80326C08 003237E8  90 C5 00 00 */	stw r6, 0(r5)
/* 80326C0C 003237EC  38 00 00 12 */	li r0, 0x12
/* 80326C10 003237F0  38 60 00 34 */	li r3, 0x34
/* 80326C14 003237F4  98 01 00 08 */	stb r0, 8(r1)
/* 80326C18 003237F8  38 80 00 56 */	li r4, 0x56
/* 80326C1C 003237FC  38 00 00 78 */	li r0, 0x78
/* 80326C20 00323800  98 61 00 09 */	stb r3, 9(r1)
/* 80326C24 00323804  38 60 00 00 */	li r3, 0
/* 80326C28 00323808  98 81 00 0A */	stb r4, 0xa(r1)
/* 80326C2C 0032380C  98 01 00 0B */	stb r0, 0xb(r1)
/* 80326C30 00323810  80 81 00 08 */	lwz r4, 8(r1)
/* 80326C34 00323814  3C 04 ED CC */	addis r0, r4, 0xedcc
/* 80326C38 00323818  28 00 56 78 */	cmplwi r0, 0x5678
/* 80326C3C 0032381C  40 82 00 0C */	bne lbl_80326C48
/* 80326C40 00323820  90 C5 00 00 */	stw r6, 0(r5)
/* 80326C44 00323824  48 00 00 20 */	b lbl_80326C64
lbl_80326C48:
/* 80326C48 00323828  3C 04 87 AA */	addis r0, r4, 0x87aa
/* 80326C4C 0032382C  28 00 34 12 */	cmplwi r0, 0x3412
/* 80326C50 00323830  40 82 00 10 */	bne lbl_80326C60
/* 80326C54 00323834  38 00 00 00 */	li r0, 0
/* 80326C58 00323838  90 05 00 00 */	stw r0, 0(r5)
/* 80326C5C 0032383C  48 00 00 08 */	b lbl_80326C64
lbl_80326C60:
/* 80326C60 00323840  38 60 00 01 */	li r3, 1
lbl_80326C64:
/* 80326C64 00323844  38 21 00 10 */	addi r1, r1, 0x10
/* 80326C68 00323848  4E 80 00 20 */	blr 


.section .rodata
    .balign 8
.global lbl_803B93A0
lbl_803B93A0:
    .4byte 0x4D657472
    .4byte 0x6F54524B
    .4byte 0x20666F72
    .4byte 0x20446F6C
    .4byte 0x7068696E
    .4byte 0x2076302E
    .4byte 0x38000000
    .4byte 0x00000000


.section .bss, "wa"
.global lbl_804A3148
lbl_804A3148:
	.skip 0x28
.global gTRKBigEndian
gTRKBigEndian:
	.skip 0x8
.global lbl_804A3178
lbl_804A3178:
	.skip 0x19B0
.global gTRKFramingState
gTRKFramingState:
	.skip 0x14
.global gTRKInputPendingPtr
gTRKInputPendingPtr:
	.skip 0x4
.global lbl_804A4B40
lbl_804A4B40:
	.skip 0x8
.global lbl_804A4B48
lbl_804A4B48:
	.skip 0x4
.global lbl_804A4B4C
lbl_804A4B4C:
	.skip 0x94
.global TRKvalue128_temp
TRKvalue128_temp:
	.skip 0x10
.global gTRKState
gTRKState:
	.skip 0xA8
.global gTRKCPUState
gTRKCPUState:
	.skip 0x430
.global lbl_804A50C8
lbl_804A50C8:
	.skip 0x8
.global TRK_mainError
TRK_mainError:
	.skip 0x10

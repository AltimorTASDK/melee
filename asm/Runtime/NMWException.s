.include "macros.inc"

.section .text  # 0x80005940 - 0x803B7240

.global __destroy_global_chain
__destroy_global_chain:
/* 80322714 0031F2F4  7C 08 02 A6 */	mflr r0
/* 80322718 0031F2F8  90 01 00 04 */	stw r0, 4(r1)
/* 8032271C 0031F2FC  94 21 FF F8 */	stwu r1, -8(r1)
/* 80322720 0031F300  48 00 00 20 */	b lbl_80322740
lbl_80322724:
/* 80322724 0031F304  80 03 00 00 */	lwz r0, 0(r3)
/* 80322728 0031F308  38 80 FF FF */	li r4, -1
/* 8032272C 0031F30C  90 0D B9 B8 */	stw r0, lbl_804D7058@sda21(r13)
/* 80322730 0031F310  81 83 00 04 */	lwz r12, 4(r3)
/* 80322734 0031F314  80 63 00 08 */	lwz r3, 8(r3)
/* 80322738 0031F318  7D 88 03 A6 */	mtlr r12
/* 8032273C 0031F31C  4E 80 00 21 */	blrl 
lbl_80322740:
/* 80322740 0031F320  80 6D B9 B8 */	lwz r3, lbl_804D7058@sda21(r13)
/* 80322744 0031F324  28 03 00 00 */	cmplwi r3, 0
/* 80322748 0031F328  40 82 FF DC */	bne lbl_80322724
/* 8032274C 0031F32C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80322750 0031F330  38 21 00 08 */	addi r1, r1, 8
/* 80322754 0031F334  7C 08 03 A6 */	mtlr r0
/* 80322758 0031F338  4E 80 00 20 */	blr 

.global __unregister_fragment
__unregister_fragment:
/* 8032275C 0031F33C  2C 03 00 00 */	cmpwi r3, 0
/* 80322760 0031F340  41 80 00 2C */	blt lbl_8032278C
/* 80322764 0031F344  2C 03 00 01 */	cmpwi r3, 1
/* 80322768 0031F348  40 80 00 24 */	bge lbl_8032278C
/* 8032276C 0031F34C  1C 83 00 0C */	mulli r4, r3, 0xc
/* 80322770 0031F350  3C 60 80 4A */	lis r3, fragmentinfo@ha
/* 80322774 0031F354  38 03 2F 38 */	addi r0, r3, fragmentinfo@l
/* 80322778 0031F358  7C 60 22 14 */	add r3, r0, r4
/* 8032277C 0031F35C  38 00 00 00 */	li r0, 0
/* 80322780 0031F360  90 03 00 00 */	stw r0, 0(r3)
/* 80322784 0031F364  90 03 00 04 */	stw r0, 4(r3)
/* 80322788 0031F368  90 03 00 08 */	stw r0, 8(r3)
lbl_8032278C:
/* 8032278C 0031F36C  4E 80 00 20 */	blr 

.global __register_fragment
__register_fragment:
/* 80322790 0031F370  3C A0 80 4A */	lis r5, fragmentinfo@ha
/* 80322794 0031F374  38 A5 2F 38 */	addi r5, r5, fragmentinfo@l
/* 80322798 0031F378  48 00 00 04 */	b lbl_8032279C
lbl_8032279C:
/* 8032279C 0031F37C  48 00 00 04 */	b lbl_803227A0
lbl_803227A0:
/* 803227A0 0031F380  80 05 00 08 */	lwz r0, 8(r5)
/* 803227A4 0031F384  2C 00 00 00 */	cmpwi r0, 0
/* 803227A8 0031F388  40 82 00 1C */	bne lbl_803227C4
/* 803227AC 0031F38C  90 65 00 00 */	stw r3, 0(r5)
/* 803227B0 0031F390  38 00 00 01 */	li r0, 1
/* 803227B4 0031F394  38 60 00 00 */	li r3, 0
/* 803227B8 0031F398  90 85 00 04 */	stw r4, 4(r5)
/* 803227BC 0031F39C  90 05 00 08 */	stw r0, 8(r5)
/* 803227C0 0031F3A0  48 00 00 08 */	b lbl_803227C8
lbl_803227C4:
/* 803227C4 0031F3A4  38 60 FF FF */	li r3, -1
lbl_803227C8:
/* 803227C8 0031F3A8  4E 80 00 20 */	blr 


.section .bss, "wa"
    .balign 8
.global fragmentinfo
fragmentinfo:
	.skip 0x10


.section .sbss
    .balign 8
.global lbl_804D7058
lbl_804D7058:
	.skip 0x8

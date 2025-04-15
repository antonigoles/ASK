	.file	"zad4.c"
	.text
	.p2align 4
	.globl	puzzle
	.type	puzzle, @function
puzzle:
.LFB0:
	.cfi_startproc
	endbr64
	xorl	%eax, %eax
	testl	%esi, %esi
	je	.L1
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%edi, %ecx
	addl	$1, %edx
	sarq	%rdi
	andl	$1, %ecx
	addl	%ecx, %eax
	cmpl	%edx, %esi
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	puzzle, .-puzzle
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

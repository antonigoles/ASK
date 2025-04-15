	.file	"zad5.c"
	.text
	.globl	puzzle2
	.type	puzzle2, @function
puzzle2:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
.L4:
	movzbl	(%rax), %r8d
	leaq	1(%rax), %r9
	movq	%rsi, %rdx
.L3:
	movzbl	(%rdx), %ecx
	addq	$1, %rdx
	testb	%cl, %cl
	je	.L6
	cmpb	%cl, %r8b
	jne	.L3
	movq	%r9, %rax
	jmp	.L4
.L6:
	subq	%rdi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	puzzle2, .-puzzle2
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

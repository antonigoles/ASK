	.file	"zad1.c"
	.text
	.globl	pointless
	.type	pointless, @function
pointless:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%rdi, %rbx
	movq	%rsi, %rbp
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	testq	%rdi, %rdi
	jg	.L2
	movq	$0, (%rsp)
.L3:
	movq	(%rsp), %rax
	addq	%rax, %rbx
	movq	%rbx, 0(%rbp)
	movq	8(%rsp), %rdx
	subq	%fs:40, %rdx
	jne	.L6
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L2:
	.cfi_restore_state
	movq	%rsp, %rsi
	leaq	(%rdi,%rdi), %rdi
	call	pointless
	addq	%rax, (%rsp)
	jmp	.L3
.L6:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE0:
	.size	pointless, .-pointless
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

	.section .rdata,"dr"
.IntFormat:
	.ascii "%d\0"
	.text
	.globl	printInt
	.def	printInt;	.scl	2;	.type	32;	.endef
	.seh_proc	printInt
printInt:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	128(%rbp), %edx
	leaq	.IntFormat(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
.StrFormat:
	.ascii "%s\0"
	.text
	.globl	printStr
	.def	printStr;	.scl	2;	.type	32;	.endef
	.seh_proc	printStr
printStr:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	128(%rbp), %rdx
	leaq	.StrFormat(%rip), %rcx
	call	printf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
.section .rdata,"dr"
.InputFormat:
	.ascii "%d\0"
	.text
	.globl	inputInt
	.def	inputInt;	.scl	2;	.type	32;	.endef
	.seh_proc	inputInt
inputInt:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	128(%rbp), %rdx
	leaq	.InputFormat(%rip), %rcx
	call	scanf
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
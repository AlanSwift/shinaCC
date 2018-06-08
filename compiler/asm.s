	.text
	.globl	main
	.seh_proc	main
main:
	pushq	rbq
	.seh_pushreg	rbp
	movq	rsp, rbp
	.seh_setframe	rbp, 0
	subq	$0, rsp
	.seh_stackalloc	0
	.seh_endprologuep
	movq %r8, %r9
	movq %r9, -8(%rbp)
	movl $0, -12(%rbp)
	movq $0, -12(%rbp)
	movq %r10, -20(%rbp)
	movl -12(%rbp), %eax
	movzbl -12(%rbp), %eax
	sall $2, %eax
	movl %eax, %r11d
	movq %r12, %r13

	.section .rdata,"dr"
	.text
	.globl	mergeSort
	.seh_proc	mergeSort
mergeSort:
	pushq	rbp
	.seh_pushreg	rbp
	movq	rsp, rbp
	.seh_setframe	rbp, 0
	subq	$316, rsp
	.seh_stackalloc	316
	.seh_endprologue
	movl	32(%rbp), %eax
	cmpl	40(%rbp), %eax
	jg	label_21
label_1:
	movl	32(%rbp), %eax
	addl	40(%rbp), %eax
	movl	%eax, %r8d
	movl	$1, %ecx
	sarl	%cl, %r8d
	movl	%r8d, %r9d
	movl	%r9d, -4(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	24(%rbp), %rax
	movq	%rax, 8(%rsp)
	movl	32(%rbp), %eax
	movl	%eax, 16(%rsp)
	movl	-4(%rbp), %eax
	movl	%eax, 24(%rsp)
	call	mergeSort
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r10d
	movq	16(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	24(%rbp), %rax
	movq	%rax, 8(%rsp)
	movl	%r10d, 16(%rsp)
	movl	40(%rbp), %eax
	movl	%eax, 24(%rsp)
	call	mergeSort
	movl	32(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r11d
	movl	%r11d, -12(%rbp)
	movl	32(%rbp), %eax
	movl	%eax, -16(%rbp)
	jmp		label_6
label_2:
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	16(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	16(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	cmpl	%r13d, %r10d
	jg	label_4
label_3:
	movl	-16(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	24(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	16(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	movl	%r13d, (%rax)
	movq	%r9, %rax
	movl	(%rax), %r14d
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r15d
	movl	%r15d, -8(%rbp)
	jmp		label_5
label_4:
	movl	-16(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	24(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	16(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	movl	%r13d, (%rax)
	movq	%r9, %rax
	movl	(%rax), %r14d
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r15d
	movl	%r15d, -12(%rbp)
label_5:
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -16(%rbp)
label_6:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	label_8
label_7:
	movl	-12(%rbp), %eax
	cmpl	40(%rbp), %eax
	jle	label_2
label_8:
	jmp		label_10
label_9:
	movl	-16(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	24(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	16(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	movl	%r13d, (%rax)
	movq	%r9, %rax
	movl	(%rax), %r14d
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r15d
	movl	%r15d, -8(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -16(%rbp)
label_10:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jle	label_9
label_11:
	jmp		label_13
label_12:
	movl	-16(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	24(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	16(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	movl	%r13d, (%rax)
	movq	%r9, %rax
	movl	(%rax), %r14d
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r15d
	movl	%r15d, -12(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -16(%rbp)
label_13:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	label_15
label_14:
	movl	-12(%rbp), %eax
	cmpl	40(%rbp), %eax
	jle	label_12
label_15:
	movl	32(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp		label_18
label_16:
	movl	-20(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	16(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-20(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	24(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	movl	%r13d, (%rax)
	movq	%r9, %rax
	movl	(%rax), %r14d
label_17:
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -20(%rbp)
label_18:
	movl	-20(%rbp), %eax
	cmpl	40(%rbp), %eax
	jle	label_16
label_21:
	addq	$316, rsp
	popq	rbp
	ret
	.seh_endproc
	.globl	main
	.seh_proc	main
main:
	pushq	rbp
	.seh_pushreg	rbp
	movq	rsp, rbp
	.seh_setframe	rbp, 0
	subq	$472, rsp
	.seh_stackalloc	472
	.seh_endprologue
	movl	$0, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-60(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movl	$2, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r13d
	movl	$1, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r14d
	movq	%r9, %r15
	addq	%r14, %r15
	movq	%r15, %r8
	movq	%r8, %rax
	movl	(%rax), %r10d
	movl	$3, (%rax)
	movq	%r8, %rax
	movl	(%rax), %r10d
	movl	$2, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$4, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$3, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$1, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$4, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$9, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$5, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$7, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$6, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$3, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$7, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$19, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$8, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$6, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$9, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r8d
	movl	$25, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r8d
	movq	%r9, %r8
	leaq	-100(%rbp), %rax
	movq	%rax, %r8
	movq	%r8, %r9
	movq	%r8, 0(%rsp)
	movq	%r9, 8(%rsp)
	movl	$0, 16(%rsp)
	movl	$9, 24(%rsp)
	#call	mergeSort
	movl	$0, -104(%rbp)
	jmp		label_25
label_23:
	movl	-104(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-60(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movl	%r12d, -108(%rbp)
label_24:
	movl	-104(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -104(%rbp)
label_25:
	movl	-104(%rbp), %eax
	cmpl	$10, %eax
	jl	label_23
label_26:
	movl	$0, %eax
	jmp		label_27
label_27:
	addq	$472, rsp
	popq	rbp
	ret
	.seh_endproc

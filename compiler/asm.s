	.section .rdata,"dr"
.LC0:
	.ascii "result = %d\n\0"
.LC1:
	.ascii "center = %d\n\0"
	.text
	.globl	mergeSort
	.seh_proc	mergeSort
mergeSort:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$408, %rsp
	.seh_stackalloc	408
	.seh_endprologue
	movl	144(%rbp), %eax
	cmpl	152(%rbp), %eax
	jge	label_20
label_1:
	movl	144(%rbp), %eax
	addl	152(%rbp), %eax
	movl	%eax, %r8d
	movl	$1, %ecx
	sarl	%cl, %r8d
	movl	%r8d, %r9d
	movl	%r9d, -4(%rbp)
	movq	128(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	136(%rbp), %rax
	movq	%rax, 8(%rsp)
	movl	144(%rbp), %eax
	movl	%eax, 16(%rsp)
	movl	-4(%rbp), %eax
	movl	%eax, 24(%rsp)
	pushq	%rax
	pushq	%rcx
	pushq	%rdx
	pushq	%rbx
	pushq	%rsi
	pushq	%rdi
	pushq	%r8
	pushq	%r9
	pushq	%r10
	pushq	%r11
	pushq	%r12
	pushq	%r13
	pushq	%r14
	pushq	%r15
	call	mergeSort
	popq	%r15
	popq	%r14
	popq	%r13
	popq	%r12
	popq	%r11
	popq	%r10
	popq	%r9
	popq	%r8
	popq	%rdi
	popq	%rsi
	popq	%rbx
	popq	%rdx
	popq	%rcx
	popq	%rax
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r10d
	movq	128(%rbp), %rax
	movq	%rax, 0(%rsp)
	movq	136(%rbp), %rax
	movq	%rax, 8(%rsp)
	movl	%r10d, 16(%rsp)
	movl	152(%rbp), %eax
	movl	%eax, 24(%rsp)
	pushq	%rax
	pushq	%rcx
	pushq	%rdx
	pushq	%rbx
	pushq	%rsi
	pushq	%rdi
	pushq	%r8
	pushq	%r9
	pushq	%r10
	pushq	%r11
	pushq	%r12
	pushq	%r13
	pushq	%r14
	pushq	%r15
	call	mergeSort
	popq	%r15
	popq	%r14
	popq	%r13
	popq	%r12
	popq	%r11
	popq	%r10
	popq	%r9
	popq	%r8
	popq	%rdi
	popq	%rsi
	popq	%rbx
	popq	%rdx
	popq	%rcx
	popq	%rax
	movl	144(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r11d
	movl	%r11d, -12(%rbp)
	movl	144(%rbp), %eax
	movl	%eax, -16(%rbp)
	jmp		label_6
label_2:
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	128(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	128(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	cmpl	%r13d, %r10d
	jge	label_4
label_3:
	movl	-16(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	136(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r10d
	movq	128(%rbp), %rax
	addq	%r10, %rax
	movq	%rax, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movq	%r9, %rax
	movl	%r12d, (%rax)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r13d
	movl	%r13d, -8(%rbp)
	jmp		label_5
label_4:
	movl	-16(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	136(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r10d
	movq	128(%rbp), %rax
	addq	%r10, %rax
	movq	%rax, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movq	%r9, %rax
	movl	%r12d, (%rax)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r13d
	movl	%r13d, -12(%rbp)
label_5:
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -16(%rbp)
label_6:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jg	label_8
label_7:
	movl	-12(%rbp), %eax
	cmpl	152(%rbp), %eax
	jle	label_2
label_8:
	jmp		label_10
label_9:
	movl	-16(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	136(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r10d
	movq	128(%rbp), %rax
	addq	%r10, %rax
	movq	%rax, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movq	%r9, %rax
	movl	%r12d, (%rax)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r13d
	movl	%r13d, -8(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r14d
	movl	%r14d, -16(%rbp)
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
	movq	136(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r10d
	movq	128(%rbp), %rax
	addq	%r10, %rax
	movq	%rax, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movq	%r9, %rax
	movl	%r12d, (%rax)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r13d
	movl	%r13d, -12(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r14d
	movl	%r14d, -16(%rbp)
label_13:
	movl	-12(%rbp), %eax
	cmpl	152(%rbp), %eax
	jle	label_12
label_14:
	movl	144(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp		label_17
label_15:
	movl	-20(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	128(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movl	-20(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r10d
	movq	136(%rbp), %rax
	addq	%r10, %rax
	movq	%rax, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movq	%r9, %rax
	movl	%r12d, (%rax)
label_16:
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -20(%rbp)
label_17:
	movl	-20(%rbp), %eax
	cmpl	152(%rbp), %eax
	jle	label_15
label_20:
	addq	$408, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$672, %rsp
	.seh_stackalloc	672
	.seh_endprologue
	leaq	.LC0(%rip), %rax
	movq	%rax, %r8
	movq	%r8, -28(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %r9
	movq	%r9, -28(%rbp)
	movl	$0, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r10d
	leaq	-68(%rbp), %rax
	movq	%rax, %r11
	movq	%r11, %r12
	addq	%r10, %r12
	movq	%r12, %r13
	movq	%r13, %rax
	movl	$2, (%rax)
	movl	$1, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r14d
	movq	%r11, %r15
	addq	%r14, %r15
	movq	%r15, %r8
	movq	%r8, %rax
	movl	$3, (%rax)
	movl	$2, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$4, (%rax)
	movl	$3, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$1, (%rax)
	movl	$4, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$9, (%rax)
	movl	$5, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$7, (%rax)
	movl	$6, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$3, (%rax)
	movl	$7, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$19, (%rax)
	movl	$8, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$6, (%rax)
	movl	$9, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	$25, (%rax)
	movq	%r11, %r8
	leaq	-108(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	movq	%r8, 0(%rsp)
	movq	%r10, 8(%rsp)
	movl	$0, 16(%rsp)
	movl	$9, 24(%rsp)
	pushq	%rax
	pushq	%rcx
	pushq	%rdx
	pushq	%rbx
	pushq	%rsi
	pushq	%rdi
	pushq	%r8
	pushq	%r9
	pushq	%r10
	pushq	%r11
	pushq	%r12
	pushq	%r13
	pushq	%r14
	pushq	%r15
	call	mergeSort
	popq	%r15
	popq	%r14
	popq	%r13
	popq	%r12
	popq	%r11
	popq	%r10
	popq	%r9
	popq	%r8
	popq	%rdi
	popq	%rsi
	popq	%rbx
	popq	%rdx
	popq	%rcx
	popq	%rax
	movl	$0, -112(%rbp)
	jmp		label_24
label_22:
	movl	-112(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-108(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movl	%r12d, -116(%rbp)
	movl	-116(%rbp), %edx
	leaq	.LC0(%rip), %rcx
	call	printf
label_23:
	movl	-112(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -112(%rbp)
label_24:
	movl	-112(%rbp), %eax
	cmpl	$10, %eax
	jl	label_22
label_25:
	movl	$0, %eax
	jmp		label_26
label_26:
	addq	$672, %rsp
	popq	%rbp
	ret
	.seh_endproc

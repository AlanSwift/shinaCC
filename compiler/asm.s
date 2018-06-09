	.section .rdata,"dr"
.LC0:
	.ascii "result = %d\n\0"
.LC1:
	.ascii "center = %d\n\0"
	.text
<<<<<<< HEAD
	.globl	mergeSort
	.seh_proc	mergeSort
mergeSort:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$408, %rsp
	.seh_stackalloc	408
=======
	.globl	merge
	.seh_proc	merge
merge:
	pushq	rbp
	.seh_pushreg	rbp
	movq	rsp, rbp
	.seh_setframe	rbp, 0
	subq	$168, rsp
	.seh_stackalloc	168
>>>>>>> tmp
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
	movq	16(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
<<<<<<< HEAD
	movq	128(%rbp), %rax
=======
	movq	24(%rbp), %rax
>>>>>>> tmp
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
<<<<<<< HEAD
	movq	136(%rbp), %rax
=======
	movq	32(%rbp), %rax
>>>>>>> tmp
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
<<<<<<< HEAD
	movq	136(%rbp), %rax
=======
	movq	32(%rbp), %rax
>>>>>>> tmp
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
<<<<<<< HEAD
	movq	128(%rbp), %rax
=======
	movq	24(%rbp), %rax
>>>>>>> tmp
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
<<<<<<< HEAD
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
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	128(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
=======
	movl	%r8d, -12(%rbp)
label_5:
	movl	-4(%rbp), %eax
	cmpl	40(%rbp), %eax
	jge	label_8
label_6:
	movl	-8(%rbp), %eax
	cmpl	40(%rbp), %eax
	jl	label_1
label_8:
	addq	$168, rsp
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
	subq	$876, rsp
	.seh_stackalloc	876
	.seh_endprologue
	leaq	.LC0(%rip), %rax
	movq	%rax, %r8
	movq	%r8, -20(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %r9
	movq	%r9, -20(%rbp)
	movl	$0, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r10d
	leaq	-60(%rbp), %rax
	movq	%rax, %r11
	movq	%r11, %r12
	addq	%r10, %r12
	movq	%r12, %r13
	movq	%r13, %rax
	movl	(%rax), %r14d
	movl	$0, (%rax)
	movq	%r13, %rax
	movl	(%rax), %r15d
	movl	$1, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$1, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$2, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$2, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$3, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$3, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$4, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$4, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$5, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$5, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$6, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$6, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$7, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$7, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$8, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$8, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$9, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r11, %r9
	addq	%r8, %r9
	movq	%r9, %r10
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$9, (%rax)
	movq	%r10, %rax
	movl	(%rax), %r8d
	movl	$0, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-100(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$1, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$1, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$11, (%rax)
>>>>>>> tmp
	movq	%r12, %rax
	movl	(%rax), %r13d
	movq	%r9, %rax
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
<<<<<<< HEAD
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
	movq	136(%rbp), %rax
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
=======
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$21, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$3, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$31, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$4, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$41, (%rax)
>>>>>>> tmp
	movq	%r12, %rax
	movl	(%rax), %r13d
	movq	%r9, %rax
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
<<<<<<< HEAD
	movl	%r8d, -16(%rbp)
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
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-20(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	136(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
=======
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$51, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$6, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$61, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$7, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$71, (%rax)
>>>>>>> tmp
	movq	%r12, %rax
	movl	(%rax), %r13d
	movq	%r9, %rax
	movl	%r13d, (%rax)
	movq	%r9, %rax
	movl	(%rax), %r14d
label_16:
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
<<<<<<< HEAD
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
	subq	$440, %rsp
	.seh_stackalloc	440
	.seh_endprologue
	leaq	.LC0(%rip), %rax
	movq	%rax, %r8
	movq	%r8, -28(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %r9
	movq	%r9, -28(%rbp)
	movl	$0, -32(%rbp)
	jmp		label_24
label_22:
	movl	-32(%rbp), %eax
=======
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$81, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$9, %eax
>>>>>>> tmp
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-72(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
<<<<<<< HEAD
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movl	$2, %r15d
	imull	-32(%rbp), %r15d
	movl	%r15d, %r13d
	movl	$100, %r15d
	subl	%r13d, %r15d
	movl	%r15d, %r14d
	movq	%r11, %rax
	movl	%r14d, (%rax)
	movq	%r11, %rax
	movl	(%rax), %r15d
label_23:
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -32(%rbp)
label_24:
	movl	-32(%rbp), %eax
	cmpl	$10, %eax
	jl	label_22
label_25:
	leaq	-72(%rbp), %rax
	movq	%rax, %r8
	movq	%r8, %r9
	leaq	-112(%rbp), %rax
	movq	%rax, %r10
	movq	%r10, %r11
	movq	%r9, 0(%rsp)
	movq	%r11, 8(%rsp)
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
	movl	$0, -32(%rbp)
	jmp		label_28
label_26:
	movl	-32(%rbp), %eax
=======
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$91, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movq	%r11, %r8
	movq	%r9, %r10
	leaq	-180(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r11
	movq	%r8, 0(%rsp)
	movq	%r10, 8(%rsp)
	movq	%r11, 16(%rsp)
	movl	$5, 24(%rsp)
	call	merge
	movl	$0, -184(%rbp)
	jmp		label_12
label_10:
	movl	-184(%rbp), %eax
>>>>>>> tmp
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-112(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
<<<<<<< HEAD
	movl	%r12d, -116(%rbp)
	movl	-116(%rbp), %edx
leaq	.LC0(%rip), %rcx
call	printf
label_27:
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -32(%rbp)
label_28:
	movl	-32(%rbp), %eax
	cmpl	$10, %eax
	jl	label_26
label_29:
	movl	$0, %eax
	jmp		label_30
label_30:
	addq	$440, %rsp
	popq	%rbp
=======
	movl	%r12d, -188(%rbp)
label_11:
	movl	-184(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -184(%rbp)
label_12:
	movl	-184(%rbp), %eax
	cmpl	$20, %eax
	jl	label_10
label_13:
	movl	$0, %eax
	jmp		label_14
label_14:
	addq	$876, rsp
	popq	rbp
>>>>>>> tmp
	ret
	.seh_endproc

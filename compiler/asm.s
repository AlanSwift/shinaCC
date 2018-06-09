	.section .rdata,"dr"
.LC0:
	.ascii "result = %d\n\0"
.LC1:
	.ascii "center = %d\n\0"
	.text
	.globl	merge
	.seh_proc	merge
merge:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$260, %rsp
	.seh_stackalloc	260
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp		label_5
label_1:
	movl	-4(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	128(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	136(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	cmpl	%r13d, %r10d
	jge	label_3
label_2:
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	144(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-4(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	128(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
	movq	%r12, %rax
	movl	(%rax), %r13d
	movq	%r9, %rax
	movl	%r13d, (%rax)
	movq	%r9, %rax
	movl	(%rax), %r14d
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r15d
	movl	%r15d, -4(%rbp)
	jmp		label_4
label_3:
	movl	-12(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	144(%rbp), %rax
	addq	%r8, %rax
	movq	%rax, %r9
	movq	%r9, %rax
	movl	(%rax), %r10d
	movl	-8(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r11d
	movq	136(%rbp), %rax
	addq	%r11, %rax
	movq	%rax, %r12
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
label_4:
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -12(%rbp)
label_5:
	movl	-4(%rbp), %eax
	cmpl	152(%rbp), %eax
	jge	label_8
label_6:
	movl	-8(%rbp), %eax
	cmpl	152(%rbp), %eax
	jl	label_1
label_8:
	addq	$260, %rsp
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
	subq	$968, %rsp
	.seh_stackalloc	968
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
	movq	%r13, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r10, %rax
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
	movq	%r12, %rax
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
	movq	%r12, %rax
	movl	$11, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$2, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movq	%r12, %rax
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
	movq	%r12, %rax
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
	movq	%r12, %rax
	movl	$41, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$5, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movq	%r12, %rax
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
	movq	%r12, %rax
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
	movq	%r12, %rax
	movl	$71, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$8, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movq	%r12, %rax
	movl	$81, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movl	$9, %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r12
	movq	%r12, %rax
	movl	(%rax), %r8d
	movq	%r12, %rax
	movl	$91, (%rax)
	movq	%r12, %rax
	movl	(%rax), %r8d
	movq	%r11, %r8
	movq	%r9, %r8
	leaq	-180(%rbp), %rax
	movq	%rax, %r8
	movq	%r8, %r9
	movq	%r8, 0(%rsp)
	movq	%r8, 8(%rsp)
	movq	%r9, 16(%rsp)
	movl	$5, 24(%rsp)
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
	call	merge
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
	movl	$0, -184(%rbp)
	jmp		label_12
label_10:
	movl	-184(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-180(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movl	%r12d, -188(%rbp)
	movl	-188(%rbp), %edx
	leaq	.LC0(%rip), %rcx
	call	printf
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
	addq	$968, %rsp
	popq	%rbp
	ret
	.seh_endproc

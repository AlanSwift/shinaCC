	.section .rdata,"dr"
.LC0:
	.ascii ", \0"
.LC1:
	.ascii "\n\0"
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
	subq	$428, %rsp
	.seh_stackalloc	428
	.seh_endprologue
	movl	$0, -24(%rbp)
	jmp		label_24
label_22:
	movl	-24(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-64(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, 0(%rsp)
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
	call	inputInt
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
label_23:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -24(%rbp)
label_24:
	movl	-24(%rbp), %eax
	cmpl	$10, %eax
	jl	label_22
label_25:
	leaq	-64(%rbp), %rax
	movq	%rax, %r8
	movq	%r8, %r9
	leaq	-104(%rbp), %rax
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
	movl	$0, -24(%rbp)
	jmp		label_28
label_26:
	movl	-24(%rbp), %eax
	movl	$2, %ecx
	sall	%cl, %eax
	movl	%eax, %r8d
	leaq	-104(%rbp), %rax
	movq	%rax, %r9
	movq	%r9, %r10
	addq	%r8, %r10
	movq	%r10, %r11
	movq	%r11, %rax
	movl	(%rax), %r12d
	movl	%r12d, -108(%rbp)
	movl	-108(%rbp), %eax
	movl	%eax, 0(%rsp)
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
	call	printInt
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
	leaq	.LC0(%rip), %rax
	movq	%rax, %r13
	movq	%r13, 0(%rsp)
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
	call	printStr
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
label_27:
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %r8d
	movl	%r8d, -24(%rbp)
label_28:
	movl	-24(%rbp), %eax
	cmpl	$10, %eax
	jl	label_26
label_29:
	leaq	.LC1(%rip), %rax
	movq	%rax, %r8
	movq	%r8, 0(%rsp)
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
	call	printStr
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
	movl	$0, %eax
	jmp		label_30
label_30:
	addq	$428, %rsp
	popq	%rbp
	ret
	.seh_endproc

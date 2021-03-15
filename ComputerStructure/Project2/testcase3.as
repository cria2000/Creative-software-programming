	lw	0	1	five
	noop
	noop
	noop
	lw	0	2	one
	noop
	noop
	noop
	lw	0	3	zero
	noop
	noop
	noop
loop	beq	1	3	done
	noop
	noop
	noop
	add	2	3	3
	noop
	noop
	noop
	beq	0	0	loop
done	halt
zero	.fill	0
one	.fill	1
five	.fill	5

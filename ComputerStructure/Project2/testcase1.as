	lw	0	1	one	load reg1 to 1
	noop				no hazard
	noop				no hazard
	noop				no hazard
	sw	0	1	11	load reg2 to 2
	noop
	noop
	noop
	add	1	2	3	add reg1 and reg2, store to reg2
	halt
one	.fill	1
two	.fill	2

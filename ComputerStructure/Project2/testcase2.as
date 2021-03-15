	lw	0	1	zero	load 0 to reg1
	noop				no hazard
	noop				no hazard
	noop				no hazard
	lw	0	2	three	load 3 to reg2(when finish the program, reg3's value is 2's complement of 3)
	noop				no hazard
	noop				no hazard
	noop				no hazard
	nor	1	2	3	nor reg1's value and reg2's value and store it to reg3
	noop				no hazard
	noop				no hazard
	noop				no hazard
	lw	0	4	one	load 1 to reg4(to make 2's comlement, add 1)	
	noop				no hazard
	noop				no hazard
	noop				no hazard
	add	3	4	3	add reg3's value and reg4's value, store it to reg3
	halt				finish the program
zero	.fill	0
three	.fill	3
one	.fill	1

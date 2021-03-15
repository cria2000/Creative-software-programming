	lw	0	1	one	load 1 to reg1
	add	1	1	3	twice reg1's value and store it to reg1(data hazard occured between lw and add.)
	noop				no hazard
	noop				no hazard
	noop				no hazard
	lw	0	2	two	load 2 to reg2
	noop				no hazard
	noop				no hazard
	noop				no hazard
	add	2	2	4	twice reg2's value and store it reg4
	add	4	4	4	twice reg4's value and store it reg4(data hazard occured between add and add, but it can get right reg4's value from EX stage)
	halt				finish the program
one	.fill	1			
two	.fill	2

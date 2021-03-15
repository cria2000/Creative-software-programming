	lw	0	1	one	load 1 to reg1
	noop				no hazard		
	noop				no hazard
	noop				no hazard
	lw 	0	2	one	load 1 to reg2
	noop				no hazard
	noop				no hezard
	noop				no hazard
	beq	1	2	Go	if reg1's value and reg2's value are same, go to Go(use branch not taken, so just execute below instructions, and when beq arrive at MEM stage, three flush)
	lw	0	1	data1	
	noop
	lw	2	3	data2
	lw	4	5	data3
Go	halt
one	.fill	1
data1	.fill	10
data2	.fill	20
data3	.fill	30	

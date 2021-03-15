	lw	0	1	11	load one to reg1	
	lw	0	2	goal	load 9 to reg2(goal is the value that we have to calaulate 2's complement)
	lw	0	3	one	load one to reg3
	lw	0	4	addn	load 2 to reg4
start	beq	1	2	2	if reg1's value and reg2's value are same, go to ment(to calculate 2's complement)
	add	4	1	1	add 2 to reg1 to make the same reg1's value and goal's value
	beq	0	0	start	go to start
ment	nor	1	2	5	nor reg1's value and reg2's value and store it reg5(they are the same value, so it make 1's complement)
	add	3	5	5	add 1 to 1's comlement and store it to reg5	
	noop
	halt				end of the program
one	.fill	1
addn	.fill	2
goal	.fill	9

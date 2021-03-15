	lw	0	1	five	load 5 to reg1
	lw	0	2	two	load 2 to reg2
	lw	0	3	one	load 1 to reg3	
	lw	0	5	19	load 0 to reg5 and this will be the quotient
	lw	0	6	remain	load 0 to reg6 and this will be the remainder
	nor	2	2	4	make 1's comlement of 2 and store it to reg4
	add	4	3	4	make 2's comlement of 2 and store it to reg4
start	beq	0	1	store0	if reg1's value is zero, go to store0
	beq	3	1	5	if reg2's value is one, go to store1
	add	1	4	1	subtract 2 from reg1's value
	add	3	5	5	increase reg5's value
	beq	0	0	start	go to start
store0	lw	0	6	zero	load 0 to reg6
	beq	0	0	done	go to done
store1	lw	0	6	one	load 1 to reg6
done	halt				end of the program
five	.fill	5
two	.fill	2
one	.fill	1
quot	.fill	0
remain	.fill	0
zero	.fill	0

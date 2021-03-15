	lw	0	2	mcand	load 32766 to reg2 and it will double per loop
	lw	0	3	mplier	load 10383 to reg3	
	nor	0	0	4	store -1 to reg4
	lw	0	5	neg1	load -1 to reg5
	lw	0	7	final	load -32769(number with 16th bit only 0)
	add	4	5	4	add -1 to reg4
	nor	4	3	6	if reg3's LSB is 0, reg6 will 1 and LSB is 1, reg6 will 0
	beq	0	6	here	if reg3's LSB is 1, go to here
here2	add	2	2	2	double reg2's value(shift left one bit)
	beq	0	0	start	go to start
here	add	2	1	1	add reg2's value to reg1
	beq	0	0	here2	go to here2
start	beq	4	7	done	if reg4's value is -32769, go to done
	add	4	5	4	move 0 bit one space to the left
	nor	4	3	6	nor reg4's value and reg3's value, and store it to reg6	
	beq	0	6	mul	if nor's result is 0, go to mul
re	add	2	2	2	double reg2's value
	add	5	5	5	double reg5's value
	beq	0	0	start	go to start	
mul	add	2	1	1	add reg2's value to reg1
	beq	0	0	re	go to re
done	halt				end of the program
neg1	.fill	-1
zero 	.fill	0
one	.fill	1
mcand	.fill	32766
mplier	.fill	10383
final	.fill	-32769

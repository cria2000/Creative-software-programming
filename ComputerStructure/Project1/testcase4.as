	lw	0	1	six	load 6 to reg1(6 is the value we have to calculate square)
	lw	0	2	27	load 6 to reg2
	lw	0	3	negh	load -1 to reg3
	lw	0	7	zero	load 0 to reg7
	nor	0	0	4	store -1 to reg4
	add	4	3	4	add -1 to reg4
	nor	4	2	5	nor reg4's vlaue and reg2's value, and store it reg5
	beq	5	0	1	if nor value is 0, go to mult
	beq	0	0	heres	go ti heres
mult	add	1	6	6	add reg1's value to reg6
heres	add	1	1	1	double the reg1's value
	lw	0	5	31	load 1 to reg5
	add	5	7	7	increase reg7
start	lw	0	5	three	load 3 to reg5
	beq	5	7	done	if reg7's value is 3, go to done
	add	4	3	4	add reg3's value to reg4
	nor	4	2	5	nor reg4's value and reg2's value, and store it reg5
	beq	5	0	mul	if nor value is 0, go to mul
	beq	0	0	here	go to here
mul	add	1	6	6	add reg1's value to reg6(reg6's value is final square value)
here	add	3	3	3	double the reg3's value
	add	1	1	1	double the reg1's value
	lw	0	5	one	load 1 to reg5
	add	5	7	7	increase the reg7
	beq	0	0	start	go to start
	noop
done	halt
six	.fill	6
negh	.fill	-1
zero	.fill	0
three	.fill	3
one	.fill	1

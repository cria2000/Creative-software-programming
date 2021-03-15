	lw	0	1	zero	load 0 to reg1 and it will store the result of 5's factorial
	lw	0	2	five	load 5 to reg2
	lw	0	3	neg1	load -1 to reg3
	lw	0	4	20	load 5 to reg4
	add	3	4	4	add reg3's value to reg4
	add	1	2	1	add 5 to reg1
start	beq	0	2	done	if reg2's value becomes zero, go to done
	add	2	3	2	decrease reg2's value
	sw	0	2	22	store the reg2's value to address 22
	lw	0	4	22	load the value of address 22 to reg4(previous reg2's value)
	sw	0	1	23	store the reg1's value to address 23
	lw	0	5	23	load the vlaue of address 23 to reg5(previous reg4's value)
	beq	0	4	5	if reg4's value bacomes 0(before decreasing), go to done
here	add	4	3	4	decrease reg4's value
	beq	0	4	start	if reg4's value is 0,(after decreasing) go to start
	add	5	1	1	add reg5's value to reg1
	beq	0	0	here	go to here
	noop
done	halt				end of the program
zero	.fill	0
five	.fill	5
neg1	.fill	-1

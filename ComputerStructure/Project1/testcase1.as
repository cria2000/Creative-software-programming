	lw	0	1	13	load 19 to reg1, this will be shift by 4 
	lw	0	2	Lshift	load 4 to reg2
	lw	0	3	zero	load 0 to reg3
	lw	0	4	one	load 1 to reg4
	lw	0	5	double	load 10 to re5 and 11 is the address that can double the reg1's value
start	beq	2	3	done	if reg3's value is 4, go to done
	jalr	5	6		go to address 11
	add	3	4	3	increase the reg3's value
	beq	0	0	start	go to start
	noop				no operation
	add	1	1	1	double the reg1's value
	jalr	6	7		go to first add
done	halt				end of the program
value	.fill	19	
Lshift	.fill	4
zero	.fill	0
one	.fill	1
double	.fill	10

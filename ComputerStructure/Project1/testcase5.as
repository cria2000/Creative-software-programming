	lw	0	1	zero	load 0 to reg1
	lw	0	2	result	load 0 to reg2, and it will the final result of the sum
	lw	0	3	ten	load 10 to reg3
	lw	0	4	12	load 1 to reg4
start	add	1	2	2 	add reg1's value to reg2
	beq	3	1	2	if reg1's value is 10, go to done
	add	1	4	1	increase reg1's value
	beq	0	0	start	go to start
done	halt				end of the program
zero	.fill	0
result	.fill	0
ten	.fill	10
one	.fill	1

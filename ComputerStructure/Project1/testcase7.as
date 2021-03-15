	lw	0	1	zero	load 0 to reg1
	lw	0	2	two	load 2 to reg2
	lw	0	3	12	load 10 to reg3
	lw	0	4	sum	load 0 to re4, it will use to final sum of even numbers smaller than ten
start	add	1	2	1	add 2 to reg1
	add	1	4	4	add reg1's value to reg4
	beq	1	3	2	if reg1's value is ten, go to done
	beq	0	0	start	go to start
	noop
done	halt				end of the program
zero	.fill	0
two	.fill	2
ten	.fill	10
sum	.fill	0

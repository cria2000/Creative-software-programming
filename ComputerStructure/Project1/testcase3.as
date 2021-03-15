	lw	0	1	five	load 5 to reg1
	lw	0	2	one	load 1 to reg2
	lw	0	3	24	load 1 to reg3
	lw	0	4 	result	load 0 to reg4 and it will be final result of fibo
	lw	0	5	two	load 2 to reg5
	lw	0	6	three	load 3 to reg6
	lw	0	7	one	load 1 to reg7
	beq	1	2	lwone	if reg1's value is 1, result is just one so go to lwone
	beq	1	5	11	if reg2's vale is 2, result is just two so go to lwtwo
start	beq	1	6	done 	if reg1's value and reg6's value are same, finish
	add	2	3	5	add n-1(reg2), n-2(reg3) and store it reg5(to calculate fibonacchi)	
	add	4	5	4	add reg5 to reg4(add to result)
	sw	0	3	28	store reg3's value to address 28
	sw	0	4	29	store reg4's value to address 29
	lw	0	2	28	load the value of address 28(previous reg3's value) to reg2
	lw	0	3	29	load the value of address 29(previous reg4's value) to reg3
	add	7	6	6	increase reg6's value
	beq	0	0	start	go back start
lwone	lw	0	4	one	if the value we have to calculate fibo is one, load one to reg4
	beq	0	0	done	go to done
lwtwo	lw	0	4	two	if the value we have to claculate fibo is two, load two to reg4
	beq	0	0	done	go to done
done	halt				finish the program
five	.fill	5			the value we have to calculate fibo
one	.fill	1
result	.fill	0
two	.fill	2
three	.fill	3

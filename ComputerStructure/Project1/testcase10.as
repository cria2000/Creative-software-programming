	lw	0	1	One	load reg1 with 1(using symbolic address) and this make error : undefined lable
	lw	1	2	11	load reg2 with 2(using numeric address)
	lw	2	3	11	load reg3 with 3(using numeric address)
	lw	0	4	four	load reg4 with 4(using symbolic address)
	add	1	2	1	add 1, 2 and store it to reg1
	add	3	4	3	add 3 ,4 and store it to reg3
start	beq	1	3	done	if reg1 and reg3 are equivalent, go to end of the program
	add	1	2	1	add 2 to reg1
	beq	0	0	-3	go back to the beginning of the program
	noop
done	halt				end of program
one	.fill	1
two	.fill	2
three	.fill	3
four	.fill	4

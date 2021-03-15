	lw	0	1	one	load 1 to reg1
	lw	0	2	65536	load 3 to reg2 and it make the error : offsetFields that don't fit in 16 bits
	nor	1	2	3	nor the reg1's value and reg3's value
	nor	3	3	4	store -1 to reg4
	add	1	3	3	increase reg3's value
	sw	0	4	one	change the value of one
	lw	0	1	one	load -1 to reg1
	noop
done 	halt				end of program
one	.fill	1
three	.fill	3

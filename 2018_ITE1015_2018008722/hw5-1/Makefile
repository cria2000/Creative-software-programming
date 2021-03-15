hw5-1: swap.o command_argument.o sort_int.o cmdarg.o
	g++ -o swap swap.o
	g++ -o command_argument command_argument.o
	g++ -o sort_int sort_int.o sort.cc
	g++ -o cmdarg cmdarg.o
swap.o: swap.cc
	g++ -c swap.cc
command_argument.o: command_argument.cc
	g++ -c command_argument.cc
sort_int.o: sort_int.cc
	g++ -c sort_int.cc
cmdarg.o: cmdarg.cc
	g++ -c cmdarg.cc
clean:
	rm swap.o command_argument.o sort_int.o cmdarg.o

hw12-1:myswap.o my_vector_main.o
	g++ -std=c++11 -o myswap myswap.o
	g++ -std=c++11 -o my_vector my_vector_main.o
myswap.o:myswap.cc
	g++ -c myswap.cc
my_vector_main.o:my_vector_main.cc my_vector.h
	g++ -c my_vector_main.cc
clean:
	rm myswap.o my_vector_main.o

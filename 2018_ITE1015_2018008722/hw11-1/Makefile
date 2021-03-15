hw11-1:my_vector_main.o my_string.o
	g++ -std=c++11 -o my_vector my_vector_main.o my_vector.cc
	g++ -std=c++11 -o my_string my_string_main.o my_string.cc
my_vetor_main.o:my_vector_main.cc
	g++ -c my_vector_main.cc
my_string.o:my_string_main.cc
	g++ -c my_string_main.cc
clean:
	rm my_vector_main.o my_string_main.o

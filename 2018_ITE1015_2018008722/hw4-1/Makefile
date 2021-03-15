hw4-1: string.o function_overloading.o circle_main.o dynamic_array.o
	g++ -o string string.o
	g++ -o function_overloading function_overloading.o
	g++ -o circle_main circle_main.o circle.cc
	g++ -o dynamic_array dynamic_array.o
string.o: string.cc
	g++ -c string.cc
function_overloading.o: function_overloading.cc
	g++ -c function_overloading.cc
circle_main.o: circle_main.cc
	g++ -c circle_main.cc
dynamic_array.o: dynamic_array.cc
	g++ -c dynamic_array.cc
clean:
	rm string.o function_overloading.o circle_main.o dynamic_array.o

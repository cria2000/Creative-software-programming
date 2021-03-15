hw10-1:class_function_main.o cast_quiz.o dynamic_cast_main.o shapes_main.o
	g++ -std=c++11 -o class_function class_function_main.o class_function.cc
	g++ -std=c++11 -o cast_quiz cast_quiz.o
	g++ -std=c++11 -o dynamic_cast dynamic_cast_main.o dynamic_cast.cc
	g++ -std=c++11 -o shapes shapes_main.o shapes.cc
class_function_main.o:class_function_main.cc
	g++ -c class_function_main.cc
cast_quiz.o:cast_quiz.cc
	g++ -c cast_quiz.cc
dynamic_cast_main.o:dynamic_cast_main.cc
	g++ -c dynamic_cast_main.cc
shapes_main.o:shapes_main.cc
	g++ -c shapes_main.cc
clean:
	rm class_function_main.o cast_quiz.o dynamic_cast_main.o shapes_main.o

hw9-2:animals_main.o draw_shape_main.o
	g++ -std=c++11 -o animals animals_main.o animals.cc
	g++ -std=c++11 -o draw_shape draw_shape_main.o draw_shape.cc
animals_main.o:animals_main.cc
	g++ -c animals_main.cc
draw_shape_main.o:draw_shape_main.cc
	g++ -c draw_shape_main.cc
clean:
	rm animals_main.o draw_shape_main.o

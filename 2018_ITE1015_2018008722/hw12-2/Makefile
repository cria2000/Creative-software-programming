hw12-2:simply_linked_list_main.o my_shared_ptr_main.o
	g++ -std=c++11 -o simply_linked_list simply_linked_list_main.o
	g++ -std=c++11 -o my_shared_ptr my_shared_ptr_main.o
simply_linked_list_main.o:simply_linked_list_main.cc
	g++ -c simply_linked_list_main.cc
my_shared_ptr_main.o:my_shared_ptr_main.cc
	g++ -c my_shared_ptr_main.cc
clean:
	rm simply_linked_list_main.o my_shared_ptr_main.o

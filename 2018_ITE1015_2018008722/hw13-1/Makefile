hw13-1: bad_allocation.o object_copy.o chained_handler.o
	g++ -o bad_allocation bad_allocation.o 
	g++ -o object_copy object_copy.o
	g++ -o chained_handler chained_handler.o
bad_allocation.o:bad_allocation.cc
	g++ -c bad_allocation.cc
object_copy.o:object_copy.cc
	g++ -c object_copy.cc
chained_handler.o:chained_handler.cc
	g++ -c chained_handler.cc
clean:
	rm bad_allocation.o object_copy.o chained_handler.o

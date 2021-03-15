hw9-1:classes_main.o print_info_main.o print_member_main.o
	g++ -std=c++11 -o classes classes_main.o classes.cc
	g++ -std=c++11 -o print_info print_info_main.o print_info.cc
	g++ -std=c++11 -o print_member print_member_main.o print_member.cc
classes_main.o:classes_main.cc
	g++ -c classes_main.cc
print_info_main.o:print_info_main.cc
	g++ -c print_info_main.cc
print_member_main.o:print_member_main.cc
	g++ -c print_member_main.cc
clean:
	rm classes_main.o print_info_main.o print_member_main.o

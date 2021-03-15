hw11-2:world_clock_main.o calendar_main.o
	g++ -o world_clock world_clock_main.o world_clock.cc
	g++ -o calendar calendar_main.o calendar.cc
world_clock_main.o:world_clock_main.cc
	g++ -c world_clock_main.cc
calendar_main.o:calendar_main.cc
	g++ -c calendar_main.cc
clean:
	rm world_clock_main.o calendar_main.o

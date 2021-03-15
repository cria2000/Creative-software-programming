#include<iostream>
#include<vector>
#include"clock_time.h"
using namespace std;
int main(){
	std::vector<Clock*> clocks;
	int second;
	cin>>second;
	clocks.push_back(new SundialClock(0,0,0));
	clocks.push_back(new CuckooClock(0,0,0));
	clocks.push_back(new GrandFatherClock(0,0,0));
	clocks.push_back(new WristClock(0,0,0));
	clocks.push_back(new AtomicClock(0,0,0));
	for(Clock *clock : clocks) clock->reset();
	cout<<"Reported clock times after resetting:"<<endl;
	for(Clock *clock : clocks) clock->displayTime();
	cout<<endl<<"Running the clocks..."<<endl<<endl;
	for(Clock *clock : clocks){
		for(int i=0;i<second;i++){
			clock->tick();}
	}
	cout<<"Reported clock times after running:"<<endl;
	for(Clock *clock : clocks) clock->displayTime();
	for(Clock *clock : clocks) delete clock;
}





	


#include<iostream>
#include"world_clock.h"
using namespace std;
int main(){
	WorldClock clock;
	clock.SetTime(0,0,0);
	string ans;
	while(true){
	cin>>ans;
	if(ans=="set"){
		cin>>clock;
		if(clock.SetTime(clock.hour(), clock.minute(),clock.second())==true)
			cout<<clock;
	}
	else if(ans=="tick"){
		int sec;
		cin>>sec;
		clock.Tick(sec);
		cout<<clock;
	}
	else if(ans=="quit") return 0;


	}

	

}

#include<iostream>
#include"calendar.h"
using namespace std;
int main(){
	Date date(0,1,1);
	string ans;
	while(true){
		cin>>ans;
		if(ans=="set"){
			cin>>date;
			if(date.SetDate(date.year(),date.month(), date.day())==true)
				cout<<date;
		}
		else if(ans=="next"){
			string days;
			cin>>days;
			if(days=="day") date.NextDay();
			else date.NextDay(atoi(days.c_str()));
			cout<<date;
		}
		else if(ans=="quit") return 0;
	}
}


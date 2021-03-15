#include<iostream>
#include"world_clock.h"
#include<string>
using namespace std;
void WorldClock::Tick(int seconds){
	int total=_hour*3600+_minute*60+_second;
	total=total+seconds;
	if(total<0) total=total+86400;
	else if(total>86400) total=total-86400;
	_hour=total/3600;
	_minute=(total-(3600*_hour))/60;
	_second=(total-(3600*_hour)-(60*_minute));

}
bool WorldClock::SetTime(int hour, int minute, int second){
	if(hour>23||hour<0) return false;
	else if(minute>59||minute<0) return false;
	else if(second>59||second<0) return false;
	else{
		_hour=hour;
		_minute=minute;
		_second=second;
		return true;
	}
}
int WorldClock::hour() const{
	return _hour;
}
int WorldClock::minute() const{
	return _minute;
}
int WorldClock::second() const{
	return _second;
}
string *split(string& str, const string& delim){
	string *string_list=new string[10];
	for(int i=0;i<10;i++){
		string_list[i]="";
	}
	size_t prev=0, pos=0;
	int idx=0;
	do{
		pos=str.find_first_of(delim, prev+1);
		string_list[idx]=str.substr(prev, pos-prev);
		prev=pos+1;
		++idx;
	}
	while(pos!=string::npos);
	return string_list;
}
ostream& operator<<(ostream& os, const WorldClock& c){
	os<<c.hour()<<":"<<c.minute()<<":"<<c.second()<<endl;
	return os;
}
istream& operator>>(istream& is, WorldClock& c){
	string time;
	int hour, minute, second;
	is>>time;
	string* items=split(time, ":");
	hour=atoi(items[0].c_str());
	minute=atoi(items[1].c_str());
	second=atoi(items[2].c_str());
	if(c.SetTime(hour, minute, second)==false)
		cout<<"Invalid time: "<<time<<endl;
	return is;
}

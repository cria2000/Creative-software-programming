#include<iostream>
#include"calendar.h"
#include<string.h>
using namespace std;
Date::Date(){
	year_=0;
	month_=0;
	day_=0;
}
Date::Date(int year, int month, int day){
	year_=year;
	month_=month;
	day_=day;
}

void Date::NextDay(int n){
	int days=ComputeDaysFromYearStart(year_, month_, day_);
	days=days+n;
	int year_day=GetDaysInYear(year_);
	if(days<0||days==0){
		year_=year_-1;
		days=days+year_day;
	}
	else if(days>year_day){
		year_=year_+1;
		days=days-year_day;
	}
	month_=1;
	for(int i=1;i<12;i++){
		if(days>0){
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
				month_=month_+1;
				days=days-31;
			}
			else if(i==4||i==6||i==9||i==11){
				month_=month_+1;
				days=days-30;
			}
			else if(i==2){
				if(year_day==365){
					month_=month_+1;
					days=days-28;
				}
				else if(year_day==366){
					month_=month_+1;
					days=days-29;
				}
			}
		day_=days;
		}
		else if(days<0||days==0){
			month_=month_-1;
			if(i-1==1||i-1==3||i-1==5||i-1==7||i-1==8||i-1==10||i-1==12) day_=days+31;
			else if(i-1==4||i-1==6||i-1==9||i-1==11) day_=days+30;
			else if(i-1==2){
				if(year_day==365) day_=days+28;
				else if(year_day==366) day_=days+29;
			}
			break;
		}

	}
}
bool Date::SetDate(int year, int month, int day){
	if(month>13||month<1){
	       return false;
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day>31||day<1){
			return false;
		}
	}
	else if(month==4||month==6||month==9||month==11){
		if(day>30||day<1){
			return false;
		}
	}
	else if(month==2){
		if(year%4==0&&year%100!=0){
			if(day>29||day<1){
				return false;
			}
		}
		else if(year%100==0&&year%400!=0){
			if(day>28||day<1){
				return false;
			}
		}
		else if(year%100==0&&year%400==0){
			if(day>29||day<1){
				return false;
			}
		}
		else{ 
			if(day>28||day<1){
		       	       return false;
			}
		}
	}
	year_=year;
	month_=month;
	day_=day;
	return true;
	
}

int Date::year() const{
	return year_;
}
int Date::month() const{
	return month_;
}
int Date::day() const{
	return day_;
}
int Date::GetDaysInYear(int year){
	if(year%4==0&&year%100!=0) return 366;
	else if(year%100==0&&year%400==0) return 366;
	else if(year%100==0&&year%400!=0) return 365;
	else return 365;
}
int Date::ComputeDaysFromYearStart(int year, int month, int day){
	int total=0;
	if(year%4==0&&year%100!=0){
		for(int i=1;i<month;i++){
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) total=total+31;
			else if(i==4||i==6||i==9||i==11) total=total+30;
			else if(i==2) total=total+29;
		}
		total=total+day;
		return total;
		}
	
	else if(year%100==0){
		if(year%400==0){
			for(int i=1;i<month;i++){
				if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) total=total+31;
				else if(i==4||i==6||i==9||i==11) total=total+30;
				else if(i==2) total=total+29;
			}
			total=total+day;
			return total;
			
		}
		else{
			for(int i=1;i<month;i++){
				if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) total=total+31;
				else if(i==4||i==6||i==9||i==11) total=total+30;
				else if(i==2) total=total+28;
			}
			total=total+day;
			return total;
		}	
	}
	else{
		for(int i=1;i<month;i++){
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) total=total+31;
			else if(i==4||i==6||i==9||i==11) total=total+30;
			else if(i==2) total=total+28;
		}
		total=total+day;
		return total;
	}
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

ostream& operator<<(ostream& os, const Date& c){
	os<<c.year()<<"."<<c.month()<<"."<<c.day()<<endl;
	return os;
}
istream& operator>>(istream& is, Date& c){
	string date;
	int year, month, day;
        is>>date;
        string* items=split(date, ".");
        year=atoi(items[0].c_str());
        month=atoi(items[1].c_str());
        day=atoi(items[2].c_str());

//	char *ptr=strtok(a,".");
//	for(int i=0;i<3;i++){
//		while(ptr!=NULL)
//		{
//			if(i==0) year=atoi(a);
//			else if(i==1) month=atoi(a);
///			else if(i==2) day=atoi(a);
//			ptr=strtok(NULL,".");
//		}}
//	cout<<year<<month<<day<<endl;

	if(c.SetDate(year, month, day)==false)
		cout<<"Invalid date: "<<date<<endl;
	return is;
}






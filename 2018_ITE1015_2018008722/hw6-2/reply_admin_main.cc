#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"reply_admin.h"
using namespace std;
int* split(string& str,const string& delim){
	int *list=new int[10];
	for(int i=0;i<10;++i){
		list[i]=-1;
	}
	size_t prev=0,pos=0;
	int idx=0;
	do{
		pos=str.find_first_of(delim,prev+1);
		string s=str.substr(prev,pos-prev);
		list[idx]=atoi(s.c_str());
		prev=pos+1;
		++idx;
	}
	while(pos!=string::npos);
	return list;
}
string* split_(string& str,const string& delim){
	string *list=new string[10];
	for(int i=0;i<10;++i){
		list[i]="";}
	size_t prev=0,pos=0;
	int idx=0;
	do{
		pos=str.find_first_of(delim,prev+1);
		list[idx]=str.substr(prev,pos-prev);
		prev=pos+1;
		++idx;}
	while(pos!=string::npos);
	return list;
}
int main(){
	ReplyAdmin ad;
	ReplyAdmin();
	string ans;
	string ans2;
	int *line;
	string *line2;
	int num;
	while(1){
		getline(cin,ans);
		if((ans.find("remove"))!=string::npos){
			if((ans.find(","))!=string::npos){
				line2=split_(ans," ");
				line=split(line2[1],",");
				num=0;
				for(int j=0;j<10;j++){
					if(line[j]!=-1){
						num=num+1;}
				}
				if((ad.removeChat(line,num))!=false){
					for(int n=0;n<ad.getChatCount();n++){
						ad.printChat(n);}}
				else{
					cout<<"Error!"<<endl;}}
			else if((ans.find("-"))!=string::npos){
				line2=split_(ans," ");
				line=split(line2[1],"-");
				if(ad.removeChat(line[0],line[1])!=false){
					for(int m=0;m<ad.getChatCount();m++){
						ad.printChat(m);}}
				else{
					cout<<"Error!"<<endl;}
			}
			else{
				if(ad.removeChat(atoi(&ans[8]))!=false){
					for(int p=0;p<ad.getChatCount();p++){
						ad.printChat(p);}}
				else{
					cout<<"Error!"<<endl;}}}
		else if(ans=="#quit"){
			return 0;}
		else{
			if(ad.addChat(ans)!=false){
				for(int q=0;q<(ad.getChatCount());q++){
					ad.printChat(q);}}
			else{
				cout<<"Error!"<<endl;}
		}}
	ad.~ReplyAdmin();

}

				



	


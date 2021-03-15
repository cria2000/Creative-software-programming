#include<iostream>
#include"reply_admin.h"
#include<string.h>
#include<stdlib.h>
using namespace std;
char **split(char *str,const char *delim){
	char **string_list=(char**)malloc(10*sizeof(char*));
	for(int i=0;i<10;i++){
		string_list[i]=NULL;}
	int idx=0;
	char *token=strtok(str,delim);
	while(token!=NULL){
		string_list[idx]=(char *)malloc(strlen(token)+1);
		strcpy(string_list[idx],token);
		token=strtok(NULL,delim);
		++idx;}
	return string_list;}
int main(){
	ReplyAdmin ad;                                                                        
	ReplyAdmin();
	string ans;
	char ans1;
	char **line;
	int num;
	while(1){
		getline(cin,ans);
	if((ans.find("remove");)!=string::npos){
		if((ans.find(",");)!=string::npos){
			strcpy(&ans1,ans.c_str());
			line=split(&ans1,",");
			for(int j=0;j<10;j++){
				if(line[j]!=NULL){
					j=j+1;}
				else{
					num=j;}
			}
			if((ad.removeChat((atoi(*line);),num);)!=false){
			for(int n=0;n<ad.getChatCount();n++){
				ad.printChat(n);}}
			else{
				cout<<"Error!"<<endl;}}

		else if((ans.find("-");)!string::npos){
			strcpy(&ans1,ans.c_str());
			line=split(&ans1,"-");
			if((ad.removeChat((atoi(line[0]);),(atoi(line[1]);));)!=false){
				for(int m=0;m<ad.getChatCount();m++){
					ad.printChat(m);}}
			else{
				cout<<"Error!"<<endl;}
		}
		else if{
			if(ad.removeChat(atoi(ans[7]););!=false){
				for(int p=0;p<ad.getChatCount();p++){
					ad.printChat(p);}}
			else{
				cout<<"Error!"<<endl;}}}
	else if(ans=="#quit"){
		return 0;}


	else{
		ad.addChat(ans);}}}
		



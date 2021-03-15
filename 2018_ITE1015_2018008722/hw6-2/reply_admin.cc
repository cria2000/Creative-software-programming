#include<iostream>
#include"reply_admin.h"
#include<stdlib.h>
#include<string.h>
using namespace std;
int ReplyAdmin::getChatCount(){
	if(chats[9]!="0"){
		return 10;}
	for(int i=0;i<10;i++){
		if(chats[i]=="0"){
			return i;}}}
bool ReplyAdmin::addChat(string _chat){
	if(chats[9]!="0"){
		return false;}
	for(int i=0;i<10;i++){
		if(chats[i]=="0"){
			chats[i]=_chat;
			return true;}
	}}
bool ReplyAdmin::removeChat(int _index){
	int num;
	num=getChatCount();
	if(num<_index){
		return false;}
	else{
		chats[_index].clear();
		for(int i=_index;i<9;i++){
			chats[i]=chats[i+1];
		}
		chats[9]="0";
		return true;
	}
}
bool ReplyAdmin::removeChat(int* _indices,int _count){
	int num;
	num=getChatCount();
	int j=0;
	string* chats2;
	for(int i=0;i<_count;i++){
		if(_indices[i]<num){
			j=j+1;
			chats[(_indices[i])].clear();
			chats[(_indices[i])]="0";}
}
	for(int k=0;k<9;k++){
		for(int p=0;p<9;p++){
		if(chats[p]=="0"){
			chats[p].swap(chats[p+1]);}}}
	if(j==0){
		return false;}
	else{
		return true;}
}
bool ReplyAdmin::removeChat(int _start,int _end){
	int num;
	num=getChatCount();
	int j=0;
	for(int i=_start;i<_end+1;i++){
		if(i<num){
			j=j+1;
			chats[i].clear();
			chats[i]="0";
		}}
	for(int k=0;k<9;k++){
		for(int p=0;p<9;p++){
			if(chats[p]=="0"){
				chats[p].swap(chats[p+1]);}}}

	if(j==0){
		return false;}
	else{
		return true;}}


int ReplyAdmin::printChat(int num){
	cout<<num<<" "<<chats[num]<<endl;}
	



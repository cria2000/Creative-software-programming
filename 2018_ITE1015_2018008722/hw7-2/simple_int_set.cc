#include<iostream>
#include"simple_int_set.h"
using namespace std;
set<int> SetUnion(const set<int>& set0, const set<int>& set1){
	set<int> com_set;
	com_set.clear();
	set<int>::iterator iter0;
	set<int>::iterator iter1;
	iter0=set0.begin();
	iter1=set1.begin();
	while(iter0!=set0.end()&&iter1!=set1.end()){
		if(*iter0==*iter1){
			com_set.insert(*iter0);
			++iter0;	
			++iter1;
		}
				
		else{
			if(*iter0<*iter1){
				com_set.insert(*iter0);
				++iter0;
			}

			else{
				com_set.insert(*iter1);
				++iter1;
			}}}
	
	if(iter0==set0.end()){
		while(iter1!=set1.end()){
			com_set.insert(*iter1);
			++iter1;}
	}
	else{
		while(iter0!=set0.end()){
			com_set.insert(*iter0);
			++iter0;}}
	return com_set;
}

set<int> SetIntersection(const set<int>& set0, const set<int>& set1){
	set<int> com_set;
	set<int>::iterator iter0;
	set<int>::iterator iter1;
	iter0=set0.begin();
	iter1=set1.begin();
	for(iter0=set0.begin();iter0!=set0.end();++iter0){
		for(iter1=set1.begin();iter1!=set1.end();++iter1){
			if((*iter0)==(*iter1)) com_set.insert(*iter0);}}
//	while(iter0!=set0.end()&&iter1!=set1.end()){
//		if(*iter0==*iter1){
//			com_set.insert(*iter0);
//			++iter0;
//			++iter1;}
//		else{
//			if(*iter0<*iter1){
//				++iter0;}
//			else{
//				++iter1;}}}
	return com_set;
}
set<int> SetDifference(const set<int>& set0, const set<int>& set1){
	set<int> com_set;
	set<int>::iterator iter0=set0.begin();
	set<int>::iterator iter1=set1.begin();
	while(iter0!=set0.end()&&iter1!=set1.end()){
		if(*iter0==*iter1){
			++iter0; ++iter1;}
		else{
			if(*iter0<*iter1){
				com_set.insert(*iter0);
				++iter0;}
			else ++iter1;
		}}
	if(iter1==set1.end()){
		for(iter0;iter0!=set0.end();++iter0) com_set.insert(*iter0);
	}
	
		return com_set;

}


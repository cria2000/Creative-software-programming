#include<iostream>
#include"minimal_fighter.h"
using namespace std;
int main(){
	while(1){
		int HP1,Power1,HP2,Power2;
		char answer;
		cin>>HP1>>Power1>>answer>>HP2>>Power2;
		if(cin.fail())
			return 0;
		MinimalFighter *F1=new MinimalFighter(HP1,Power1);
		MinimalFighter *F2=new MinimalFighter(HP2,Power2);
		if(answer=='H')
			F1->hit(F2);
		else if(answer=='A')
			F1->attack(F2);
		else if(answer=='F')
			F1->fight(F2);
		else if(answer!='A'&&answer!='H'&&answer!='F')  return 0;
		if(F1->status()==Dead&&F2->status()==Dead)
			cout<<"DEAD / DEAD"<<endl;
		else if(F1->status()==Dead)
			cout<<"DEAD / "<<"H"<<F2->hp()<<", P"<<F2->power()<<endl;
		else if(F2->status()==Dead)
			cout<<"H"<<F1->hp()<<", P"<<F1->power()<<" / DEAD"<<endl;
		else
			cout<<"H"<<F1->hp()<<", P"<<F1->power()<<" / H"<<F2->hp()<<", P"<<F2->power()<<endl;
		delete F1;
		delete F2;
	}}

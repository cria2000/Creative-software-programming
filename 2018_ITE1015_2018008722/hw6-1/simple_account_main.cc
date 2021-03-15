#include<iostream>
#include"simple_account.h"
using namespace std;
int main(){
	string acc;
	int amount;
	int num;
	int num_t;
	Account_admin ad;
	ad.account_num=0;
	while(1){
		cout<<"Job?"<<endl;
		cin>>acc;
		if(acc=="N"){
			if(ad.account_num<10){
			cout<<"Account for user "<<ad.account_num<<" registered"<<endl;
			ad.a[ad.account_num].id=ad.account_num;
			ad.a[ad.account_num].balance=0;
			ad.check_balance(ad.account_num);
			ad.account_num=ad.account_num+1;
			}

			else{
				cout<<"The account has failed to open : There are more than 10 accounts"<<endl;}
		}
		else if(acc=="D"){
			cin>>num>>amount;
			if((ad.account_num-1)<num){
				cout<<"Account does not exist"<<endl;}
			else{
				ad.deposit(num,amount);
				ad.check_balance(num);}
		}
		else if(acc=="W"){
			cin>>num>>amount;
			if(ad.account_num-1<num){
				cout<<"Account does not exist"<<endl;}
			else{
				ad.withdraw(num,amount);
				ad.check_balance(num);}
		}
		else if(acc=="T"){
			cin>>num>>num_t>>amount;
			if((ad.account_num-1<num)||(ad.account_num-1<num_t)){
				cout<<"Account does not exist"<<endl;}
			else{
				ad.transfer(num,num_t,amount);
				if(num>num_t){
					ad.check_balance(num_t);
					ad.check_balance(num);}
				else{
					ad.check_balance(num);
					ad.check_balance(num_t);}

		}}
		else if(acc=="Q"){
			return 0;}}}

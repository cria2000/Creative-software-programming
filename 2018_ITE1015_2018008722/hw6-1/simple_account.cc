#include<iostream>
#include"simple_account.h"
void Account_admin::deposit(int num, int amount){
	if(a[num].balance+amount>1000000){
		std::cout<<"Failure: Deposit to user "<<a[num].id<<" "<<amount<<std::endl;}
	else if(a[num].balance+amount<0){
		std::cout<<"Failure: Deposit to user "<<a[num].id<<" "<<amount<<std::endl;}
	else{
		std::cout<<"Success: Deposit to user "<<a[num].id<<" "<<amount<<std::endl;
		a[num].balance=a[num].balance+amount;}}
void Account_admin::withdraw(int num, int amount){
	if(a[num].balance-amount<0||a[num].balance-amount>1000000){
		std::cout<<"Faliure: Withdraw from user "<<a[num].id<<" "<<amount<<std::endl;}
	else{
		std::cout<<"Success: Withdraw from user "<<a[num].id<<" "<<amount<<std::endl;
		a[num].balance=a[num].balance-amount;}}
void Account_admin::transfer(int num,int num_t,int amount){
	if(a[num].balance-amount>1000000||a[num].balance-amount<0||a[num_t].balance+amount>1000000||a[num_t].balance+amount<0){
		std::cout<<"Failure: Transfer from user "<<a[num].id<<" to user "<<a[num_t].id<<" "<<amount<<std::endl;}
	else{
		std::cout<<"success: Transfer from user "<<a[num].id<<" to uer "<<a[num_t].id<<" "<<amount<<std::endl;
	a[num].balance=a[num].balance-amount;
	a[num_t].balance=a[num_t].balance+amount;}}
void Account_admin::check_balance(int num){
	std::cout<<"Balance of user "<<a[num].id<<": "<<a[num].balance<<std::endl;}


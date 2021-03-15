#include<istream>
#include"minimal_fighter.h"
using namespace std;
int MinimalFighter::hp()const{
	return mHp;}
int MinimalFighter::power()const{
	return mPower;}
FighterStatus MinimalFighter::status()const{
	return mStatus;}
void MinimalFighter::setHp(int _hp){
	mHp=_hp;}
void MinimalFighter::hit(MinimalFighter *_enemy){
	if(mHp>0&&_enemy->mHp>0){
	_enemy->setHp(_enemy->mHp-mPower);
	setHp(mHp-_enemy->mPower);
	if(mHp==0||mHp<0) mStatus=Dead;
	if(_enemy->mHp==0||_enemy->mHp<0) _enemy->mStatus=Dead;
	}
	else cout<<"One or teo fighters is already dead. Can't fight."<<endl;
}
void MinimalFighter::attack(MinimalFighter *_target){
	if(mHp>0&&_target->mHp>0){
	_target->setHp(_target->mHp-mPower);
	mPower=0;
	if(_target->mHp==0||_target->mHp<0) _target->mStatus=Dead;}
	else cout<<"One or two fighters is already dead. Can't fight."<<endl;
}
void MinimalFighter::fight(MinimalFighter *_enemy){
	if(mHp>0&&_enemy->mHp>0) {

	while(mHp>0&&_enemy->mHp>0){
		_enemy->setHp(_enemy->mHp-mPower);
		setHp(mHp-_enemy->mPower);
	}

	if(mHp==0||mHp<0){
		mStatus=Dead;
		if(_enemy->mHp==0||_enemy->mHp<0){
			_enemy->mStatus=Dead;}
	}
	else if(_enemy->mHp==0||_enemy->mHp<0){
		_enemy->mStatus=Dead;
		if(mHp==0||mHp<0){
			mStatus=Dead;}}
	}	
	else cout<<"One or two fighters is already dead. Can't fight."<<endl;

}



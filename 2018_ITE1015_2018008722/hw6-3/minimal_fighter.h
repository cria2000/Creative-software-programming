#include<iostream>
using namespace std;
typedef enum{Invalid, Alive, Dead}FighterStatus;
class MinimalFighter{
	private:
		int mHp;
		int mPower;
		FighterStatus mStatus;
	public:
		MinimalFighter(){
			mHp=0;mPower=0;mStatus=Invalid;}
		MinimalFighter(int _hp,int _power){
			mHp=_hp; mPower=_power; 
			if(_hp>0)mStatus=Alive;
			else mStatus=Dead;}
		int hp() const;
		int power() const;
		FighterStatus status() const;
		void setHp(int _hp);
		void hit(MinimalFighter *_enemy);
		void attack(MinimalFighter *_target);
		void fight(MinimalFighter *_enemy);
};

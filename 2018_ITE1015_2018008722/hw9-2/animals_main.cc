#include<iostream>
#include<vector>
#include"animals.h"
using namespace std;
int main(){
	string animal;
	string name;
	int age;
	int numstripe;
	string favoritetoy;
	std::vector<Animal*> animals;
	while(true){
		cin>>animal;
		if (animal=="z"){
			cin>>name>>age>>numstripe;
			animals.push_back(new Zebra(name,age,numstripe));
		}
		else if(animal=="c"){
			cin>>name>>age>>favoritetoy;
			animals.push_back(new Cat(name, age, favoritetoy));
		}
		else if(animal=="0"){
			for(Animal *animal : animals) animal->printInfo();
			for(Animal *animal : animals) delete animal;
			return 0;
		}
	}}

		


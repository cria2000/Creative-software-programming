#include<vector>
#include "classes.h"
using namespace std;

int main(){
	vector<A*> objects;

	objects.push_back(new A);
	objects.push_back(new B);
	objects.push_back(new C);

	for (A *object : objects) object->test();
	for (A *object : objects) delete object;
	return 0;
}

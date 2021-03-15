#include <iostream>
#include "my_shared_ptr.h"

using namespace std;

int main() {
	{
		My_shared_ptr<unsigned long> a;
		cout << a.getCount() << endl;
		{
			My_shared_ptr<unsigned long> b(new unsigned long(5));
			cout << a.getCount() << endl;
			cout << b.getCount() << endl;

			if (a.get_m_obj() == b.get_m_obj())
				cout << "resource shared" << endl;

			a = b;
			cout << a.getCount() << endl;
			cout << b.getCount() << endl;

			if (a.get_m_obj() == b.get_m_obj())
				cout << "resource shared" << endl;
		}
		cout << a.getCount() << endl;
	}

	return 0;
}

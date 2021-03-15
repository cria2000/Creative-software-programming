#include <iostream>
#include <vector>
#include <string>
#include "simply_linked_list.h"

using namespace std;

template <class T>
static int run(vector<List<T>* >& vec) {
	string cmd, pos;
	int lid;
	T item;

	while (true) {
		cin >> cmd;

		if (cmd == "quit") {
			break;
		} else if (cmd == "dump") {
			int tid = 0;
			for (auto list : vec)
				cout << tid++ << ", " << list->size() << endl;
		} else if (cmd == "new") {
			vec.push_back(new List<T>);
		} else if (cmd == "show") {
			cin >> lid;
			try {
				cout << *(vec.at(lid)) << endl;
			} catch (out_of_range& e) {
			}
		} else if (cmd == "insert") {
			cin >> lid >> pos >> item;
			try {
				List<T> *list = vec.at(lid);
				(pos == "front") ? list->push_front(item) : (pos == "back") ? list->push_back(item) : list->insert_at(stoi(pos), item);
			} catch (out_of_range& e) {
			}
		} else if (cmd == "remove") {
			cin >> lid >> pos;
			try {
				List<T> *list = vec.at(lid);
				(pos == "front") ? list->pop_front() : (pos == "back") ? list->pop_back() : list->remove_at(stoi(pos));
			} catch (out_of_range& e) {
			}
		} else if (cmd == "copy") {
			int lid2;
			cin >> lid >> lid2;
			try {
				List<T> *first = vec.at(lid), *second = vec.at(lid2);
				*second = *first;
			} catch (out_of_range& e) {
			}
		}
	}

	return 0;
}

int main() {
	vector<List<int>* > int_vec;
	vector<List<double>* > double_vec;
	vector<List<string>* > string_vec;

	string vtype;
	cin >> vtype;

	return (vtype == "int") ? run(int_vec) : (vtype == "double") ? run(double_vec) : run(string_vec);
}

#include <iostream>
#include <string>
#include <vector>
#include "my_vector.h"

using namespace std;

template <class T>
void print_vector(const MyVector<T>* v) {
	if (v->size() > 0) {
		cout << v->at(0);
		for (int i = 1; i < v->size(); ++i) cout << ", " << v->at(i);
		cout << endl;
	}
}

template <class T>
int run(vector<MyVector<T>* >& vectors) {
	string cmd;
	int vid;

	while (true) {
		cin >> cmd;

		if (cmd == "quit") {
			break;
		} else if (cmd == "new") {
			int capacity;
			cin >> capacity;

			vectors.push_back(new MyVector<T>(capacity));
		} else if (cmd == "dump") {
			int tvid = 0;
			for (auto& v : vectors) {
				cout << tvid++ << ", " << v->size() << ", " << v->max_size() << endl;
			}
		} else if (cmd == "add") {
			T new_item;
			cin >> vid >> new_item;

			vectors.at(vid)->push_back(new_item);
			print_vector(vectors.at(vid));
		} else if (cmd == "pop") {
			cin >> vid;

			vectors.at(vid)->pop_back();
			print_vector(vectors.at(vid));
		} else if (cmd == "clear") {
			cin >> vid;
			vectors.at(vid)->clear();
			print_vector(vectors.at(vid));
		} else if (cmd == "join") {
			int vid2;
			cin >> vid >> vid2;

			auto new_vec = *(vectors.at(vid)) + *(vectors.at(vid2));
			print_vector(&new_vec);
		}
	}

	return 0;
}

int main() {
	string vtype;
	cin >> vtype;

	vector<MyVector<int>* > int_vectors;
	vector<MyVector<double>* > double_vectors;
	vector<MyVector<string>* > string_vectors;

	return (vtype == "int") ? run(int_vectors) : (vtype == "double") ? run(double_vectors) : run(string_vectors);
}

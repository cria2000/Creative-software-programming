#include<iostream>
using namespace std;

int data_size=5;
class A{
	public:
		A(){
			data=new int[data_size];
			for(int i=0;i<data_size;++i)
				data[i]=i;
			cout<<"constructed"<<endl;
		}
		A(A &a){
			data=new int[data_size];
			for(int i=0;i<data_size;++i)
				data[i]=a.data[i];
		}
		~A(){
			for(int i=0;i<data_size;++i)
				data[i]=0;
			delete[] data;
			data=nullptr;
			cout<<"destroyed"<<endl;
		}
		friend ostream& operator<<(ostream& out, const A& a);
	private:
		int *data;
};
ostream& operator<<(ostream& out, const A& a){
	for(int i=0;i<data_size;++i)
		out<<a.data[i]<<" ";
	return out;
}
int main(){
	try{
		A a;
		cout<<a<<endl;
		throw a;
	}catch (A& a){
		cout<<"err. handled"<<endl;
		cout<<a<<endl;
	}
	return 0;
}


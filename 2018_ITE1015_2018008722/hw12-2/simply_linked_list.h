#include<iostream>
using namespace std;
template <class T>
class Node{
	public:
		Node():next(nullptr){}
		Node(T t):data(t),next(nullptr){}

		T data;
		Node<T> *next;
};
template <class T>
class List {
	public:
		List():head(nullptr){};
		List(T *arr, int n){
			for(int i=0;i<n;i++){
				Node<T> *new_nod=new Node<T>(arr[i]);
				Node<T> *temp=new Node<T>;
				temp=this->head;
				while(temp->next!=nullptr){
					temp=temp->next;
				}
				temp->next=new_nod;
				new_nod->next=nullptr;
				delete temp;
			}
		}		
		~List(){
			for(int i=1;i<size();i++){
				Node<T> *temp=new Node<T>;
				temp=this->head;
				while(temp->next!=nullptr)
					temp=temp->next;
				delete temp;
			}
			delete this->head; 
		};

		List<T>& operator=(const List<T>&rhs){
			List<T> &new_list=*(this);
			Node<T> *temp=rhs.head;
			while(temp!=nullptr){
				new_list.push_back(temp->data);
				temp=temp->next;
				
			}
			return new_list;
		}

		int size()const{		
			int num=0;
			Node<T>* temp=head;
			while(temp!=nullptr){
				temp=temp->next;
				num+=1;
			}
			delete temp;
			return num;
		}

		void insert_at(int idx, T& data){
			if(idx==0) push_front(data);
			else if(idx>size()){}
			else{
				Node<T> *current=new Node<T>;
			current=this->head;
			for(int i=0;i<idx-1;i++){
				current=current->next;
			}
			Node<T> *new_nod=new Node<T>(data);
			

			new_nod->next=current->next;
			current->next=new_nod;
			}
		}
		void remove_at(int idx){
			Node<T> *temp1=head;
			Node<T> *temp2;
			Node<T> *temp3;
			if(idx>size()){}
			else if(idx==0) pop_front();
			else if(idx!=0&&idx){
				for(int i=0;i<idx-1;i++){
					temp1=temp1->next;
				}
				temp2=temp1->next;
				temp3=temp2->next;
				temp1->next=temp3;
			}
			delete temp2;
		}
		
		void push_back(T& data){
			Node<T>* new_nod=new Node<T>(data);
			Node<T>* temp=head;
			if(head==nullptr)
				this->head=new_nod;
			else if(temp!=nullptr){
				while(temp->next!=nullptr){
				temp=temp->next;
				}
				new_nod->next=temp->next;
				temp->next=new_nod;
			}
		}
		void pop_back(){
			Node<T> *temp=this->head;
			if(head==nullptr){}
			else if(head!=nullptr){
				while(temp->next->next!=nullptr)
					temp=temp->next;
				delete temp->next;
				temp->next=nullptr;
			}
		}
		void push_front(T& data){
			Node<T> *new_nod=new Node<T>(data);
			Node<T> *temp=head;
			if(head==nullptr){
				head=new_nod;
				new_nod->next=nullptr;
			}
			
			else if(temp!=nullptr){
				this->head=new_nod;
				new_nod->next=temp;
			}
		}
		void pop_front(){
			Node<T> *temp;
			if(head==nullptr){}
			else if(head!=nullptr){
				temp=head->next;
				delete head;
				head=temp;
			}
		}

		friend std::ostream& operator<<(std::ostream& out, const List<T>& rhs){
			if(rhs.head==nullptr)return out;
			out<<rhs.head->data;
			Node<T> *current=new Node<T>;
			current=rhs.head;
			while(current!=NULL){
				current=current->next;
				if(current!=nullptr) cout<<", "<<current->data;
			
			}
			return out;
                }

	private:
		Node<T> *head;
};


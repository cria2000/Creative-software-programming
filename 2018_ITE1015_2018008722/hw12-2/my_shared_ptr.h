#include<iostream>
using namespace std;
template <class T>
class My_shared_ptr{
	public:
		My_shared_ptr():m_obj(nullptr), count(nullptr){}
		My_shared_ptr(T *obj){
			this->m_obj=obj;
			this->count=new int;
			*(this->count)=1;
		}
		My_shared_ptr(const My_shared_ptr& rhs){
			this->increase();
			rhs.m_obj=this->m_obj;
			rhs.count=this->count;
		}
		~My_shared_ptr(){
			if(this->count!=nullptr)
				this->decrease();
			if(this->getCount()==0) {
				std::cout<<"everything destroyed"<<std::endl;
				this->m_obj=nullptr;
				this->count=nullptr;
			}
		}
		My_shared_ptr<T>& operator=(const My_shared_ptr<T>& rhs){
			delete this->m_obj;
			delete this->count;
			this->m_obj=rhs.m_obj;
			this->count=rhs.count;
			this->increase();
			return *(this);
		}
		const T* get_m_obj(){
			return this->m_obj;
		}
		int getCount(){
			return (this->count==nullptr)?0:*(this->count);
		}

	private:
		void decrease(){
			*(this->count)=*(this->count)-1;
		}
		void increase(){
			*(this->count)=*(this->count)+1;
		}
		T* m_obj;
		int *count;
};






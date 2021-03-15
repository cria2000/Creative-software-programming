class A{
	public:
		virtual void test1();
		virtual void test2()=0;
		~A(){}
};
class B : public A{
	public:
		virtual void test2();
		~B(){}
};
class C : public A{
	public:
		virtual void test1();
		virtual void test2();
		~C(){}
};
class BB : public B{
	public:
		virtual void test1();
		~BB(){}
};

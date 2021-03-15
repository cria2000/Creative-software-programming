class A{
	public:
		A(int a);
		virtual ~A();
		virtual void print();
	private:
		int *memberA;
};
class B : public A{
	public:
		B(double b);
		virtual ~B();
		virtual void print();
	private:
		double *memberB;
};
class C : public B{
	public:
		C(std::string c);
		virtual ~C();
		virtual void print();
	private:
		std::string *memberC;
};

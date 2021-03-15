class A{
	public:
		virtual std::string getTypeInfo();
};
class B : public A{
	public:
		virtual std::string getTypeInfo();
};
class C : public B{
	public:
		virtual std::string getTypeInfo();
};


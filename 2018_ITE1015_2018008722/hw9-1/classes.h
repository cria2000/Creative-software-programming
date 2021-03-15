#ifndef __CLAASES_H__
#define __CLASSES_H__

class A{
	public:
		virtual void test();
};
class B : public A{
	public:
		virtual void test();
};
class C : public B{
	public:
		virtual void test();
};

#endif //__CALSSES_H__

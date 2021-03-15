using namespace std;
class Animal{
	public:
		Animal(string _name,int _age);
		virtual void printInfo();
		~Animal();
	protected:
		string name;
		int age;
};
class Zebra : public Animal{
	public:
		Zebra(string _name, int _age, int _numStripes);
		virtual void printInfo();
		~Zebra();
	private:
		int numStripes;
};
class Cat : public Animal{
	public:
		Cat(string _name, int _age, string _favoriteToy);
		virtual void printInfo();
		~Cat();
	private:
		string favoriteToy;
};



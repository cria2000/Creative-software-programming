using namespace std;
class MyVector
{
	private:
		int max_num;
		double* a;
	public:
		MyVector();
		MyVector(int _max_num);
		~MyVector();

		MyVector &operator=(const MyVector& b);

		MyVector operator+(const MyVector& b);
		MyVector operator-(const MyVector& b);
		MyVector operator+(const int b);
		MyVector operator-(const int b);
		friend ostream& operator<<(ostream& out, MyVector& b);
		friend istream& operator>>(istream& in, MyVector& b);
};


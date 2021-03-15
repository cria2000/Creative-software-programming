using namespace std;
class MyString
{
	private:
		int len;
		char* a;
	public:
		MyString();
		MyString(const MyString& my_string);
		~MyString();

		MyString& operator=(const MyString& b);

		MyString operator+(const MyString& b);
		MyString operator*(const int b);

		friend ostream& operator<<(ostream& out, MyString& my_string);
		friend istream& operator>>(istream& in, MyString& my_string);
};

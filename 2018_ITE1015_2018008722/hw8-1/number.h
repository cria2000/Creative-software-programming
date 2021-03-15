class Number
{
	protected:
		int _num;
	public:
		Number(){_num=0;};
		Number(int num){_num=num;};
		void setNumber(int num)
		{
			_num=num;}
		int getNumber(){
			return _num;}
};
class Square:public Number{
	public:
		int getSquare();
};
class Cube:public Square{
	public:
		int getCube();};

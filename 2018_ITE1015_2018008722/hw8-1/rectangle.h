using namespace std;
class Rectangle{
	public:
		Rectangle(int height, int width){_height=height; _width=width;};
		int getWidth() const;
		int getHeight() const;
		int getArea() const;
		int getPerimeter() const;
	private:
		int _height;
		int _width;};
class Square:public Rectangle{
	public:
		Square(int width):Rectangle(width,width){}
		void print() const;
};
class NonSquare:public Rectangle{
	public:
		NonSquare(int height,int width):Rectangle(height,width){}
		void print() const;};

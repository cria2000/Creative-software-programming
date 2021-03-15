class Shape{
	public:
		virtual double getArea()=0;
		virtual double getPerimeter()=0;
		virtual std::string getTypeString()=0;
};
class Circle : public Shape{
	private:
		double _radius;
	public:
		Circle(double radius);
		virtual double getArea();
		virtual double getPerimeter();
		virtual std::string getTypeString();
};
class Rectangle : public Shape{
	private:
		double _height;
		double _width;
	public:
		Rectangle(double height, double width);
		virtual double getArea();
		virtual double getPerimeter();
		virtual std::string getTypeString();
};





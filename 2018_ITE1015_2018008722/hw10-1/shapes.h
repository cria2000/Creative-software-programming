class Shape{
	protected:
		double width;
		double height;
	public:
		Shape(double _width, double _height);
		virtual double getArea()=0;
		virtual ~Shape(){}
};
class Triangle : public Shape{
	public:
		Triangle(double _width, double _height);
		virtual double getArea();
		virtual ~Triangle(){}
};
class Rectangle : public Shape{
	public:
		Rectangle(double _width, double _height);
		virtual double getArea();
		virtual ~Rectangle(){}
};

class Shape{
	public:
		Shape(){_x=0;_y=0;_brush=0;}
		Shape(int x,int y,char brush){_x=x; _y=y; _brush=brush;}
//		double GetArea(){};
//		int GetPerimeter(){};
//		void Draw(int canvas_width, int canvas_height){};
	protected:
		int _x;
		int _y;
		char _brush;

};
class Rectangle:protected Shape{
	protected:
		int _height;
		int _width;
	public:
		Rectangle(int x,int y,int height,int width,char brush):Shape(x,y,brush){_height=height; _width=width;}
		double GetArea();
		int GetPerimeter();
		void Draw(int canvas_width, int canvas_height);
};
class Square:protected Shape{
	protected:
		int _width;
	public:
		Square(int x,int y,int width,char brush):Shape(x,y,brush){_width=width;}
		double GetArea();
		int GetPerimeter();
		void Draw(int canvas_width, int canvas_height);
};
class Diamond:protected Shape{
	protected:
		int _distance;
	public:
		Diamond(int x,int y,int distance,char brush):Shape(x,y,brush){_distance=distance;}
		double GetArea();
		int GetPerimeter();
		void Draw(int cnavas_width, int canvas_height);
};


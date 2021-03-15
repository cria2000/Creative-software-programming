class Canvas{
	public:
		Canvas(const size_t row, const size_t col);
		~Canvas();
		void Resize(const size_t row, const size_t col);
		bool DrawPixel(const int x, const int y, const char brush);
		void Print() const;
		void Clear();
		char **_canvas;
		int _row, _col;
};
class Shape{
	public:
		Shape(int x, int y, char brush);
		virtual void Draw(Canvas* canvas) const{};
		virtual void printInfo() const{};
	protected:
		int _x;
		int _y;
		char _brush;
};
class Rectangle:public Shape{
	protected:
		int _height;
		int _width;
	public:
		Rectangle(int x, int y, int height, int width, char brush);
		virtual void Draw(Canvas* canvas) const;
		virtual void printInfo() const;
};
class UpTriangle:public Shape{
	protected:
		int _height;
	public:
		UpTriangle(int x, int y, int height, char brush);
		virtual void Draw(Canvas* canvas) const;
		virtual void printInfo() const;
};
class DownTriangle:public Shape{
	protected:
		int _height;
	public:
		DownTriangle(int x, int y, int height, char brush);
		virtual void Draw(Canvas* canvas) const;
		virtual void printInfo() const;
};
class Diamond:public Shape{
	protected:
		int _distance;
	public:
		Diamond(int x, int y, int distance, char brush);
		virtual void Draw(Canvas* canvas) const;
		virtual void printInfo() const;
};

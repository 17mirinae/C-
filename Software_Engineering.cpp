#include <iostream>
using namespace std;

class Figure { // abstract class
private:
	int color;
public:
	void setColor(int c) { color = c; }
	virtual void move(int dx, int dy) = 0; // abstract op
	virtual void draw() = 0; // abstract op
	Figure(int c) {
		color = c;
		cout << "Figure::Figure(int)" << endl;
	}
	virtual ~Figure() { // virtual 은 소멸자를 동적 (dynamic) 바인딩 (run-time binding) 하라는 의미
		cout << "Figure::~Figure()\n";
	}
};
class Point {
private:
	int x, y;
public:
	void move(int dx, int dy) {
		x += dx;
		y += dy;
		cout << "Point::move(int, int)\n";
	}
	Point(int xp, int yp) {
		x = xp;
		y = yp;
		cout << "Point::Point(int, int)\n";
	}
	~Point() { cout << "Point::~Point()\n"; }
};
class Circle : public Figure {
	Point center; // class type 이므로 association(composition) 이 된다.
	int radius; // primitive type 이므로 attribute 가 된다.
public:
	void move(int dx, int dy) {
		center.move(dx, dy);
		cout << "Circle::move(int, int)\n";
	}
	void draw() {
		cout << "Circle::draw()\n";
	}
	void setRadius(int r) { radius = r; }
	Circle(int x, int y, int r, int c) : Figure(c), center(x, y) {
		radius = r;
		cout << "Circle::Circle(int, int, int, int)\n";
	}
	~Circle() { cout << "Circle::~Circle()\n"; }
};
class Rectangle : public Figure {
	Point topleft;
	int width, height;
public:
	void move(int dx, int dy) {
		topleft.move(dx, dy);
		cout << "Rectangle::move(int, int)\n";
	}
	void draw() { cout << "Rectangle::draw()\n"; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	Rectangle(int x, int y, int w, int h, int c) :Figure(c), topleft(x, y) {
		width = w;
		height = h;
		cout << "Rectangle::Rectangle(int, int, int, int, int)\n";
	}
	~Rectangle() {
		cout << "Rectangle::~Rectangle()\n";
	}
};
void main() {
	Figure* f[4];
	int num = 4;
	f[0] = new Circle(100, 100, 50, 2); // 상위 클래스 포인터나 참조로 하위 클래스 객체를 가리키는 것?
	f[1] = new Circle(200, 200, 30, 2); // upcasting
	f[2] = new Rectangle(10, 10, 50, 40, 3);
	f[3] = new Rectangle(100, 100, 70, 30, 4);

	int dx = 10, dy = 20, i;
	for (i = 0; i < num; i++) f[i]->move(dx, dy); // 다형성 예
	for (i = 0; i < num; i++) f[i]->draw(); // 다형성 예

	for (i = 0; i < num; i++) delete f[i]; // 다형성 예
}
#include <iostream>
#include "point.hpp"
#include <cmath>
#define PI 3.1415926
using std::cout, std::endl;

class Circle
{
private:
	Point center;
	float radius;

public:

	Circle(const Point& center, float radius)
	{
		this->center = center;
		this->radius = radius;
	}

	Circle()
	{
		this->center = Point();
		this->radius = 1;
	}

	Circle(const Circle& circle)
	{
		center = circle.center;
		radius = circle.radius;
	}

	void setCenter(const Point& center)
	{
		this->center = center;
	}

	Point getCenter() const
	{
		return center;
	}

	void setRadius(float r)
	{
		if (r<0)
			radius = 0;
		else radius = r;
	}

	float getRadius() const
	{
		return radius;
	}

	float area() const
	{
		return PI*radius*radius;
	}

	float distance(const Point& p) const
	{
		return std::fabs(center.distance(p) - radius);
	}

	bool isColliding(const Circle& c) const
	{
		float dist = center.distance(c.center);
		return (dist >= std::fabs(radius - c.radius))&&(dist <= (radius + c.radius));
	}

	void move(const Point& p)
	{
		center = center + p;
	}

};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;

	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
}
#include <stdio.h>
#include <math.h>
struct point
{
	double x;
	double y;
};
typedef struct point Point;
struct triangle
{
	Point a;
	Point b;
	Point c;
};
typedef struct triangle Triangle;

void print_point(Point z)
{
	printf("(%.2lf, %.2lf)\n", z.x, z.y);
}
void print_triangle(const Triangle* p)
{
	printf("{(%.2lf, %.2lf), (%.2lf, %.2lf), (%.2lf, %.2lf)}\n", p->a.x, p->a.y, p->b.x, p->b.y, p->c.x, p->c.y);
}
float distance(Point a, Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
float get_triangle_perimeter(const Triangle* p)
{
	return (distance(p->a, p->b) + distance(p->b, p->c) + distance(p->a, p->c));
}
Triangle moved_triangle(const Triangle* p, Point v)
{
	Triangle n;
	n.a.x = p->a.x + v.x;
	n.b.x = p->b.x + v.x;
	n.c.x = p->c.x + v.x;
	n.a.y = p->a.y + v.y;
	n.b.y = p->b.y + v.y;
	n.c.y = p->c.y + v.y;
	return n;
}
void move_triangle(Triangle* p, Point v)
{
	p->a.x += v.x;
	p->b.x += v.x;
	p->c.x += v.x;
	p->a.y += v.y;
	p->b.y += v.y;
	p->c.y += v.y;
}
int main()
{
	Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
	printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));
	
	Point d = {1.0, 1.0};
	print_triangle(&t);
	move_triangle(&t, d);
	print_triangle(&t);
}

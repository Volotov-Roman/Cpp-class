#include <iostream>
#include <cmath>

struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = {left.x + right.x, left.y + right.y};
    return result;
}

Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = {left.x * right, left.y * right};
    return result;
}

Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = {left * right.x, left * right.y};
    return result;
}

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

float getDistance(Vector2f a, Vector2f b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::ostream& operator<<(std::ostream& out, Vector2f right)
{
    out << "(" << right.x << ", " << right.y << ")";
    return out;
}

struct Shape
{
    Vector2f mPosition;
    Vector2f getPosition()
    {
        return mPosition;
    }
    void setPosition(Vector2f newPosition)
    {
        mPosition = newPosition;
    }
    void move(Vector2f change)
    {
        mPosition += change;
    }
};

class Circle: public Shape
{
private:
    float mRadius;

public:

    Circle(float radius) : mRadius(radius)
    {
        mPosition = {0, 0};
    }

    float calculatePerimeter()
    {
        return 2 * 3.1415926535898 * mRadius;
    }
};



class Rectangle: public Shape
{
private:
    float mWidth;
    float mHeight;

public:

    Rectangle(float width, float height) : mWidth(width), mHeight(height)
    {
        mPosition = {0, 0};
    }

    float calculatePerimeter()
    {
        return 2 * (mWidth + mHeight);
    }
};




class Triangle: public Shape
{
private:
    Vector2f mPointA;
    Vector2f mPointB;
    Vector2f mPointC;

public:

    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC) 
        : mPointA(pointA), mPointB(pointB), mPointC(pointC)
    {
        mPosition = {0, 0};
    }

    float calculatePerimeter()
    {
        return getDistance(mPointA, mPointB) + getDistance(mPointB, mPointC) + getDistance(mPointC, mPointA);
    }
};


int main()
{
    Circle a(10);
    std::cout << a.calculatePerimeter() << std::endl;

    Rectangle b(100, 200);
    std::cout << b.calculatePerimeter() << std::endl;

    Triangle c({5, 2}, {-7, 5}, {4, 4});
    std::cout << c.calculatePerimeter() << std::endl;

    std::cout << a.getPosition() << std::endl;
    a.move({2.0f, 3.0f});
    std::cout << a.getPosition() << std::endl;

    std::cout << b.getPosition() << std::endl;
    b.move({5.0f, -3.0f});
    std::cout << b.getPosition() << std::endl;

    std::cout << c.getPosition() << std::endl;
    c.move({2.41f, -0.023f});
    std::cout << c.getPosition() << std::endl;
}
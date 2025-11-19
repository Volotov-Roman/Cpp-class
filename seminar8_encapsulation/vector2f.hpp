#pragma once
#include <iostream>
#include <cmath>

struct Vector2f
{
    float x;
    float y;
};

Vector2f operator+(const Vector2f& a, const Vector2f& b)
{
    Vector2f result = {a.x + b.x, a.y + b.y};
    return result;
}

Vector2f operator-(const Vector2f& a, const Vector2f& b)
{
    Vector2f result = {a.x - b.x, a.y - b.y};
    return result;
}

Vector2f operator*(float a, const Vector2f& b)
{
    Vector2f result = {a * b.x, a * b.y};
    return result;
}

Vector2f operator*(const Vector2f& b, float a)
{
    return a * b;
}

float operator*(const Vector2f& a, const Vector2f& b)
{
    return a.x * b.x + a.y * b.y;
}

Vector2f operator-(const Vector2f& a)
{
    Vector2f result = {-a.x, -a.y};
    return result;
}

Vector2f operator+(const Vector2f& a)
{
    return a;
}

bool operator==(const Vector2f& a, const Vector2f& b)
{
    return (a.x == b.x)&&(a.y == b.y);
}

bool operator!=(const Vector2f& a, const Vector2f& b)
{
    return !(a == b);
}

Vector2f& operator+=(Vector2f& a, const Vector2f& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2f& operator-=(Vector2f& a, const Vector2f& b)
{
    return a += (-b);
}

Vector2f& operator*=(Vector2f& a, float b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

Vector2f& operator/=(Vector2f& a, float b)
{
    return a *= (1/b);
}


std::ostream& operator<<(std::ostream& left, const Vector2f& right) 
{
    left << "(" << right.x << ", " << right.y << ")";
    return left;
}

std::istream& operator>>(std::istream& in, Vector2f& v) 
{
    in >> v.x >> v.y;
    return in;
}

#include <iostream>
#include "point2d.h"

using namespace std;

Point::Point()
{}
Point::Point(const Point& p)
{
    x_ = p.x_;
    y_ = p.y_;
}
Point::Point(int c)
{
    x_ = c;
    y_ = c;
}
Point::Point(int x, int y)
{
    x_ = x;
    y_ = y;
}

Point Point::operator-() const
{
    Point p;
    p.x_ = -x_;
    p.y_ = -y_;
    return p;
}

Point operator+(const Point& lhs, const Point& rhs)
{
    Point result;
    result.x_ = lhs.x_ + rhs.x_;
    result.y_ = lhs.y_ + rhs.y_;
    
    return result;
}

Point operator-(const Point& lhs, const Point& rhs)
{
    Point result;
    result.x_ = lhs.x_ - rhs.x_;
    result.y_ = lhs.y_ - rhs.y_;
    
    return result;
}
Point operator*(const Point& lhs, const Point& rhs)
{
    Point result;
    result.x_ = lhs.x_ * rhs.x_;
    result.y_ = lhs.y_ * rhs.y_;
    
    return result;
}


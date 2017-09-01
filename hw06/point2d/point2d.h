
#ifndef __point2d__point2d__
#define __point2d__point2d__

#include <iostream>

struct Point {
    int x_, y_;  // 멤버 변수.
    
    Point();
    Point(const Point& p);
    explicit Point(int c);
    Point(int x, int y);
    
    Point operator-() const;  // 전위 - 연산자
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);


#endif /* defined(__point2d__point2d__) */

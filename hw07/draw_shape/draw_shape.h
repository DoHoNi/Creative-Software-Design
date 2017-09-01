//
//  draw_shape.h
//  draw_shape
//
//  Created by 김도현 on 2015. 11. 5..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __draw_shape__draw_shape__
#define __draw_shape__draw_shape__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Canvas {
public:
    Canvas(size_t row, size_t col);
    ~Canvas();
    
    // Canvas 크기를 w x h 로 변경한다. 그려진 내용은 보존한다.
    void Resize(size_t w, size_t h);
    
    // (x,y) 위치에 ch 문자를 그린다. 범위 밖의 x,y 는 무시한다.
    bool Draw(int x, int y, char brush);
    
    // 그려진 내용을 모두 지운다 ('.'으로 초기화)
    void Clear();
    
private:
    int row_, col_;
    vector<vector <char> > canvas_;
    // 그려진 모양을 저장할 수 있도록 데이터멤버를 정의 (resize 가능에 주의)
    friend ostream& operator<<(ostream& os, const Canvas& c);
};

class Shape {
public:
    virtual ~Shape(){} // changed
    virtual void Draw(Canvas* canvas) const = 0;
    int x(){return x_;}
    int y(){return y_;}
    int h(){return height_;}
    int w(){return width_;}
    char brush(){return brush_;}
    string type(){return type_;}
    
protected:
    int x_,y_;
    int height_;
    int width_;
    string type_;
    char brush_;// 도형의 공통 속성을 정의.
};

class Rectangle : public Shape
{
    virtual void Draw(Canvas* canvas) const;
    friend istream& operator>>(istream& is, Rectangle& r);

};
class UpTriangle : public Shape
{
    virtual void Draw(Canvas* canvas) const;
    friend istream& operator>>(istream& is, UpTriangle& t);
    
};
class DownTriangle : public Shape
{
    virtual void Draw(Canvas* canvas) const;
    friend istream& operator>>(istream& is, DownTriangle& d);
};
class Diamond : public Shape
{
    virtual void Draw(Canvas* canvas) const;
    friend istream& operator>>(istream& is, Diamond& dm);
};

//istream& operator>>(istream& is, Rectangle& r);
//istream& operator>>(istream& is, UpTriangle& t);
//istream& operator>>(istream& is, DownTriangle& d);
//istream& operator>>(istream& is, Diamond& dm);


#endif /* defined(__draw_shape__draw_shape__) */

//
//  draw_shape.cpp
//  draw_shape
//
//  Created by 김도현 on 2015. 11. 5..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "draw_shape.h"


    Canvas::Canvas(size_t row, size_t col)
    {
        row_ = (int)row;
        col_ = (int)col;
        
        canvas_=vector<vector <char> >( row_,vector<char>(col_,'.'));
    }
Canvas::~Canvas()
{
    while(canvas_.size())canvas_[0].clear();
    canvas_.clear();
}

ostream& operator<<(ostream& os, const Canvas& c)
{
    cout << " ";
    for(int k=0; k<c.col_;k++)
        cout << k%10;
    cout << endl;
    for(int i=0; i< c.row_;i++)
    {
        cout << i%10;
        for(int j=0;j< c.col_;++j)
            os << c.canvas_[i][j];
        os<<endl;
    }
    return os;
}

    // Canvas 크기를 w x h 로 변경한다. 그려진 내용은 보존한다.
    void Canvas::Resize(size_t w, size_t h)
    {
        row_=(int)h; col_=(int)w;
        canvas_.resize(w);
        for(int i=0; i<w;i++)
        {
            canvas_[i].resize(h);
        }
    }
    
    // (x,y) 위치에 ch 문자를 그린다. 범위 밖의 x,y 는 무시한다.
    bool Canvas::Draw(int x, int y, char brush)
    {
        if(x<0 || y<0 || x>=col_ || y>=row_)
            return false;
        
        canvas_[y][x] = brush;
        
        return true;
    }
    
    // 그려진 내용을 모두 지운다 ('.'으로 초기화)
    void Canvas::Clear()
    {
        for(int i=0; i<row_;i++)
        {
            for(int j=0; j<col_; j++)
            {
                canvas_[i][j] ='.';
            }
        }
    }
        

    void Rectangle::Draw(Canvas* canvas) const
    {
        
        for(int a= y_ ;a<y_+height_;a++)
        {
            
            for(int b= x_; b<x_+width_;b++)
            {
                canvas->Draw(b, a, brush_);
            }
        }
    }
    void DownTriangle::Draw(Canvas* canvas) const
    {
        for(int a =0; a<height_;a++)
        {
            for(int b = -a; b <= a; b++)
            {
                canvas->Draw(x_+b, y_-a, brush_);
            }
        }
    }
    void UpTriangle::Draw(Canvas* canvas) const
    {
        for(int a =0; a<height_;a++)
        {
            for(int b = -a; b <= a; b++)
            {
                canvas->Draw(x_+b, y_+a, brush_);
            }
        }
    }
    void Diamond::Draw(Canvas* canvas) const
    {
        int a,b;
        for(a=0; a<=height_;a++)
        {
            for( b = -a; b <= a; b++)
            {
                canvas->Draw(x_+b, y_+a, brush_);
            }
        }
        for(a =0; a<height_;a++)
        {
            for(int b = -a; b <= a; b++)
            {
                canvas->Draw(x_+b, y_+(height_*2)-a, brush_);
            }
        }

    }



istream& operator>>(istream& is, Rectangle& r)
{
    r.type_ = "rect";
    cin >>r.x_ >> r.y_ >>r.width_ >> r.height_ >> r.brush_;
    return is;
}
istream& operator>>(istream& is, UpTriangle& t)
{
    t.type_ = "tri_up";
    cin >> t.x_ >> t.y_ >>t.height_ >> t.brush_;
    return is;
}
istream& operator>>(istream& is, DownTriangle& d)
{
    d.type_ = "tri_down";
    cin >>d.x_ >> d.y_ >> d.height_ >> d.brush_;
    return is;
}

istream& operator>>(istream& is, Diamond& dm)
{
    dm.type_ = "diamond";
    cin >> dm.x_ >>dm.y_ >> dm.height_ >> dm.brush_;
    return is;
}


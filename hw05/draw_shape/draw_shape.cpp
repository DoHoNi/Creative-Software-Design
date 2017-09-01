
#include <iostream>
#include "draw_shape.h"

using namespace std;

Canvas::Canvas(size_t row, size_t col)
{
    row_=row;
    col_=col;
}
Canvas::~Canvas()
{
    
}
int Canvas::AddShape(const Shape &s)// Return the index of the shape.
{
    if(s.type==RECTANGLE)
    {
        if((s.height%2)==0 || (s.width%2)==0)
        {
            return ERROR_INVALID_INPUT;
        
        }
        if(s.x - (s.width/2) < 0 || s.x + (s.width/2) >= row_
           || s.y - (s.height/2) < 0 || s.y + (s.height/2)>= col_)
                return ERROR_OUT_OF_CANVAS;
        
        
    }
    else if(s.x - (s.width-1) < 0 || s.x + (s.width-1) >= row_
           || s.y - (s.height-1) < 0 || s.y + (s.height-1)>= col_)
                return ERROR_OUT_OF_CANVAS;

    
        
    
        shapes_.push_back(s);
    
    return (int)shapes_.size();
}
void Canvas::DeleteShape(int index)
{
    if(index<shapes_.size())
        shapes_.erase(shapes_.begin()+index);
}
void Canvas::Draw(ostream& os)
{
    vector<vector<char> > canvas( row_,vector<char>(col_,'.'));
    cout << " ";
    
    for(int i=0; i<shapes_.size();i++)
    {
        if(shapes_[i].type==RECTANGLE)
        {
            for(int a= (shapes_[i].y)-(shapes_[i].height%2);
                a<=(shapes_[i].y)+(shapes_[i].height%2);a++)
            {
            
                for(int b= (shapes_[i].x)-(shapes_[i].width%2);
                    b<=(shapes_[i].x)+(shapes_[i].width%2);b++)
                {
                    canvas[a][b] = shapes_[i].brush;
                }
            }
        }
        else if(shapes_[i].type==TRIANGLE_DOWN)
        {
            for(int a =0; a<shapes_[i].height;a++)
            {
                for(int b = -a; b <= a; b++)
                {
                    canvas[shapes_[i].y - a][shapes_[i].x + b] = shapes_[i].brush;
                }
            }
        }
        else if(shapes_[i].type == TRIANGLE_UP)
        {
            for(int a =0; a<shapes_[i].height;a++)
            {
                for(int b = -a; b <= a; b++)
                {
                    canvas[shapes_[i].y + a][shapes_[i].x + b] = shapes_[i].brush;
                }
            }
        }
    }
    
    
    for(int k=0; k<col_; k++)  // 출력
        cout << (k%10);
    cout <<endl;
    
    for(int i=0; i<row_;i++ )
    {
        cout << (i%10);
        for(int j=0; j<col_;j++)
            cout << canvas[i][j];
        cout << endl;
    }
}
void Canvas::Dump(ostream& os)
{
    for(int i=0; i<shapes_.size();i++ )
    {
        if(shapes_[i].type == RECTANGLE )
            os << i << " " << "rect" << " " << shapes_[i].x << " "<<shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].width << " " <<shapes_[i].brush << endl;
        else if(shapes_[i].type == TRIANGLE_DOWN)
            os << i << " " << "tri_down" << " " << shapes_[i].x << " " <<shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
        else if(shapes_[i].type == TRIANGLE_UP)
            os << i << " " << "tri_up" << " " << shapes_[i].x << " " <<shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
   
    }

}

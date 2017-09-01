
#include <iostream>
#include "draw_shape.h"

using namespace std;

int main()
{
    int row,col;
    cin >> row >>col;
    Canvas canvas(row,col);
    canvas.Draw(cout);
    int result =0;
    
    while(1)
    {
        string input;
        cin >> input;
        if(input=="quit") return 0;
        else if(input =="add")
        {
            Shape shape;
            
            string type;
            cin >>type;
            
            if(type == "rect" )
            {
                shape.type = RECTANGLE;
                cin >> shape.x >> shape.y >> shape.width >> shape.height >> shape.brush;
                
                result = canvas.AddShape(shape);
                if(result== ERROR_OUT_OF_CANVAS)
                    cout << "error out of canvas" << endl;
                else if(result == ERROR_INVALID_INPUT)
                    cout << "error invalid input" << endl;

                
            }
            else if(type == "tri_down")
            {
                shape.type = TRIANGLE_DOWN;
                cin >> shape.x >> shape.y >> shape.height >> shape.brush;
                
                result = canvas.AddShape(shape);
                if(result== ERROR_OUT_OF_CANVAS)
                    cout << "error out of canvas" << endl;
                else if(result == ERROR_INVALID_INPUT)
                    cout << "error invalid input" << endl;
            }
            else if(type == "tri_up")
            {
                shape.type = TRIANGLE_UP;
                cin >> shape.x >> shape.y >> shape.height >> shape.brush;
                
                result = canvas.AddShape(shape);
                if(result== ERROR_OUT_OF_CANVAS)
                    cout << "error out of canvas" << endl;
                else if(result == ERROR_INVALID_INPUT)
                    cout << "error invalid input" << endl;
            }
        }
        else if(input == "delete")
        {
            int index;
            cin >> index;
            canvas.DeleteShape(index);
        }
        else if(input == "draw")
        {
            canvas.Draw(cout);
        }
        else if(input == "dump")
        {
            canvas.Dump(cout);
        }
        
        
        
    }
}
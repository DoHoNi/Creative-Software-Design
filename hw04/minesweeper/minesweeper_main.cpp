
#include "minesweeper.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

int main()
{
    vector<string> _map;
    string inputs;
    bool returnValue = true;
    int height;
    int width;
    Minesweeper *minesweeper = new Minesweeper();
    
    while(1)
    {
        cin >> inputs;

        if(inputs ==":quit") return 0;
        else if(inputs==":set")
        {
            cin>>width>>height;
            minesweeper->setMap((size_t)width, (size_t)height, _map);
        
        }
        else if(inputs==":toggle")
        {
            int _x = 0 ;
            int _y = 0 ;
            
            cin>>_y>>_x;
            
            returnValue = minesweeper->toggleMine(_x,_y);
        }
        else if(inputs==":play")
        {
            minesweeper->setPlay();
        }
        else if(inputs==":touch")
        {
            int _x,_y;
            cin>>_y>>_x;
            minesweeper->touchMap(_x,_y);
        }
    }
 
}


//
//  main.cpp
//  new_vector
//
//  Created by 김도현 on 2015. 11. 13..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

// new_vector_main.cc

#include <iostream>
#include "new_vector.h"
using namespace std;

int main(void)
{
    NewVector nv = NewVector();
    while(true)
    {
        string type;
        cin >> type;
        
        if(type == "i")
        {
            int value;
            cin >> value;
            nv.add(value); // replace to nv.add<int>(value) when error occurs
        }
        else if(type == "d")
        {
            double value;
            cin >> value;
            nv.add(value); // replace to nv.add<double>(value) when error occurs
        }
        else if(type == "c")
        {
            char value;
            cin >> value;
            nv.add(value); // replace to nv.add<char>(value) when error occurs
        }
        else if(type == "print") cout << nv;
        else if(type == "q") break;
    }
    return 0;
}

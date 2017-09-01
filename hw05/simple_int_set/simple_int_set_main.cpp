//
//  main.cpp
//  simple_int_set
//
//  Created by 김도현 on 2015. 10. 13..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include "simple_int_set.h"

using namespace std;

enum EOperateType
{
    Invalid = -1,
    
    Add,
    Sub,
    Mul,
    Print,
};
typedef enum EOperateType OperateType;

int main(void)
{
    set<int> left,right;
    string input ;
    bool result;
    OperateType type = Invalid;
    int rl=0;
    while(1)
    {
        while (rl!=2)
        {
            cin >> input;
            if(input =="0") return 0;
            if(input =="{")
            {
                if(rl==0)
                {
                    result =InputSet(cin, &left);
                    rl++;
                }
                else if(rl==1)
                {
                    result =InputSet(cin, &right);
                    rl++;
                }
            }
            else
            {
                if(input == "+")
                    type = Add;
                if(input == "-")
                    type = Sub;
                if(input == "*")
                    type = Mul;
            }
        }
        
        rl =0;
        
            switch(type)
            {
                case Add:
                    OutputSet(SetUnion(left,right),cout);
                    break;
                    
                case Sub:
                   OutputSet(SetDifference(left,right),cout);
                    break;
                    
                case Mul:
                    OutputSet(SetIntersection(left,right),cout);
                    break;
                    
                default: break;
            }
        left.clear();
        right.clear();
    
    }
}

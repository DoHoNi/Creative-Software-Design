//
//  new_vector.h
//  new_vector
//
//  Created by 김도현 on 2015. 11. 13..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __new_vector__new_vector__
#define __new_vector__new_vector__

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
struct container
{
    int flag;
    int reint;
    double redouble;
    char rechar;
};

class NewVector
{
public:
    NewVector(){count_ = 0;}
    
    template <typename T>
    void add(T _value)
    {
        container temp;
        if(typeid(_value) == typeid(int))
        {
            temp.flag=0;
            temp.reint = _value;
        }
        else if(typeid(_value) == typeid(double))
        {
            temp.flag=1;
            temp.redouble = _value;
        }
        else if(typeid(_value) == typeid(char))
        {
            temp.flag=2;
            temp.rechar = _value;
        }
        contain.push_back(temp);
        ++count_;
        
    }
    
    inline int count(){return count_;}
    
    friend ostream& operator << (ostream& _os, const NewVector _nv)
    {
        for(int i=0; i<_nv.count_; i++)
        {
            if(_nv.contain[i].flag == 0)
            {
                _os << _nv.contain[i].reint;
            }
            else if(_nv.contain[i].flag == 1)
            {
                _os << _nv.contain[i].redouble;
            }
            else if(_nv.contain[i].flag == 2)
            {
                _os << _nv.contain[i].rechar;
            }
            _os << " ";
        }
        _os << endl;
        return _os;
    }
    
private:
    int count_;
    vector<container> contain;
    // add your own private function / variables
};


#endif /* defined(__new_vector__new_vector__) */

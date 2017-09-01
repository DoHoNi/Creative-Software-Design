//
//  simple_int_set_main.cpp
//  simple_int_set
//
//  Created by 김도현 on 2015. 10. 14..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "simple_int_set.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

set<int> SetIntersection(const set<int>& set0, const set<int>& set1)
{
    set<int> result;
    
    set_intersection (set0.begin(), set0.end(), set1.begin(), set1.end(), inserter(result, result.end()));
    
    return result;
}
set<int> SetUnion(const set<int>& set0, const set<int>& set1)
{
    set<int> result;
    
    set_union(set0.begin(), set0.end(), set1.begin(), set1.end(),inserter(result, result.end()));
    
    return result;
}
set<int> SetDifference(const set<int>& set0, const set<int>& set1)
{
    set<int> result;
    
    set_difference(set0.begin(), set0.end(), set1.begin(), set1.end(),inserter(result, result.end()));
    
    return result;

}

bool InputSet(istream& in, set<int>* s)
{
    string c = "";
    while (1)
    {
        in >> c;
        if(c=="}")break;
        s->insert(atoi(c.c_str()));
    }
        return true;
    
}
void OutputSet(const set<int>& s, ostream& out)
{
    set<int>::iterator it_s = s.begin();
    
    out << "{ ";
    for( ; it_s != s.end(); ++it_s)
    {
        out << *it_s << " ";
    }
    out << "}" << endl;
}

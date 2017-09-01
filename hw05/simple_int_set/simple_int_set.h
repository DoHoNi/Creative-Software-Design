//
//  simple_int_set_main.h
//  simple_int_set
//
//  Created by 김도현 on 2015. 10. 14..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __simple_int_set__simple_int_set_main__
#define __simple_int_set__simple_int_set_main__

#include <iostream>
#include <set>
using namespace std;

set<int> SetIntersection(const set<int>& set0, const set<int>& set1);
set<int> SetUnion(const set<int>& set0, const set<int>& set1);
set<int> SetDifference(const set<int>& set0, const set<int>& set1);

bool InputSet(istream& in, set<int>* s);
// return false when input is incorrect
// (input must be like { 1 2 3 })
void OutputSet(const set<int>& s, ostream& out);


#endif /* defined(__simple_int_set__simple_int_set_main__) */

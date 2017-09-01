//
//  parse_radix.h
//  parse_radix
//
//  Created by 김도현 on 2015. 10. 29..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __parse_radix__parse_radix__
#define __parse_radix__parse_radix__

#include <stdio.h>
#include <string>

using namespace std;

int ParseRadix(const string& number);
string ConvertRadix(int number, int radix);
void printresult( string result, int radix );

#endif /* defined(__parse_radix__parse_radix__) */

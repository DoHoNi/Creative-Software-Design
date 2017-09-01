// 2015004011 소프트웨어전공 김도현
//진법변환


#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Implement this function.

string RadixNotation(unsigned int number, unsigned int radix)
{
    string dabarr = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    if (number == 0) return "";
    return RadixNotation(number / radix, radix) + dabarr[number%radix];
}

/*
int main()
{
    unsigned int number, radix;
    cin >> radix >> number;
    cout << RadixNotation(number, radix);
    return 0;
}
*/

int main(int argc, char** argv) {
    
    if (argc < 2) return -1;
    
    unsigned int radix;
    
    sscanf(argv[1], "%u", &radix);
    
    if (radix < 2 || radix > 36) return -1;
    
    for (int i = 2; i < argc; ++i) {
        unsigned int number;
        sscanf(argv[i], "%u", &number);
        
        cout << RadixNotation(number, radix) << endl;
    }
    
    return 0;
}


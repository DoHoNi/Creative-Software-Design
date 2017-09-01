
#include <iostream>
#include "parse_radix.h"

using namespace std;


int ParseRadix(const string& number)
{
    int radix =-1;
    int result =-1;
    
    if(number.find('_') == string::npos)
    {
        radix=10;
        for(int i= 0; i<number.length(); i++)
        {
            char c = number[i];
            int num = (int)c -(int)'0';
            if(result<0) result = num;
            else result = result*radix + num;
        }

    }
    
    else
    {
        for(int i= (int)number.find('_')+1; i<number.length(); i++)
        {
            char c = number[i];
            int num = (int)c -(int)'0';
            if(radix<0) radix = num;
            else radix = radix*10 +num;
            
        }
        for(int i= 0; i<number.find('_'); i++)
        {
            char c = number[i];
            int num ;
            if(isdigit(c))
                num = (int)c -(int)'0';
            else
                num = ((int)c -(int)'a') +10;
            
            if(num > radix) return -1;
            if(result<0) result = num;
            else result = result*radix + num;
        }

    }
    
    
    
    return result;
    
}
string ConvertRadix(int number, int radix)
{
    if(number <0)
    {
        number = -number;

    }
    string dabarr = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    if (number == 0)
    {
    
        return "";
    }
    return ConvertRadix( number / radix, radix) + dabarr[number%radix];
}

void printresult( string result, int radix )
{
    
    if(radix==10)cout << result << endl;
    else cout << result <<"_" <<radix << endl;

}
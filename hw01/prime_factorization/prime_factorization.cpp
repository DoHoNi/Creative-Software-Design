

#include <iostream>
#include <stdio.h>
using namespace std;

string st_arr;

// Implement this function
string primeFactorization(unsigned int _number)
{

    if(_number==0)return "";
    int k=0, i=2,num=0;
    while (_number!=0)
    {
        if(_number%i==0)
        {
            _number/=i;
            k++;
        }
        else
        {
        
            if(k>0)
            {
                if(num!=0)
                cout <<"x";
                
                cout << i;
                cout <<"^";
                cout <<k;
                num++;
            }
            if(_number==1) _number=0;
            i++;
            k=0;
            
        }
        
    }
    
    
    return "";
}

int main(int argc, char** argv)
{
    if(argc < 1) return -1;
    
    unsigned int number;
    
   // sscanf(argv[1], "%u", &number);
    cin >> number;
    cout << primeFactorization(number)  <<argc<< endl;
    return 0;
}

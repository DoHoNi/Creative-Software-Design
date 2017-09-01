
#include "parse_radix.h"
#include <iostream>

using namespace std;

int main()
{
    string inputs;
    int result;
    string result_radix;
    
    
    while(1)
    {
        cin >> inputs;
        if(inputs == "quit") return 0;
        else if(inputs =="eval")
        {
            string lst,rst;
            int radix;
            string operator_;
            
            cin >> lst >> operator_ >> rst ;
            
            if(operator_ == "+")
            {
                cin >> radix;
                int lst_int = ParseRadix(lst);
                int rst_int = ParseRadix(rst);
                
                if(lst_int<0 || rst_int <0)
                {
                    cout << "Error" << endl;
                    continue;
                }
                
                result = lst_int + rst_int;
                
                result_radix = ConvertRadix(result,radix);
                printresult(result_radix, radix);
            }
            else if(operator_ == "-")
            {
                cin >> radix;
                int lst_int = ParseRadix(lst);
                int rst_int = ParseRadix(rst);
                if(lst_int<0 || rst_int <0)
                {
                    cout << "Error" << endl;
                    continue;
                }
                result = lst_int - rst_int;
                if(result < 0)
                    result_radix = "-" + ConvertRadix(result,radix);
                    
                else
                    result_radix = ConvertRadix(result,radix);
                printresult(result_radix, radix);
            }
            else if(operator_ == "*")
            {
                cin >> radix;
                int lst_int = ParseRadix(lst);
                int rst_int = ParseRadix(rst);
                if(lst_int<0 || rst_int <0)
                {
                    cout << "Error" << endl;
                    continue;
                }
                result = lst_int * rst_int;

                result_radix = ConvertRadix(result,radix);
                printresult(result_radix, radix);
            }
            else if(operator_ == "/")
            {
                cin >> radix;
                int lst_int = ParseRadix(lst);
                int rst_int = ParseRadix(rst);
                if(lst_int<0 || rst_int <0)
                {
                    cout << "Error" << endl;
                    continue;
                }
                result = lst_int / rst_int;
                result_radix = ConvertRadix(result,radix);
                printresult(result_radix, radix);
            }
            else if(operator_ == ">")
            {
                
                int lst_int = ParseRadix(lst);
                int rst_int = ParseRadix(rst);
                if(lst_int<0 || rst_int <0)
                {
                    cout << "Error" << endl;
                    continue;
                }

                if(lst_int > rst_int) cout << "true" << endl;
                else cout <<"false" << endl;

            }
            else if(operator_ == "<")
            {
                
                int lst_int = ParseRadix(lst);
                int rst_int = ParseRadix(rst);
                if(lst_int<0 || rst_int <0)
                {
                    cout << "Error" << endl;
                    continue;
                }
                if(lst_int < rst_int) cout << "true" << endl;
                else cout <<"false" << endl;
                
            }
            else if(operator_ == "==")
            {
                int lst_int = ParseRadix(lst);
                int rst_int = ParseRadix(rst);
                if(lst_int<0 || rst_int <0)
                {
                    cout << "Error" << endl;
                    continue;
                }

                if(lst_int == rst_int) cout << "true" << endl;
                else cout <<"false" << endl;
                
            }
        }




        
    }
}
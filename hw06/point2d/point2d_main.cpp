
#include "point2d.h"
#include <iostream>
#include <string>
#include <Map>
#include <stdlib.h>

using namespace std;

int main() {
    
    string order;
    string key;
    char operator_;
    string lhs,rhs;
    map<string,Point> list;
    while (1)
    {
        cin >> order;
        
        if(order =="quit") return 0;
        
        else if(order == "set")
        {
            Point p;
            cin >> key >> p.x_ >> p.y_ ;

            list.insert(make_pair(key, p));
            
        }
        else if(order == "eval")
        {
            Point result;
            
            cin >> lhs >> operator_ >> rhs ;
            
            if(isdigit(lhs[0]) && isdigit(rhs[0]))
            {
                
                
                int lhs_int =atoi(lhs.c_str());
                Point lhs ( lhs_int );
                
                int rhs_int =atoi(rhs.c_str());
                Point rhs ( rhs_int );
                
               
                
                if(operator_ == '+')
                {
                    Point result =  lhs + rhs;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='-')
                {
                    Point result = lhs - rhs;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='*')
                {
                    Point result = lhs * rhs;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
            }
            else if(isdigit(lhs[0]))
            {
                int lhs_int =atoi(lhs.c_str());
                Point lhs ( lhs_int );
                if(list.find(rhs)==list.end())
                {
                    cout << "input error" << endl;
                }
                else if(operator_== '+')
                {
                    Point result =  lhs + list.find(rhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='-')
                {
                    Point result = lhs - list.find(rhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='*')
                {
                    Point result = lhs * list.find(rhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
            }
            else if(isdigit(rhs[0]))
            {
                int rhs_int =atoi(rhs.c_str());
                Point rhs ( rhs_int );
                
                if(list.find(lhs)==list.end())
                {
                    cout << "input error" << endl;
                }
                else if(operator_== '+')
                {
                    Point result =  rhs + list.find(lhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='-')
                {
                    Point result = rhs - list.find(lhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='*')
                {
                    Point result = rhs * list.find(lhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
            }
            else
            {
                
                if(list.find(lhs)==list.end() || list.find(rhs)==list.end())
                {
                    cout << "input error" << endl;
                }
                else if(operator_== '+')
                {
                                        Point result = list.find(lhs)->second + list.find(rhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='-')
                {
                    Point result = list.find(lhs)->second - list.find(rhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
                else if(operator_ =='*')
                {
                    Point result = list.find(lhs)->second * list.find(rhs)->second;
                    cout << "(" << result.x_ <<", " << result.y_ << ")" << endl;
                }
            }
        }
    }
    
    
}

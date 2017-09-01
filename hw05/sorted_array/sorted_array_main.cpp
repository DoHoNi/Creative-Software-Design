
#include <iostream>
#include "sorted_array.h"


int main() {
    SortedArray sortedarray;
    
    while(1)
    {
        string inputs;
        getline(cin,inputs);
        
        if(inputs =="quit") return 0;
        else if(inputs=="ascend")
        {
           
            vector<int> asc = sortedarray.GetSortedAscending();
            for(int i=0; i<asc.size();i++)
                cout << asc[i] << " ";
            cout << endl;
        
        }
        else if(inputs=="descend")
        {
            vector<int> dsc = sortedarray.GetSortedDescending();
            for(int i=0; i<dsc.size();i++)
                cout << dsc[i] << " ";
            cout << endl;

        }
        else if(inputs=="max")
        {
            cout << sortedarray.GetMax() << endl;
        }
        else if(inputs=="min")
        {
            cout << sortedarray.GetMin() <<endl;
        }
        else
        {
            int number =-1;
            
            for(int i=0; i<inputs.size(); ++i)
            {
                char c = inputs[i];
                
                
                if(isdigit(c) == true)
                {
                    
                    int num = (int)c - (int)'0';
                    
                    if(number < 0) number = num;
                    else number = number * 10 + num;
                }
                else
                {
                    sortedarray.AddNumber(number);
                    number= 0;
                }
                
            }
            if(number>-1)
                sortedarray.AddNumber(number);

        }
    }
    
   
}

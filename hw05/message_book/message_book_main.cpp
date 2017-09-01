//
//  message_book_main.cpp
//  message_book
//
//  Created by 김도현 on 2015. 10. 12..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "message_book.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    
    class MessageBook message;
    
    while(1)
    {
        string inputs;
        cin >> inputs;
        if(inputs =="quit")return 0; //quit
        if(inputs =="add"){
            string massage;
            int number;
            cin >> number;
            getline(cin,massage);
            massage=massage.substr(1,massage.size());
            message.AddMessage(number, massage);
            
        }
        else if(inputs =="delete")
        {
            int number;
            cin >> number;
            message.DeleteMessage(number);
           
        }
        else if(inputs =="print")
        {
            int number;
            cin >> number;
            vector<int> nums = message.GetNumbers();
            int i=0;
            for(;i<nums.size();++i)
            {
                if(nums[i]==number)
                {
                    cout << message.GetMessage(number)<<endl;
                    break;
                }
            }
            if(i==nums.size())
                cout <<" "<<endl;
            
        }
        else if(inputs =="list")
        {
            vector<int> nums = message.GetNumbers();
            for(int i=0;i<nums.size();++i)
                cout<<nums[i]<<": "<<message.GetMessage(nums[i])<<endl;
            
        }
        
    }

}

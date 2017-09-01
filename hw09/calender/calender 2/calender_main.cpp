//
//  main.cpp
//  calender
//
//  Created by 김도현 on 2015. 11. 22..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include <iostream>
#include <string>
#include "calender.h"

using namespace std;

int main()
{
    Date date;
    string cmd;
    while(cmd != "quit")
    {
        cin >> cmd;
        try{
            if(cmd == "set"){
                cin >> date;
                cout << date << endl;
            }
            else if (cmd == "next_day")
            {
                date.NextDay();
                cout << date <<endl;
            }
            else if (cmd == "next")
            {
                int day;
                cin >> day;
                date.NextDay(day);
                cout << date <<endl;
            }
        }catch (InvalidDateException& e)
        {
            cout << "Invalid date: " << e.input_date << endl;
        }
    }
    return 0;
}

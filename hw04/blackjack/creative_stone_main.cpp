//
//  main.cpp
//  creative_stone
//
//  Created by 김도현 on 2015. 10. 11..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include <iostream>
#include <string>
#include "creative_stone.h"

using namespace std;

int main()
{
    class CreativeStone minion;
    while(1)
    {
        string inputs;
        cin >> inputs;
        if(inputs ==":quit")return 0;
        if(inputs ==":add"){
            string name;
            int hp,power;
            cin >> name >> hp >> power;
            minion.add(name,hp,power);
        }
        else if(inputs ==":foeadd")
        {
            string name;
            int hp,power;
            cin >> name >> hp >> power;
            minion.foeadd(name,hp,power);
        }
        else if(inputs ==":attack")
        {
            string name1, name2;
            cin >> name1 >> name2;
            if(!minion.attack(name1,name2))
            {
                cout<<"CANNOT FIND MINION"<<endl;
                continue;
            }
        }
        else if(inputs ==":burn")
        {
            string str;
            getline(cin,str);
            str=str.substr(1,str.size());
            if(str.find(' ')==string::npos)
            {
                int damage=str[0]-'0';
                minion.burn(damage);
            }
            else
            {
                string name=str.substr(0,str.find(' '));
                str=str.substr(str.find(' ')+1,str.size());
                int damage=str[0]-'0';
                if(!minion.burn(name,damage))
                {
                    cout<<"CANNOT FIND MINION"<<endl;
                    continue;
                }
            }
        }
        minion.print();
    }
}


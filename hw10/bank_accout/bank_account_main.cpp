//
//  main.cpp
//  bank_account
//
//  Created by 김도현 on 2015. 11. 26..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include <iostream>
#include "bank_account.h"

int main()
{
    string cmd;
    vector<Account *> account;
    
    while (cmd != "quit")
    {
        cin>> cmd;
        if(cmd =="add")
        {
            string name, type;
            int balance;
            double rate;
            cin >> name >> type;
            if(type =="checking")
            {
                cin >> balance >> rate;
                account.push_back(CreateAccount(type, name, balance, rate));
            }
            else if(type =="saving")
            {
                cin >> balance >> rate;
                account.push_back(CreateAccount(type, name, balance, rate));
            }
        
        }
        else if(cmd =="show")
        {
            for(int i=0; i<account.size(); i++)
            {
                cout << account[i]->name() <<"\t"<< account[i]->type() <<"\t"
                << account[i]->balance() << "\t" << account[i]->interest_rate() << endl;
            }
        }
        else if(cmd =="after")
        {
            int year;
            cin >> year;
            for(int i=0; i<account.size(); i++)
            {
                cout << account[i]->name() <<"\t"<< account[i]->type() <<"\t"
                << account[i]->ComputeExpectedBalance(year) << "\t" << account[i]->interest_rate() << endl;
            }

        }
        else if(cmd =="delete")
        {
            string name;
            cin >> name;
            
            vector<Account *>::iterator itor = account.begin();
            for(int i=0; i< account.size();i++,itor++)
            {
                if(account[i]->name()==name)
                {
                    account.erase(itor);
                    break;
                }
            }
           
        }
    }

}

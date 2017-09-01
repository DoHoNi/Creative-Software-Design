//
//  world_clock.cpp
//  world_clock
//
//  Created by 김도현 on 2015. 11. 20..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "world_clock.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;
 map<string,int> WorldClock::timezone_;


void WorldClock::Tick(int seconds )
{
    int hh, mm, ss;
    int tsec = hour_*3600 + minute_*60 + second_+seconds;
    if(tsec <0) tsec = 24*3600 +tsec;
    
    hh= tsec/3600;
    mm=(tsec/60)%60;
    ss=tsec%60;
    hh%=24;
    
    SetTime (hh, mm, ss);
    
}

bool WorldClock::SetTime(int hour, int minute, int second)
{
    if(hour >= 24 || minute >= 60 || second >= 60)
        throw InvalidTimeException( to_string(hour) + ":" + to_string(minute) + ":" + to_string(second));
    else
    {
        hour_= hour; minute_= minute; second_=second;
    }
    return true;
}
bool WorldClock::LoadTimezoneFromFile(const string& file_path)
{
    string name;
    int tt;
    ifstream fin;
    fin.open("timezone.txt");
    while (!fin.eof())
    {
        fin >> name >> tt;
        timezone_.insert(make_pair(name, tt));
    }
    fin.close();
    return true;
}
void WorldClock::SaveTimezoneToFile(const string& file_path)
{
    ofstream fout;
    fout.open("timezone.txt",ios_base::trunc);
    for(map<string,int>::iterator it=timezone_.begin();it!=timezone_.end();++it)
        fout<<it->first<<" "<<it->second<<endl;
    fout.close();
    return ;
}
void WorldClock::AddTimezoneInfo(const string& city, int diff)
{
    timezone_[city]= diff;
    return;
}

// 잘못된 값 입력시 false 리턴하고 원래 시간은 바뀌지 않음.
bool WorldClock::SetTimezone(const string& timezone)
{
    if(timezone_.find(timezone) !=timezone_.end())
        time_difference_ = timezone_[timezone];
    else
        return false;
    return true;
}

ostream& operator<<(ostream& os, const WorldClock& c)
{
    os << c.hour() << ":" << c.minute() << ":" << c.second();
    if(c.time_difference()!=0)
        os << " (+" << c.time_difference() << ")";
    return os;
}
#include <cstdio>
istream& operator>>(istream& is, WorldClock& c)
{
    int hh, mm, ss;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    
    c.SetTime(hh, mm, ss);
    
    return is;
    
    
}


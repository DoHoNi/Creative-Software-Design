#include <iostream>
#include <string>
#include <map>
#include "creative_stone.h"
using namespace std;

void CreativeStone::add(string name,int hp,int power)
{
    if(our.find(name)==our.end())
    {
        our[name]=make_pair(hp,power);
    }
    else
    {
        our[name].first+=hp;
        our[name].second+=power;
    }
    if(our[name].first<=0) our.erase(name);
}

void CreativeStone::foeadd(string name,int hp,int power)
{
    if(there.find(name)==there.end())
    {
        there[name]=make_pair(hp,power);
    }
    else
    {
        there[name].first+=hp;
        there[name].second+=power;
    }
    if(there[name].first<=0) there.erase(name);
}

bool CreativeStone::attack(string _name1,string _name2)
{
    if(our.find(_name1)==our.end() || there.find(_name2)==there.end()) return false;
    
    our[_name1].first-=there[_name2].second;
    there[_name2].first-=our[_name1].second;
    
    if(our[_name1].first<=0)
        our.erase(_name1);
    
   
    if(there[_name2].first<=0)
        there.erase(_name2);
    
    return true;
}

void CreativeStone::burn(int _damage)
{
    map<string,pair<int,int> >::iterator it=there.begin();
    for(;it!=there.end();)
    {
        it->second.first-=_damage;
        if(it->second.first<=0) there.erase(it++);
        else ++it;
    }
}

bool CreativeStone::burn(string name,int _damage)
{
    if(there.find(name)!=there.end())
    {
        there[name].first-=_damage;
        if(there[name].first<=0) there.erase(name);
    }
    else if(our.find(name)!=our.end())
    {
        our[name].first-=_damage;
        if(our[name].first<=0) our.erase(name);
    }
    else return false;
    return true;
}


void CreativeStone::print()
{
    map<string,pair<int,int> >::iterator ourIt,thereIt;
    for(ourIt=our.begin(),thereIt=there.begin();ourIt!=our.end() && thereIt!=there.end();++ourIt,++thereIt)
    {
        cout<<ourIt->first<<" "<<ourIt->second.first<<" "<<ourIt->second.second<<" / ";
        cout<<thereIt->first<<" "<<thereIt->second.first<<" "<<thereIt->second.second<<endl;
    }
    for(;ourIt!=our.end();++ourIt)
        cout<<ourIt->first<<" "<<ourIt->second.first<<" "<<ourIt->second.second<<endl;
    for(;thereIt!=there.end();++thereIt)
        cout<<" / "<<thereIt->first<<" "<<thereIt->second.first<<" "<<thereIt->second.second<<endl;
}

















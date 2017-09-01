//2015004011
#include "reply_admin.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;


ReplyAdmin::ReplyAdmin()
{
    itor = chats.begin();
    //this->chats = new string[NUM_OF_CHAT];
   
    addChat("Hello, Reply Administrator!");
    addChat("I will be a good programmer.");
    addChat("This class is awesome.");
    addChat("Professor Lim is wise.");
    addChat("Two TAs are kind and helpful.");
    addChat("I think male TA looks cool.");

}

ReplyAdmin::~ReplyAdmin()
{
    }


bool ReplyAdmin::addChat(string _chat)
{
    int count= (int)chats.size();
    if(count==0) chats.push_front(_chat);
    else chats.push_back(_chat);
        return true;
}
bool ReplyAdmin::removeChat(int _index) //remove
{
    int i=0;
    for(itor=chats.begin();itor !=chats.end();itor++,i++)
    {
        if(i == _index)
        {   chats.erase(itor); break;}
            
        
    }
    
    return true;
}
bool ReplyAdmin::removeChat(int *_indices, int _count) // #remove #,#,#,#
{
    int del =0;
    
    for(int i =0; i<_count; i++)
    {
        removeChat(_indices[i]-del);//
        del++;
    }
    return true;

}
bool ReplyAdmin::removeChat(int _start, int _end)// #remove #-#
{
    for(int i=0;i<=(_end-_start);i++)
    {
        removeChat(_start);
    }
    return true;
}

void ReplyAdmin::printChat()
{
    int i=0;
    for(itor=chats.begin();itor !=chats.end();itor++,i++)
    {
       cout << i << " " << *itor << endl;
    }

}


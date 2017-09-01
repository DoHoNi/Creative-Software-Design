//2015004011
#include "reply_admin.h"
#include <iostream>
#include <string>

using namespace std;


ReplyAdmin::ReplyAdmin()
{
    this->chats = new string[NUM_OF_CHAT];
    
    addChat("Hello, Reply Administrator!");
    addChat("I will be a good programmer.");
    addChat("This class is awesome.");
    addChat("Professor Lim is wise.");
    addChat("Two TAs are kind and helpful.");
    addChat("I think male TA looks cool.");

}

ReplyAdmin::~ReplyAdmin()
{
    delete[] chats;
}

int ReplyAdmin::getChatCount()
{
    int i;
    for(i=0; i<NUM_OF_CHAT; ++i)
    {
        string s = this->chats[i];
        if(s.empty() == true) break;
    }
    return i;
}


bool ReplyAdmin::addChat(string _chat)
{
    this->chats[getChatCount()] =_chat;
    return true;
}
bool ReplyAdmin::removeChat(int _index) //remove
{
    
    int count =getChatCount();
    for(int i=_index;i<count;i++)
        this->chats[i]=this->chats[i+1];
    this->chats[count]="";
    
    return true;
}
bool ReplyAdmin::removeChat(int *_indices, int _count) // #remove #,#,#,#
{
    int del =0;
    
    for(int i =0; i<_count; i++)
    {
        removeChat(_indices[i]-del);
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
    int count = getChatCount();
    for(int i=0; i<count; ++i)
    {
        cout << i << " " << this->chats[i] << endl;
    }
}


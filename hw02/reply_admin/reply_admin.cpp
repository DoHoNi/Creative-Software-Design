#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

const int NUM_OF_CHAT = 200;

int getChatCount(string *_chatList)
{
    int i;
    for(i=0; i<NUM_OF_CHAT; ++i)
    {
        string s = _chatList[i];
        if(s.empty() == true) break;
    }
    return i;
}

void printChat(string *_chatList)
{
    int count = getChatCount(_chatList);
    for(int i=0; i<count; ++i)
    {
        cout << i << " " << _chatList[i] << endl;
    }
}

// Implement these functions
bool addChat(string *_chatList, string _chat)
{

        _chatList[getChatCount(_chatList)] =_chat;
    return true;
}// returns true when adding chat is succeeded
bool removeChat(string *_chatList, int _index)
{
    int count =getChatCount(_chatList);
    for(int i=_index;i<count;i++)
        _chatList[i]=_chatList[i+1];
    _chatList[count]="";
    
        return true;
}// returns true when removing chat is succeeded

int makenum(int first, int last,string _chatList){
    int num=0;
    
    for(int i=first;i<last;++i) num=num*10+(_chatList[i]-'0');
    return num;
}


// Implement commented (/* */) areas in main function
int main(void)
{
    string* chats = new string[NUM_OF_CHAT];
    bool result ;
    addChat(chats, "Hello, Reply Administrator!");
    addChat(chats, "I will be a good programmer.");
    addChat(chats, "This class is awesome.");
    addChat(chats, "Professor Lim is wise.");
    addChat(chats, "Two TAs are kind and helpful.");
    addChat(chats, "I think male TA looks cool.");
    
    while(true)
    {
        string command;
        getline(cin, command);
        
        if(command[0]=='#'){
            if(command=="#quit") break;
            else if(command.substr(0,7)=="#remove")
            {
                /* remove chat */
                if(command.find(",")!=string::npos)
                {
                    int remove_count=0;
                    int remove_num=8;
                    
                    int last_count =getChatCount(chats);
                    int first =(int)command.find_first_of(",");
                    int last =command.length();
                    for (;; )
                    {
                        int num=makenum(remove_num,first,command);
                        
                        
                        result=removeChat(chats, num - remove_count);
                        remove_count ++;
                        
                        if(first!=last)remove_num = first+1;
                        if(first==last) break;
                        first=(int)command.find(",",first+1);
                            if(first<0)first=last;
                        
                      
                    }
                    
                   // remove_upup(chats,last_count,remove_count);
                    printChat(chats);
                    
                }
                else if(command.find("-")!=std::string::npos)
                {
                   
                    int last_count =getChatCount(chats);
                    int first =(int)command.find_first_of("-");
                    int last =(int)command.length();
                 
                    int start = makenum(8, first, command);
                    int end = makenum(first+1, last, command);
                    
                    for(int i=start;i<=end;i++)
                        result =removeChat(chats, start);
                    
                    printChat(chats);
                }
                else
                {
                    int last_count =getChatCount(chats);
                    int length=(int)command.length();
                    result=removeChat(chats, makenum(8,length,command));
                    printChat(chats);
                }
                
            
            }
            
        }
        else if(addChat(chats, command)){printChat(chats);}
        
    }
    
    // delete chatting list
    delete[] chats;
    
    return 0;
}

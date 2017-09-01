

#include "message_book.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MessageBook::MessageBook()
{

}
MessageBook::~MessageBook()
{

}
void MessageBook::AddMessage(int number, const string& message)
{
    if(messages_.find(number)==messages_.end())
    {
        messages_[number]=message;
    }
    else
    {
        messages_.erase(number);
        messages_[number]=message;
    }
    
}
void MessageBook::DeleteMessage(int number)
{
    messages_.erase(number);
}
vector<int> MessageBook::GetNumbers() const
{
    map<int, string>::const_iterator it_map = messages_.begin();
    vector<int> numbers;
    
    for(;it_map !=messages_.end();it_map++)
    {
        numbers.push_back(it_map->first);
    }
    return numbers;
}
const string& MessageBook::GetMessage(int number) const
{
    map<int, string>::const_iterator it_map = messages_.find(number);
    
    return it_map->second;
    
}
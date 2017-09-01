

#ifndef __message_book__message_book_main__
#define __message_book__message_book_main__

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

class MessageBook {
public:
    MessageBook();
    ~MessageBook();
    void AddMessage(int number, const string& message);
    void DeleteMessage(int number);
    vector<int> GetNumbers() const;
    const string& GetMessage(int number) const;
    
private:
    map<int, string> messages_;
};


#endif /* defined(__message_book__message_book_main__) */

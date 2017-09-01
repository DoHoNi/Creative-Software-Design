
#include "omok.h"
#include <iostream>

using namespace std;

int main()
{
    Omok omok;
    int x, y;
    int turn = NOBODY;
    int winner=NOBODY;
    
    while(winner==NOBODY)
    {
        if(omok.Turn()==WHITE || omok.Turn()==NOBODY)
        {
            cout <<"Black: ";
            cin >> x >> y;
            turn=omok.Put(x, y);
            omok.IsOmok(&winner);
            
            
        }
        else if(omok.Turn()==BLACK)
        {
            cout <<"White: ";
            cin >> x >> y;
            turn=omok.Put(x, y);
            omok.IsOmok(&winner);

        }
        
    }
    
    cout << omok;
}
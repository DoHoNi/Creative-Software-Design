

#include "omok.h"
#include <iostream>

using namespace std;

int Omok::Put(int x, int y)
{
    if(omokpan[y][x]!=NOBODY || x<0||x>18||y<0||y>18)
    {
        cout << "Can not be placed there." << endl;
        return NOBODY;
    }
    
    if(turn_==NOBODY || turn_==WHITE)
    {
        turn_=BLACK;
    }
    else if(turn_==BLACK) turn_=WHITE;
    
    omokpan[y][x] = turn_;
    
    return turn_;
}

void Omok::IsOmok(int* winner) const
{
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<19;j++)
        {
            if(omokpan[i][j]==turn_)
            {
                if(j+4<19 && omokpan[i][j+5]!=turn_)
                {
                    if(omokpan[i][j+1]==turn_ && omokpan[i][j+2]==turn_ &&
                       omokpan[i][j+3]==turn_ && omokpan[i][j+4]==turn_ )
                    {
                        *winner = turn_;
                    }
                }
                if(j+4<19 && i-4>=0&& omokpan[i-5][j+5]!=turn_)
                {
                    if(omokpan[i-1][j+1]==turn_ && omokpan[i-2][j+2]==turn_ &&
                       omokpan[i-3][j+3]==turn_ && omokpan[i-4][j+4]==turn_ )
                    {
                        *winner = turn_;
                    }
                }
                if(i+4<19 && omokpan[i+5][j]!=turn_)
                {
                    if(omokpan[i+1][j]==turn_ && omokpan[i+2][j]==turn_ &&
                       omokpan[i+3][j]==turn_ && omokpan[i+4][j]==turn_ )
                    {
                        *winner = turn_;
                    }
                }
                if(i+4<19&& j+4<19 && omokpan[i+5][j+5]!=turn_)
                {
                    if(omokpan[i+1][j+1]==turn_ && omokpan[i+2][j+2]==turn_ &&
                       omokpan[i+3][j+3]==turn_ && omokpan[i+4][j+4]==turn_ )
                    {
                        *winner = turn_;
                    }
                }
            }
        }
    }
}


// 오목 판 출력
std::ostream& operator<<(std::ostream& os, const Omok& omok)
{
    for(int i=0; i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(omok.omokpan[i][j]==NOBODY)
                os << ". ";
            else if(omok.omokpan[i][j]==BLACK)
                os << "o ";
            else if(omok.omokpan[i][j]==WHITE)
                os << "x ";
        }
        os << endl;
    }
    
    if(omok.turn_ == BLACK)
        cout << "Winner: Black player" << endl;
    if(omok.turn_ == WHITE)
        cout << "Winner: White player" << endl;
    return os;

}

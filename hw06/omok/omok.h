

#ifndef __omok__omok__
#define __omok__omok__

#include <iostream>


#define BLACK -1
#define NOBODY 0
#define WHITE 1
#define GROUND_SIZE 19

class Omok {
public:
    Omok() : width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(NOBODY)
    {
        for(int i=0; i<19;i++)
        {
            for(int j=0;j<19;j++)
            {
                omokpan[i][j]=NOBODY;
            }
        }
    }
    int Put(int x, int y);
    
    void IsOmok(int* winner) const;
    
    int Turn() const { return turn_; }
    
    friend std::ostream& operator<<(std::ostream& os, const Omok& omok);
    
private:
    int width_, height_;
    int turn_;  // 마지막에 플레이한 턴을 저장
    int omokpan[19][19];// 멤버 변수를 추가.
};

// 오목 판 출력
std::ostream& operator<<(std::ostream& os, const Omok& omok);

//* 필요시 private 멤버 변수 및 함수, friend 선언 추가.


#endif /* defined(__omok__omok__) */

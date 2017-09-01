//
//  main.cpp
//  minesweeper
//
//  Created by 김도현 on 2015. 10. 11..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "minesweeper.h"
#include <stdlib.h>

using namespace std;



bool Minesweeper::setMap(size_t _width, size_t _height, vector<string>& _map)
{
    string temp;
    hei=_height;
    wid=_width;
    cMap.clear();
    for(int i = 0 ; i< hei ; i++)
    {
        string str;
        cin >> str;
        if(str.size()!=wid)return false;
        cMap.push_back(str);
        for(int j=0;j<wid;++j)
            if(str[j]!='*' && str[j]!='.')
                return false;
    }
    numberChk();
    return true;
}


void Minesweeper::numberChk()
{
    for(int i=0;i<hei;++i)
    {
        for(int j = 0 ; j < wid ; j++)
        {
            if(cMap[i][j] != '*')
            {
                cMap[i][j] = '0';
            }
        }
    }
    
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    
    for (int i = 0 ; i < hei ; i++)
    {
        for( int j = 0  ; j < wid ; j++)
        {
            if(cMap[i][j] == '*')
            {
                for(int k=0;k<8;++k)
                {
                    int nextX=i+dx[k],nextY=j+dy[k];
                    if(nextX<0 || nextX>=hei || nextY<0 || nextY>=wid) continue;
                    if(cMap[nextX][nextY]=='*')continue;
                    cMap[nextX][nextY]++;
                }
            }
        }
    }
    
    
    for (int i = 0 ; i < hei ; i++)
    {
        for( int j = 0  ; j < wid ; j++)
        {
            cout<< cMap[i][j];
        }
        cout <<endl;
    }

}

bool Minesweeper::toggleMine(int _x, int _y)
{
    if(get(_x,_y)==' ') return false;
    if(cMap[_x][_y] == '*')
    {
        cMap[_x][_y] = '0';
    }
    else
    {
        cMap[_x][_y] = '*';
    }
    
    numberChk();
    
    return true;
}

char Minesweeper::get(int _x, int _y) const
{
    if(_x<0 || _x>=hei || _y<0 || _y>=wid)return ' ';
    return cMap[_x][_y];
}

bool Minesweeper::setPlay()
{
    tCount=1;
    playMap=vector<string>(hei);
    for(int i=0;i<hei;++i)
    {
        for(int j=0;j<wid;++j)
            playMap[i].push_back('_');
    }
    playPrint();
    return true;
}

bool Minesweeper::touchMap(int _x, int _y)
{
    if(get(_x,_y)==' ')return false;
    else if(get(_x,_y)=='*')
    {
        cout<<"DEAD("<<touchCount()<<")"<<endl;
        return false;
    }
    else
    {
        ++tCount;
        playMap[_x][_y]=get(_x,_y);
        playPrint();
        return true;
    }
}

void Minesweeper::playPrint()
{
    for(int i=0;i<hei;++i)
    {
        cout<<playMap[i]<<endl;
    }
}

Minesweeper::Minesweeper(){}
Minesweeper::~Minesweeper(){}

// return false when input is incorrect
//bool setMap(size_t _width, size_t _height, vector<string>& _map);


// return map width, height, and char
size_t Minesweeper::width() const { return wid; }
size_t Minesweeper::height() const{ return hei; }
//char Minesweeper::get(int _x, int _y) const{} // return ' ' if input is illegal

////////// 4-3-2 (3 score) //////////
//bool Minesweeper::setPlay(){} // return false when map is not set
//bool Minesweeper::touchMap(int _x, int _y){} // return true when dead

int Minesweeper::touchCount() const{ return tCount; }

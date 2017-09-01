//
//  torrent.cpp
//  torrent
//
//  Created by 김도현 on 2015. 10. 30..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "torrent.h"
#include <iostream>
#include <string>

using namespace std;


    Torrent::Torrent(){}

    Torrent::Torrent(const Torrent& torrent)
    {
        name_=torrent.name_;
        seeder_=torrent.seeder_;
        maxsize_= torrent.maxsize_;
        download_= torrent.download_;
        
    }
    Torrent::Torrent(const string& name, int maxSize, int seeder)
    {
        name_ = name;
        maxsize_ = maxSize;
        seeder_ = seeder;
    }
    int Torrent::download(){return download_;}
    string Torrent::name() const{return name_;}  // 토렌트 파일의 이름
    int Torrent::seeder() const{return seeder_ ;}  // seeder의 수
            
    int Torrent::maxSize() const{return maxsize_;}
   // int Torrent::download() { return download_;}// 다운로드가 완료됐을 때의 토렌트 파일의 크기

    int Torrent::download(int _second)
    {
        download_ += seeder_*_second;
        return download_;
    } // _second만큼 다운로드된 이후 용량 return

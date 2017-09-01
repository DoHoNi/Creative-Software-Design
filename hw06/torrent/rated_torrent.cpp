//
//  rated_torrent.cpp
//  torrent
//
//  Created by 김도현 on 2015. 10. 30..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "rated_torrent.h"
#include<string>

    RatedTorrent::RatedTorrent(){}
    RatedTorrent::RatedTorrent(const Torrent& torrent)
    {
        
    }
RatedTorrent::RatedTorrent(const std::string& name, int maxSize, int seeder, int rating) : Torrent(name,maxSize,seeder)
    {
        rating_=rating;
    }

    
RatedTorrent::RatedTorrent(const Torrent& torrent, int rating) : Torrent(torrent)
    {
    
    rating_=rating;

    }
// ‘torrent(***)' 처럼 평가 점수를 원래 이름에 추가하여 리턴 (최고점은 5점)
std::string RatedTorrent::changename() const {
    
    std::string newname = Torrent::name()+"(";
    for (int i=0; i<rating_; i++)
    {
        newname += "*";
    }
    newname += ")";
    return newname;
}


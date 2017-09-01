//
//  rated_torrent.h
//  torrent
//
//  Created by 김도현 on 2015. 10. 30..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __torrent__rated_torrent__
#define __torrent__rated_torrent__

#include "torrent.h"
#include <iostream>
#include <string>


class RatedTorrent : public Torrent {
public:
    RatedTorrent();
    RatedTorrent(const Torrent& torrent);
    RatedTorrent(const std::string& name, int maxSize, int seeder, int rating);
    RatedTorrent(const Torrent& torrent, int rating);
    
    // ‘torrent(***)' 처럼 평가 점수를 원래 이름에 추가하여 리턴 (최고점은 5점)
    std::string changename() const;
   // std::string name() const;
    
    // 필요시 함수 추가 구현 가능
    
private:
    
    int rating_;
    
};
#endif /* defined(__torrent__rated_torrent__) */

//
//  torrent_client.h
//  torrent
//
//  Created by 김도현 on 2015. 10. 30..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __torrent__torrent_client__
#define __torrent__torrent_client__

#include "torrent.h"
#include "rated_torrent.h"
#include <iostream>
#include <vector>
#include <string>

class TorrentClient {
public:
    TorrentClient();
    // 필요한 함수 자유롭게 구현
    void InsertTorrent(Torrent& torrent);
    void InsertRatedTorrent(RatedTorrent& ratedtor);
    void ChangeRating(std::string name , int rating );
    void Delete(std::string name);
    void Print();
    void Download(int second);
private:
    std::vector<Torrent> torrents_;  // 토렌트를 저장하는 벡터
    std::vector<RatedTorrent> ratedTorrents_;  // 평가된 토렌트를 저장하는 벡터
    // 그 외 필요한 변수를 추가
};


#endif /* defined(__torrent__torrent_client__) */

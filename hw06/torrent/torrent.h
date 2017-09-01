//
//  torrent.h
//  torrent
//
//  Created by 김도현 on 2015. 10. 30..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __torrent__torrent__
#define __torrent__torrent__

#include <iostream>
#include <string>

class Torrent {
public:
    Torrent();
    Torrent(const Torrent& torrent);
    Torrent(const std::string& name, int maxSize, int seeder);
    
    std::string name() const;  // 토렌트 파일의 이름
    int seeder() const;  // seeder의 수
    
    int maxSize() const; // 다운로드가 완료됐을 때의 토렌트 파일의 크기
    int download(int _second);
    int download();// _second만큼 다운로드된 이후 용량 return
    // 다운로드에 대한 자세한 설명은 아래 참조
    
    // 필요시 함수 추가 구현 가능
    
private:
    std::string name_;
    int seeder_;
    int maxsize_;
    int download_;
};




#endif /* defined(__torrent__torrent__) */

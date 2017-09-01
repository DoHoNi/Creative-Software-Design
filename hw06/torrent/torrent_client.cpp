//
//  torrent_client.cpp
//  torrent
//
//  Created by 김도현 on 2015. 10. 30..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "torrent_client.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

TorrentClient::TorrentClient(){}

void TorrentClient::InsertTorrent(Torrent& torrent)
{
    torrents_.push_back(torrent);
}
void TorrentClient::InsertRatedTorrent(RatedTorrent& torrent)
{
    ratedTorrents_.push_back(torrent);
}
void TorrentClient::ChangeRating(string name , int rating )
{
    int i;
    for(i=0; i<torrents_.size(); i++)
    {
        if(torrents_[i].name() == name)break;
    }
    RatedTorrent ratedtor(torrents_[i], rating);
    
    ratedTorrents_.push_back(ratedtor);
    torrents_.erase(torrents_.begin()+i);
}

void TorrentClient::Delete(string name)
{
    int i;
    for(i=0; i<torrents_.size(); i++)
    {
        if(torrents_[i].name() == name)break;
    }
    
    if(i == torrents_.size())
    {
        int j;
        for(j=0; j<ratedTorrents_.size(); j++)
        {
            if(ratedTorrents_[j].name() == name) break;
        }
        
        if( j == ratedTorrents_.size())
        {
            cout <<"invalid operation." <<endl;
        }
        else ratedTorrents_.erase(ratedTorrents_.begin()+j);
    }
    else{
        torrents_.erase(torrents_.begin()+i);
    }
}
void TorrentClient::Print()
{
    for(int j=0; j <ratedTorrents_.size(); j++)
    {
        cout << ratedTorrents_[j].download() << "/" << ratedTorrents_[j].maxSize() << " "  << ratedTorrents_[j].changename()<<endl;
    }
    for(int i=0; i < torrents_.size(); i++)
    {
        cout << torrents_[i].download() << "/" << torrents_[i].maxSize() << " " << torrents_[i].name()<<endl;
    }
}
void TorrentClient::Download(int second)
{
    for(int i=0; i < torrents_.size(); i++)
    {
        if(torrents_[i].maxSize()<=torrents_[i].download(second))
        {
    
            torrents_.erase(torrents_.begin()+i);
        }
    }
    for(int j=0; j <ratedTorrents_.size();j++)
    {
        if(ratedTorrents_[j].maxSize()<=ratedTorrents_[j].download(second))
        {
            ratedTorrents_.erase(ratedTorrents_.begin()+j);
            j--;
        }
    }

}







//
//  main.cpp
//  torrent
//
//  Created by 김도현 on 2015. 10. 30..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include <iostream>
#include "torrent.h"
#include "rated_torrent.h"
#include "torrent_client.h"
#include <string>
using namespace std;
int main() {
    string inputs;
    TorrentClient client;
    while(1)
    {
        cin >> inputs;
        
        if(inputs=="quit")return 0;
        else if(inputs =="add")
        {
            string name;
            int seeder, maxsize;
            cin >> name >> maxsize >> seeder ;
            Torrent tor(name,maxsize,seeder);
            client.InsertTorrent(tor);
        }
        else if(inputs == "rate")
        {
            string name;
            int rating;
            cin >> name >> rating;
            client.ChangeRating(name, rating);
        }
        else if(inputs == "add_rate")
        {
            string name;
            int seeder, maxsize,rating;
            cin >> name >> maxsize >> seeder >> rating;
            RatedTorrent ratedtor(name,maxsize,seeder,rating);
            client.InsertRatedTorrent(ratedtor);
            
        }
        else if(inputs == "delete")
        {
            string name;
            cin >> name;
            client.Delete(name);

        }
        else if(inputs =="print")
        {
            client.Print();

        }
        else if(inputs =="download")
        {
            int second;
            cin  >> second;
            client.Download(second);
        }
    }
    
}

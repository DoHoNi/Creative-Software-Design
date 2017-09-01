//
//  main.cpp
//  aus_vote
//
//  Created by 김도현 on 2015. 11. 28..
//  Copyright (c) 2015년 김도현. All rights reserved.
//


#include "aus_vote.h"
#include <iostream>

typedef vector<Candidate> RoundResult;

int main() {
    int cand_su, vote_su;
    vector<string> cand_name;
    vector<int>  vote_rank;
    int vrank;
    string cname;
    
    cin >> cand_su;
    
    for(int i=0; i<cand_su; i++)
    {
        
        cin>>cname;
        //cout << i << cname;
        cand_name.push_back(cname);
    }
    AusVoteSystem votesystem(cand_name);
    
    cin >> vote_su;
    
    for(int i=0; i<vote_su ;i++)
    {
        for(int j=0; j<cand_su; j++)
        {
            cin >> vrank;
            //cout << j << vrank;
            vote_rank.push_back(vrank);
        }
        if(votesystem.AddVote(vote_rank))
            vote_rank.clear();
    }
    
    
    vector<RoundResult> result = votesystem.ComputeResult();
    
    for(int i=0; i<result.size(); i++)
    {
        cout << "Round " << i+1 << ": ";
        for(int j=0; j<cand_su; j++)
        {
            
            if(i==0 || (i>0 && result[i][j].votes!=0))
            cout << result[i][j].name << " " <<  result[i][j].votes << " ";
        }
        cout << endl;
    }
    
    int max=0;
    string final_name;
    for(int i =0; i< cand_su; i++)
    {
        if( max < result[result.size()-1][i].votes)
        {
            max =result[result.size()-1][i].votes;
            final_name = result[result.size()-1][i].name;
            
        }
    }
    
    int min = max;
    for(int i =0; i< cand_su; i++)
    {
        if(min > result[result.size()-1][i].votes)
        {
            min =result[result.size()-1][i].votes;
        }
    }
    
    
    if(max==min)
        cout << "Winner:" << endl;
    else if(max>min)
        cout << "Winner: " << final_name << endl;
    
    return 0;
    
}

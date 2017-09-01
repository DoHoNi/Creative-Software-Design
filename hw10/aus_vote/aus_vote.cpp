
#include <iostream>
#include "aus_vote.h"

typedef vector<Candidate> RoundResult;
vector<RoundResult> AusVoteSystem::ComputeResult() const
{
    vector< vector<int> > allvote = all_vote_;
    vector<RoundResult> roundresult;
    RoundResult result;
    Candidate cand;
    for(int i=0; i < candidate_names_.size(); i++ )
    {
        cand.name = candidate_names_[i];
        cand.votes =0;
        result.push_back(cand);
    }
   
    while(1)
    {
        int vote;
        for(int i=0; i<all_vote_.size();i++)
        {
            for(int j=0; j<all_vote_[i].size(); j++)
            {
                if(allvote[i][j]!=-1)
                {
                vote = all_vote_[i][j];
                result[vote-1].votes++;
                    break;
                }
            }
        }
        
        int max=0;
        for(int i=0; i<candidate_names_.size(); i++) //가장 많은 득표수
        {
            if(max < result[i].votes)
            {
                max = result[i].votes;
            }
        }
        
        if(max > vote_su_/2) //과반수이상
        {
            roundresult.push_back(result);
            return roundresult;
        }
        
        int min=max;
        
        for(int i=0; i<candidate_names_.size(); i++) //가장 적은 득표수
        {
            if(min > result[i].votes)
            {
                if(result[i].votes!=0)
                {
                    min = result[i].votes;
            
                }
            }
        }
        
        if (max == min)
        {
            roundresult.push_back(result);
            return roundresult;
        }
        
        //가장 적은 득표자 지우기
        for( int i=0; i<allvote.size(); i++)
        {
        
                for(int j=0; j<allvote[i].size(); j++)
                {
                    if(min == result[allvote[i][j]-1].votes)
                    {
                        allvote[i][j] = -1;
                    }
                }
        }
        roundresult.push_back(result);
       
        for(int i=0; i<result.size();i++)
        {
            result[i].votes=0;
        }
        
        
        
        
        
    }
    
    

}
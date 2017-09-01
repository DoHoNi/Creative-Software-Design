//
//  aus_vote.h
//  aus_vote
//
//  Created by 김도현 on 2015. 11. 28..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __aus_vote__aus_vote__
#define __aus_vote__aus_vote__

#include <string>
#include <vector>

using namespace std;

struct Candidate {
    std::string name;
    int votes;
};

class AusVoteSystem {
public:
    AusVoteSystem(const vector<string>& candidate_names):candidate_names_(candidate_names),vote_su_(0){}
    
    // 후보별 선호도를 1순위부터 입력.
    // 잘못된 숫자가 있거나 선호도 수가 후보자 수와 다르면
    // 해당 입력을 무시하고 false를 리턴.
    bool AddVote(const vector<int>& vote)
    {
        all_vote_.push_back(vote);
        vote_su_++;
        return true;
    }
    
    typedef vector<Candidate> RoundResult;
    // 지금까지의 투표를 바탕으로 결과를 모든 라운드에 대해 계산.
    // main() 에서는 vector<RoundResult>를 출력형식에 맞도록 출력.
    vector<RoundResult> ComputeResult() const;
    
private:
    int vote_su_ ;
    vector< vector<int> > all_vote_;
    vector<string> candidate_names_;
    // 입력받은 투표를 계산에 적합한 방식으로 저장하는 멤버 변수를 설계.
};

#endif /* defined(__aus_vote__aus_vote__) */

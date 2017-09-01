//
//  grader.cpp
//  grader
//
//  Created by 김도현 on 2015. 11. 23..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "grader.h"


string SubjectPassFail::GetGrade(int score) const
{
    if(score >= pass_score_)
        return "P";
    else
        return "F";
}

string SubjectGrade::GetGrade(int score) const
{
    if(score >=cutA_)
        return "A";
    else if(score >=cutB_)
        return "B";
    else if(score >=cutC_)
        return "C";
    else if(score >=cutD_)
        return "D";
    else
        return "F";
}

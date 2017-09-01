//
//  grader.h
//  grader
//
//  Created by 김도현 on 2015. 11. 23..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __grader__grader__
#define __grader__grader__

#include <string>
using namespace std;

// 0~100점의 성적을 학점으로 변환하는 클래스. 과목 이름과 시수를 저장.
class Subject {
public:
    Subject(const string& name, int credit)
    : name_(name), credit_(credit) {}
    virtual ~Subject() {}
    
    const string& name() const { return name_; }
    int credit() const { return credit_; }
    virtual string GetGrade(int score) const = 0;
    
private:
    string name_;
    int credit_;
};

// 성적을 Pass / Fail 로 구분하여 출력해주는 클래스.
// 성적이 pass_score보다 같거나 높으면 "P", 아니면 "F"를 리턴.
class SubjectPassFail : public Subject {
public:
    SubjectPassFail(const string& name, int credit, int pass_score): Subject(name, credit), pass_score_(pass_score){};
    virtual ~SubjectPassFail(){}
    
    virtual string GetGrade(int score) const;
    
private:
    int pass_score_;
};

// 성적을 A, B, C, D, F 로 구분하여 출력해주는 클래스.
// 성적이 속하는 구간에 따라
// 100 >= "A" >= cutA > "B" >= cutB > "C" >= cutC > "D" >= cutD > "F".
class SubjectGrade : public Subject {
public:
    SubjectGrade(const string& name, int credit,
                 int cutA, int cutB, int cutC, int cutD):Subject(name, credit), cutA_(cutA),cutB_(cutB),
    cutC_(cutC),cutD_(cutD){};
    virtual ~SubjectGrade(){}
    
    virtual string GetGrade(int score) const;
    
private:
    int cutA_, cutB_, cutC_, cutD_;
};

//* Class 멤버 함수, 변수 및 구조 변경 금지


#endif /* defined(__grader__grader__) */

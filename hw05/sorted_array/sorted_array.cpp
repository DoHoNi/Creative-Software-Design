//
//  sorted_array.cpp
//  sorted_array
//
//  Created by 김도현 on 2015. 10. 13..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#include "sorted_array.h"

#include <iostream>
#include <vector>


using namespace std;

SortedArray::SortedArray()
{
}
SortedArray::~SortedArray()
{
}

void SortedArray::AddNumber(int num)
{
    numbers_.push_back(num);
}

vector<int> SortedArray::GetSortedAscending() const
{
    int temp;
    vector<int> sortup = numbers_;
    
    for(int i = 0;i < sortup.size()-1;i++)
    {
        for(int j = i + 1;j < sortup.size();j++)
        {
            if(sortup[i] > sortup[j])
            {
                temp = sortup[i];
                sortup[i] = sortup[j];
                sortup[j] = temp;
            }
        }
    }
    
    return sortup;
}
vector<int> SortedArray::GetSortedDescending() const
{
    int temp;
    vector<int> sortup = numbers_;
    for(int i = 0;i < sortup.size()-1;i++)
    {
        for(int j = i + 1;j < sortup.size();j++)
        {
            if(sortup[i] < sortup[j])
            {
                temp = sortup[i];
                sortup[i] = sortup[j];
                sortup[j] = temp;
            }
        }
    }
    
    return sortup;
}
int SortedArray::GetMax() const
{
    int max = 0;
    for(int i=0; i<numbers_.size();i++)
    {
        if(max<numbers_[i])
            max = numbers_[i];
    }
    return max;
}
int SortedArray::GetMin() const
{
    int min = numbers_[0];
    for(int i=0; i<numbers_.size();i++)
    {
        if(min>numbers_[i])
            min = numbers_[i];
    }
    return min;

}
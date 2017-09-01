//
//  sorted_array.h
//  sorted_array
//
//  Created by 김도현 on 2015. 11. 9..
//  Copyright (c) 2015년 김도현. All rights reserved.
//

#ifndef __sorted_array__sorted_array__
#define __sorted_array__sorted_array__

#include <iostream>
using namespace std;

template <typename T>
class SortedArray {
public:
    SortedArray()
    {
        values_ = NULL;
        size_ = 0; alloc_ =0;
    }
    SortedArray(const SortedArray& a)
    {
        Reverse(a.size());
        for(int i = 0; i< a.size(); i++)
            values_[i] = a(i);
    }
    SortedArray(size_t size)
    {
        Reserve(size);
    }
    ~SortedArray()
    {
        delete[]values_;
    }
    
    SortedArray& operator=(const SortedArray& a)
    {
        Reserve((int)a.size());
        for(int i =0; i<a.size(); i++)
            values_[i] = a(i);
        return *this;
    }
    
    size_t size() const { return size_; }
    
    const T& operator()(int idx) const
    {
        return values_[idx];
    }
    
    void Reserve(int size)
    {
        size_ = size;
        values_= new T[size];
    }
    void Add(const T& value)
    {
        values_[alloc_] = value;
        alloc_++;
        Sort();
    }
    
    void Sort()
    {
        for(int i = 0; i < alloc_ - 1; i++)
        {
            for(int j = 0; j < alloc_ - (i + 1); j++)
            {
                if(values_[j] > values_[j + 1])
                {
                    T temp = values_[j + 1];
                    values_[j + 1] = values_[j];
                    values_[j] = temp;
                }
            }
        }
   
    }
    int Find(const T& value)
    {
        Sort();
        
        int left = 0;
        int right = size_- 1;
        int mid;
        
        while(left<=right)
        {
            mid = (left + right) / 2;
            
            if(values_[mid] == value) {
                return mid;
            }
            else if (values_[mid] < value)
            {
                left = mid + 1;
            }
            else if (values_[mid] > value)
            {
                right = mid - 1;
            }
           
        }
        
        return -1;
        
    }
    // 주어진 값의 위치, 없으면 -1을 리턴.
    // Binary Search를 사용해야 함
    
private:
       T* values_;
    int size_, alloc_;
};

template <typename T>
istream& operator>>(istream& is, SortedArray<T>& a)
{
    int size;
    is >> size;
    a.Reserve(size);
    
    for(int i=0; i < size ;i++)
    {
        T tt;
        is >> tt;
        a.Add(tt);
    }
    return is;

}

template <typename T>
ostream& operator<<(ostream& os, const SortedArray<T>& a)
{
    for(int i=0; i< a.size();i++)
        os << a(i) << " ";
    
    return os;
}



#endif /* defined(__sorted_array__sorted_array__) */

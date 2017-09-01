//2015004011

#include <iostream>
#include "binary_search.h"

void BinarySearch::sortArray()
{
    
    int temp;
    for(int i=0 ; i<(this->mArrayCount)-1;i++)
    {
        for(int j=0; j<(this->mArrayCount)-1-i;j++ )
        {
            if(this->mArray[j] > this->mArray[j+1])
            {
                temp = this->mArray[j];
                this->mArray[j] = this->mArray[j+1];
                this->mArray[j+1] =temp;
            }
        }
    }
    
    for (int i=0; i < mArrayCount- 1; i++)
    {
        if (mArray[i] == mArray[i+1])
        {
            for (int j=i; j < mArrayCount- 1; j++)
                mArray[j] = mArray[j + 1];
            
            mArrayCount--;
            i--;
        }
    }
    return ;

}
BinarySearch::BinarySearch()
{
    mArrayCount =0;
}
BinarySearch::BinarySearch(int *_array, int _arrayCount)
{
    mArray = new int[_arrayCount];
    
    for(int i=0; i<_arrayCount; i++)
        mArray[i] = _array[i];
    
    mArrayCount = _arrayCount;
    sortArray();
}
BinarySearch::~BinarySearch()
{
    delete[] mArray;
}
int BinarySearch::getIndex(int _element) // return -1 when element doesn't exist
{
    int left = 0;
    int right = mArrayCount-1;
    int center =0;
    
    while(1)
    {
        center = (left+right)/2;
        if(mArray[center] < _element)
            left = center +1;
        else if (mArray[center]>_element)
            right = center-1;
        else if(mArray[center]==_element)
            return center;
        
            
        if(left>right) break;
    }
    
    return -1;
    
}
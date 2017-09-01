//2015004011

#include "simple_int_set.h"
#include <iostream>
#include <string>

using namespace std;


void SimpleIntSet::sortElements()
{
    
    int temp;
    for(int i=0 ; i<(this->mElementCount)-1;i++)
    {
        for(int j=0; j<(this->mElementCount)-1-i;j++ )
        {
            if(this->mElements[j] > this->mElements[j+1])
            {
                temp = this->mElements[j];
                this->mElements[j] = this->mElements[j+1];
                this->mElements[j+1] =temp;
            }
        }
    }
    
    for (int i=0; i < mElementCount- 1; i++)
    {
        if (mElements[i] == mElements[i+1])
        {
            for (int j=i; j < mElementCount - 1; j++)
                mElements[j] = mElements[j + 1];
            
            mElementCount--;
            i--;
        }
    }
    return ;
    
}

SimpleIntSet::SimpleIntSet()
{
    mElementCount =0;
}

SimpleIntSet::SimpleIntSet(int *_elements, int _count)
{

    this->mElements = new int[_count];
    
    for(int i=0; i<_count ; i++)
    this->mElements[i] = _elements[i];
    
    this->mElementCount = _count;
    sortElements();
}
SimpleIntSet::~SimpleIntSet()
{
    delete mElements;
}

int* SimpleIntSet::elements() const // return sorted array
{
   
    return this->mElements;
}

int SimpleIntSet::elementCount() const
{
    return this->mElementCount;
}

SimpleIntSet *SimpleIntSet::unionSet(SimpleIntSet& _operand)
{
    int * result = new int[this->mElementCount + _operand.elementCount()];
    int * right_el=_operand.elements();
    int left_size = this->mElementCount;
    int right_size = _operand.elementCount();
    bool no_same =true;
    int count =0;
    
    for(int j=0; j<mElementCount; j++)
        result[j] = mElements[j];
    
    for(int i=0; i<right_size; i++)
    {
        no_same=true;
        
        for(int j=0;j<left_size;j++)
        {
            if(mElements[j]==right_el[i]) no_same=false;
        }
        
        if(no_same==true)
        {
            result[mElementCount+count]=right_el[i];
            count++;
        }
    }
    
    
    mElementCount += count ;
    delete[] mElements;
    mElements = new int[mElementCount];
    
    for(int i=0;i<mElementCount;i++)
        this->mElements[i]= result[i];
    
     sortElements();
    
    
    
    delete[] result;
    return this;

}

SimpleIntSet *SimpleIntSet::differenceSet(SimpleIntSet& _operand)
{
    int * result = new int[this->elementCount()];
    int * right_el=_operand.elements();
    int left_size = this->mElementCount;
    int right_size = _operand.elementCount();
    bool no_same =true;
    int count =0;
    
    for(int i=0;i<left_size;i++)
    {
        no_same=true;
        for(int j=0;j<right_size;j++)
        {
            if(mElements[i]==right_el[j])no_same=false;
        }
        
        if(no_same==true)
        {
            result[count]=mElements[i];
            count++;
        }
    }
    
    mElementCount =count;
    delete[] mElements;
    mElements = new int[mElementCount];
    for(int i=0;i<count;i++)
        this->mElements[i]= result[i];
    
    delete result;
    return this;
    
}
SimpleIntSet *SimpleIntSet::intersectSet(SimpleIntSet& _operand)
{
    int * result = new int[this->elementCount()];
    int * right_el=_operand.elements();
    int left_size = this->mElementCount;
    int right_size = _operand.elementCount();
    bool no_same =true;
    int count =0;
    
    for(int i=0;i<left_size;i++)
    {
        no_same=true;
        for(int j=0;j<right_size;j++)
        {
            if(mElements[i]==right_el[j])no_same=false;
        }
        
        if(no_same==false)
        {
            result[count]=mElements[i];
            count++;
        }
    }
    
    
    mElementCount =count;
    delete[] mElements;
    mElements = new int[mElementCount];
    for(int i=0;i<count;i++)
        this->mElements[i]= result[i];

    
    delete result;
    return this;

    
    
}

void SimpleIntSet::printSet()
{
    cout << "{" << " ";
    for(int i=0; i<this->mElementCount; i++)
    {
        cout << this->mElements[i] << " ";
    }
    cout << "}";
    
}

//1-3 마방진
//2015004011 김도현

#include <iostream>

    using namespace std;

int magic(int **arr_magic, int dan)
{
    for(int i=0; i<dan;i++) //초기화
        
    {
        for(int j=0; j<dan; j++)
            arr_magic[i][j]=0;
    }
    
    arr_magic[0][dan/2]= 1;
    
    for(int num = 2,i=0,j=(dan/2); num <= dan*dan;num++)
    {
        i--;
        j++;
        
        if((i<0 && j>dan-1) || (i>=0 && j>=0 && i<dan && j<dan && arr_magic[i][j]>0))
        { //둘다 범위밖으로 나가거나, 값이있으면 아래로
           
            j--;
            i+=2;
        }
        else if(i<0) i=dan-1;  //i가 0보다 작아지면 맨아래로
            else if(j>dan-1) j=0; // j가 범위보다 커지면 맨앞으로 
    
    
        arr_magic[i][j]=num;
        
        
        
    }
    
    return 0;
}


int main()
{
    int dan;
    cin >> dan;
    if(dan%2==0 ||dan<0)
    {
        return 0;
    }
    
    
    int ** arr_magic = new int*[dan];
    for(int i=0; i<dan;i++)
    {
        arr_magic[i] = new int[dan];
    }
  
    
    magic(arr_magic, dan);
    
    for(int i=0; i<dan;i++)
    {
        for(int j=0; j<dan; j++)
            cout << arr_magic[i][j]<< " ";
        cout<<endl;
    }

    
    
    
    for(int i=0; i<dan;i++)
    {
        delete[] arr_magic[i];
    }
    delete arr_magic;
    
    return 0;
}

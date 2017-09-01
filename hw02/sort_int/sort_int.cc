
//1-4 정렬함수
// 2015004011 김도현

#include <iostream>

    using namespace::std;

int sort(int * sort_arr , int arr_size)
{
    int temp;
    for(int i=0 ; i<arr_size-1;i++)
    {
        for(int j=0; j<arr_size-1-i;j++ )
        {
            if(sort_arr[j] > sort_arr[j+1])
            {
                temp = sort_arr[j];
                sort_arr[j] = sort_arr[j+1];
                sort_arr[j+1] =temp;
            }
        }
    }
    return 0;
}


int main() {
    
    int arr_size;
    cin >> arr_size;
    
    if(arr_size <1) return 0;
    
    int * sort_arr = new int[arr_size];
    
    for(int i=0; i<arr_size; i++)
    {
        cin >> sort_arr[i];
    }
    
    sort(sort_arr,arr_size);
    
    for(int i=0; i<arr_size; i++)
    {
        cout << sort_arr[i] << " ";
    }
    
    return 0;
}

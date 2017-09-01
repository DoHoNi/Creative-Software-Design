

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
 
    /*int num1,num2, x_max=0, y_max=0;
    
    cin >> num1 >> num2;
    
    char **map = new char*[num2+1];
    for(int i=0; i<=num2;i++)
        map[i] = new char[num1+1];
    
    x_max =num1; y_max=num2;
    
    for(int i=0; i<=x_max; i++)
    {
        for(int j=0;j<=y_max; j++)
            map[j][i]='.'
    }
    
    for(;;)
    {
        cin >> num1>> num2;
        if(num1<0 || num2 <0) return 0;
        if(num1> x_max)
    }
    
    
    */
     char arr[100][100];
    
    for(int j=0;j<100;j++){ //배열초기화
        for(int k=0;k<=100;k++){
            arr[j][k]='.';
        }
        
    }

    int num1=1, num2=1, x_max=0, y_max=0;
    
    for(int i=0;;i++){
        
        cin >> num1 >> num2;
        if(num1<0 || num2<0) return 0;
        arr[num2][num1]='*';
        if(num2>y_max) y_max=num2;
        if(num1>x_max) x_max=num1;
        
        for(int j=0;j<=y_max;j++){
            for(int k=0;k<=x_max;k++){
                cout<< arr[j][k] << " ";
            }
            cout << endl;
            
        }
    }
    
    
    return 0;
}

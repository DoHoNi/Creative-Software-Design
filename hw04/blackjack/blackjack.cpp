//2015004011

#include <iostream>
#include <locale>
#include <string>

using namespace std;

int blackjack(string inputs)
{

        int number = -1;
        
        int* numbers = new int[200];
        int numbersCount = 0;
        
        for(int i=0; i<inputs.size(); ++i)
        {
            int c = inputs[i];
            
            if(isdigit(c) == true)
            {
                int num = (int)c - (int)'0';
                
                if(num <0) return -1;
                
                if(number < 0) number = num;
                else number = number * 10 + num;
            }
            else if(isupper(c) ==true) //대문자
            {
                if(inputs[i] == 'J' || inputs[i]=='Q' || inputs[i]=='K')  //J,Q,K =10
                    number=10;
                else if(inputs[i] == 'A')  //A =1
                    number=1;
                else return -1;  //그 외는 return -1
            }
            else if(islower(c)==true) return -1;  //소문자
            else
            {
                numbers[numbersCount++] = number;
                number = -1;
            }
        }
    
        if(numbersCount > 0)
        {
            numbers[numbersCount++] = number; // final number
           
        }
    
    if(numbersCount <2) return -1;
    
    
    // plus number
    int sum =0;
    int exist1 =0;
    
    for(int j=0;j<numbersCount; j++)
    {
        if(j==0) sum -=numbers[j];
        if(numbers[j]!=1)  sum +=numbers[j];
        else exist1++;
    }
    if(exist1 >0)
    {
        for(int i=0; i<exist1;i++)
            sum++;
        for(int i=0; i<exist1;i++)
        {
            if(sum+10<=21) sum +=10;
        }
    }
    
    
    if(sum <= 21)   return sum;
    else return 0;
    
    
    delete[] numbers;
}





int main() {
    // insert code here...
    while (1)
    {
        string inputs;
        getline(cin, inputs);
        int result = blackjack(inputs);
    
        if(result==-1) return 0;
        else if(result == 21) cout << "BlackJack" <<endl;
        else if(result ==0) cout << "Exceed" << endl;
        else cout << result << endl;
    }
}

#include <iostream>

void fib(int x, int f1, int f2) {
    
    if(f1==0)

        std::cout << 1  << " ";

    if(x==1)return;

        int fibo= f1+f2;

        std::cout << fibo << " ";

    fib(x-1,f2,fibo);

}

 

int main() {
    
    int num;

    std::cin >> num;

    fib(num,0,1);

    return 0;


}

 

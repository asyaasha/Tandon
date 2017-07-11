
#include <iostream>
using namespace std;

int fib(int n);


int main() {
    int inputNumber;
    
    cout<<"Please enter a positive integer:";
    cin>>inputNumber;
    
    cout<<fib(inputNumber)<<endl;
    
    return 0;
}

int fib(int n){
    if( n==0)
        return 0;
    else if(n == 1|| n == 2)
        return 1;
    else
        return (fib(n-1) +fib(n-2));
}


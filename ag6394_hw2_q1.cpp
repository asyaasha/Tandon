//Write a program that reads from the user two positive integers, 
//and prints the result of when we add, subtract multiply, divide, div and mod them.

#include <iostream>
using namespace std;

int main() {

    int num1, num2;
    int sum, difference, multiply, modulo, div;
    double divide;
    cout<<"Please enter two	positive integers, separated by	a space:"<<endl;
    cin>>num1>>num2;
    
    sum = num1+ num2;
    difference = num1 - num2;
    multiply = num1 * num2;
    divide = (float)num1 / num2;
    div = num1 / num2;
    modulo = num1 % num2;
    
    cout<<num1<<" + "<<num2<<" = "<<sum<<endl;
    cout<<num1<<" -"<<num2<<" = "<<difference<<endl;
    cout<<num1<<" * "<<num2<<" = "<<multiply<<endl;
    cout<<num1<<" / "<<num2<<" = "<<divide<<endl;
    cout<<num1<<" div "<<num2<<" = "<<div<<endl;
    cout<<num1<<" mod "<<num2<<" = "<<modulo<<endl;
    
    
    return 0;
}

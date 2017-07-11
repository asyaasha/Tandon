
#include <iostream>
using namespace std;


int main() {
   
    int decimalNumber;
    string binaryRepresentation=" ";
    
    do{
    cout<<"Enter decimal number: "<<endl;
    cin>>decimalNumber;
    }
    while (decimalNumber<0);
    cout<<"The	binary	representation	of "<<decimalNumber<<" is ";
    while( decimalNumber>=1)
    {
       binaryRepresentation = to_string(decimalNumber%2)+ binaryRepresentation;
       decimalNumber = decimalNumber/2;
    }
    
    cout<<binaryRepresentation;
    return 0;
}

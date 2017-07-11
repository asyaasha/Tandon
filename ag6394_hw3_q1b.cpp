

#include <iostream>
using namespace std;


int main() {
    
    int integerInput, firstEven = 2;
    do{
    cout<<"Please	enter	a	positive	integer: ";
    cin>>integerInput;
    } while (integerInput <0 );
    
    for (int i = 0; i < integerInput; i++ ){
        cout<<firstEven<<endl;
        firstEven+=2;
    }
    
       return 0;
}

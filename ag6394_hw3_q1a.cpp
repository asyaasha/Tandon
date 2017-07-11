//
//  main.cpp
//  hw3_1
//
//  Created by A on 6/4/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int integerInput, firstEven=2;
    do{
    cout<<"Please	enter	a	positive	integer: ";
    cin>>integerInput;
    }while (integerInput<0);
    
    int i = 0;
    while (i< integerInput)
    {
        cout<<firstEven<<endl;
        firstEven+=2;
        i++;
    }
    
    return 0;
}

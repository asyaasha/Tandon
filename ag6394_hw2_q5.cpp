//
//  main.cpp
//  hw2_q5
//
//  Created by A on 6/2/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

    int methodNumber;
    double inputNumber;
    cout<<"Please enter a Real number:"<<endl;
    cin>>inputNumber;
    cout<<"Choose your rounding method:"<<endl;
    cout<<"1.Floor round"<<endl;
    cout<<"2.Ceiling round"<<endl;
    cout<<"Round to the nearest whole number"<<endl;
    cin>>methodNumber;
    
    switch(methodNumber){
        case FLOOR_ROUND:
            cout<<floor(inputNumber)<<endl;
            break;
        case CEILING_ROUND:
            cout<<ceil(inputNumber)<<endl;
            break;
        case ROUND:
            cout<<round(inputNumber)<<endl;
            break;
        default:
            cout<<"Incorrect option"<<endl;
    }
    
    return 0;
}

//
//  main.cpp
//  hw3_q2
//
//  Created by A on 6/4/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {

    char thousand ='M', fiveHundred = 'D', hundred = 'C', fifty = 'L', ten = 'X', five = 'V', one='I';
    string romanNumber ="";

    int decimalNumber, inputInteger;
    
    cout<<"Enter decimal number: "<<endl;
    cin>>inputInteger;
    //find thousands
    decimalNumber = inputInteger;
    if ( decimalNumber%1000 >=0)
    {
        int counter = decimalNumber/1000;
        for ( int i =0; i< counter; ++i)
        {
            romanNumber += thousand;
        }
        decimalNumber = decimalNumber%1000;
    }
    //find 5 hundreds
    if (decimalNumber>=500)
    {
        romanNumber += fiveHundred;
        decimalNumber = decimalNumber-500;
    }
    //find hundreds
    if ( decimalNumber>=100)
    {
        int counter = decimalNumber/100;
        for ( int i =0; i< counter; ++i)
        {
        romanNumber += hundred;
        }
        decimalNumber = decimalNumber%100;
    }
    //find fifties
    if (decimalNumber>=50)
    {
        romanNumber+=fifty;
        decimalNumber = decimalNumber-50;
    }
    //find tens
    if (decimalNumber>=10)
    {
        int counter = decimalNumber/10;
        for ( int i =0; i< counter; ++i)
        {
            romanNumber += ten;
        }
        decimalNumber = decimalNumber%10;
    }
    if (decimalNumber>=5)
    {
        romanNumber+=five;
        decimalNumber = decimalNumber-5;
    }
    if (decimalNumber>=1)
    {
        int counter = decimalNumber/1;
        for ( int i =0; i< counter; ++i)
        {
            romanNumber += one;
        }
        decimalNumber = decimalNumber%1;
    }
    cout<<inputInteger<<" is "<<romanNumber<<endl;
    return 0;
}

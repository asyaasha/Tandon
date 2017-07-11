//
//  main.cpp
//  hw3_q5
//
//  Created by A on 6/5/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
   
    int inputNumber, row =0;
    char empty =' ', star = '*';
    
    cout<<"Enter a number"<<endl;
    cin>>inputNumber;
    int starsInRow = inputNumber*2;
    while (inputNumber >0){
        for( int i =0; i< row; ++i)
        {
            cout<<empty;
        }
        for (int i =0; i<starsInRow-1; i++)
        {
            cout<<star;
        }
        cout<<endl;
        row+=1;
        starsInRow = starsInRow -2;
        inputNumber = inputNumber - 1;
    }
    while (row > 0){
        for( int i =0; i< row-1; ++i)
        {
            cout<<empty;
        }
        for (int i =0; i<starsInRow+1; i++)
        {
            cout<<star;
        }
        cout<<endl;
        row-=1;
        starsInRow+=2;
    }
    return 0;
}
    

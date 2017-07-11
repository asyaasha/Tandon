//
//  main.cpp
//  hw3_q7
//
//  Created by A on 6/5/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int multipl = 1;
    int inputInteger;
    cout<<"Please enter a positive integer: "<<endl;
    cin>>inputInteger;
    
    while (multipl<= inputInteger)
    {
        for(int i=0; i<inputInteger; i++)
        {
            cout<<(i+1) * multipl<<"\t";
        }
        multipl +=1;
        cout<<endl;
    }
    return 0;
}

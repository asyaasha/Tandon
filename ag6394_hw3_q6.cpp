//
//  main.cpp
//  hw3_q6
//
//  Created by A on 6/7/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    
    int inputInteger;
    cout<<"Please enter a positive integer: ";
    cin>>inputInteger;
    
    for(int i =  1; i<= inputInteger; i++ )
    {
        int evenCount =0, oddCount=0;
        int nextNumber = i;
        while (nextNumber > 0){
        
            if (nextNumber % 2==0)
            {
                evenCount++;
            }
            else {
                oddCount++;
            }
            nextNumber = nextNumber / 10;
        }
 
        if ( evenCount> oddCount)
        {
        cout<<i<<endl;
        }
    }
    return 0;
}

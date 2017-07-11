//
//  main.cpp
//  hw2_que6
//
//  Created by A on 6/2/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>

const double CONVERT_TO_KG = 0.45359237;
const double CONVERT_TO_METERS = 0.0254;

int main() {
    int weightPounds, heightInches;
    string weightStatus;
    double BmiRange;
    
    cout<<"Please enter weight(in pounds):";
    cin>>weightPounds;
    cout<<"Please enter height(in inches):";
    cin>>heightInches;
    BmiRange = (weightPounds* CONVERT_TO_KG)/pow((heightInches*CONVERT_TO_METERS),2);
    
    if (BmiRange <18.5)
        weightStatus="Underweight";
    else if ((BmiRange>18.5) && (BmiRange<25))
        weightStatus="Normal";
    else if  ((BmiRange>25) && (BmiRange<30))
          weightStatus="Overweight";
    else if (BmiRange>30)
         weightStatus="Obese";
    
    cout<<"The weight status is: "<<weightStatus<<endl;
    return 0;
}

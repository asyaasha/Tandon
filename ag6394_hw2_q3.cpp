//
//  main.cpp
//  hw2_3
//
//  Created by A on 5/29/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {

    string name, status;
    
    int graduationYear, currentYear;
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>graduationYear;
    cout<<"Please enter current year: ";
    cin>>currentYear;
    
        if (graduationYear <= currentYear)
        {
            status = "Graduated";
        }
        else if (graduationYear - currentYear == 1)
        {
            status = "Senior";
        }
        else if (graduationYear - currentYear == 2)
        {
            status = "Junior";
        }
        else if (graduationYear - currentYear == 3)
        {
            status = "Sophmore";
        }
        else if (graduationYear - currentYear == 4)
        {
            status = "Freshman";
        }
        else if (graduationYear - currentYear > 4 )
        {
            status = "not in college yet";
        }
    
    cout<<status<<endl;
    cout<<name<<", you are a "<<status<<endl;


    
    
    return 0;
}

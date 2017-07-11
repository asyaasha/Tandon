//
//  main.cpp
//  hw2_4
//
//  Created by A on 5/29/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c;
    double rootOne, rootTwo, determinant;
    cout<<"Please enter value of a";
    cin>>a;
    cout<<"Please enter value of b";
    cin>>b;
    cout<<"Please enter value of c";
    cin>>c;
    
    determinant = (b*b - 4*a*c);
    
    if (a == b == c == 0)
    {
        cout<< "The equation has an infinite number of solutions"<<endl;
    }
    else
    {
        if (determinant< 0)
        {
            rootOne = -b/(2*a);
            rootTwo =sqrt(-determinant)/(2*a);
            cout << "The equation has two imaginary roots"<<rootOne<<" and "<<rootTwo<<endl;        }
        else if (determinant == 0 )
        {
            rootOne = rootTwo = -b/(2*a);
            cout << "The equation has a single root"<<rootOne<<endl;
        }
        else
            rootOne = (-b + sqrt(determinant)) / (2*a);
            rootTwo = (-b - sqrt(determinant)) / (2*a);
            cout << "The equation has two real roots "<<rootOne<<" and "<<rootTwo<<endl;
    }
    return 0;
}

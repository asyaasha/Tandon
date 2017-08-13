
// *Give a recursive implement to the following functions:*
// a. void printTriangle(int n)
// This function is given a positive integer n, and
// prints a textual image of a right triangle
// (aligned to the left) made of n lines with asterisks.
// 
// *
// **
// ***
// ****
//b. void printOpositeTriangles(int n)
// This function is given a positive integer n, and
// prints a textual image of a two opposite right
// triangles (aligned to the left) with asterisks, each containing n lines.
// For example,
// ****
// ***
// **
// *
// **
// ***
// ****
// c. printRuler()
// -
// --
// -
// ---
// -
// --
// -
// ---
// -
// --
// -
#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangles( int n);
void printRuler (int n);

int main() {
//    printTriangle(4);
//     printOpositeTriangles(4);
//    printRuler (4);
    return 0;
}


void printTriangle(int n){
  
    if(n == 1){
        cout<<"*"<<endl;
        
    }
    else{
        printTriangle(n - 1);
        
        for(int i = n; i > 0; i--){
            cout<<"*";
        }
        cout<<endl;
    }
}

void printOpositeTriangles( int n){
    if(n == 1){
        cout<<"*"<<endl;
        cout<<"*"<<endl;
    }
    else{
        for(int i = n; i > 0; i--){
            cout<<"*";
        }
        cout<<endl;
        printOpositeTriangles(n - 1);
        
        for(int i = n; i > 0; i--){
            cout<<"*";
        }
        cout<<endl;
    }
}

void printRuler (int n){
    if(n == 0){
        return;
    }
    else{
    printRuler(n-1);
        for (int i=0; i < n; i++){
            cout << '-';
        }
    cout<<endl;
    printRuler(n-1);
    }
}




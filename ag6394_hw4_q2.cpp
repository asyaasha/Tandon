
#include <iostream>
using namespace std;

void printShiftedTriangle( int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    
    char inputSymbol;
    int numberOfTriangles;
    
    cout<<"Hello, how big the tree should be? Enter the number of triangles: ";cin>>numberOfTriangles;
    cout<<"What symbols should fill it? ";cin>>inputSymbol;
    
    printPineTree(numberOfTriangles, inputSymbol);
    
    return 0;
}

void printShiftedTriangle( int n, int m, char symbol){
    
    char empty =' ';
    int symbolsInRow = 0;
    
    while (n > 0){
        for(int x=0; x <=m; x++){  //shift all
            cout<<empty;
        }
        for( int i =0; i< n-1; ++i) //spaces to make triangle
        {
            cout<<empty;
        }
        for (int i =0; i<symbolsInRow+1; i++)  //fill with symbols
        {
            cout<<symbol;
        }
        cout<<endl;
        n-=1;
        symbolsInRow+=2;
    }
}

void printPineTree(int n, char symbol){
    
    int shift = n - 2;
    int firstTriangle =2;
    int startN =0;
    
    while ( startN < n){
        printShiftedTriangle(firstTriangle, shift, symbol);
        startN++;
        firstTriangle +=1;
        shift -=1;
    }
}

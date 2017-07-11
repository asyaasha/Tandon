#include <iostream>
using namespace std;


const int SIZE = 10;
void enlargeArray(int sortedArr[], int arrSize, int integerToAdd);
int main() {

    int *myArray = new int[SIZE]; //array to test
    int x=0;
    for(int i = 0; i< SIZE; i++){
        myArray[i] = x+2;
        x+=4;
    }
    enlargeArray(myArray, SIZE,23);
    delete[] myArray;
    return 0;
}

void enlargeArray(int arr[], int size, int intAdd){
    int loc=0;
    
    int* resize = new int[size + 1];
    for(int i = 0; i < size; i++){
        resize[i] = arr[i];
    }
    size++;
    arr = resize;
    delete[] resize;
    
    for(int i=0; i< size; i++){
        if( (arr[i] <= intAdd) && (intAdd <= arr[i+1]) ){
            loc = i+1;
            break;
        }
        else if(intAdd < arr[0]){
            loc =0;
        }
        else{
            loc = size -1;
        }
    }

    int *w = arr;
    
    if ( loc != size){
        for ( int y = size; y> loc; y--){
            w[y] = w[y-1];
        }
    }
    
    w[loc] = intAdd;

    for(int i=0; i<= size -1; i++){
        cout<<arr[i]<<" "<<endl;
    }
}

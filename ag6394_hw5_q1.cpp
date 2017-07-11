#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void sameValuesIndexes(int arr[], int arrSize, int value);
const int MAX_ARRAY_SIZE = 20;

int main( ) {
    int array[MAX_ARRAY_SIZE];
    int nextInteger;
    int min;
    
    cout<<"Please enter " <<MAX_ARRAY_SIZE <<" integers separated by a space:"<<endl;
    
    for (int i=0; i<MAX_ARRAY_SIZE; i++)
    {
        cin>>nextInteger;
        array[i] = nextInteger;
    }
    
    min= minInArray(array, MAX_ARRAY_SIZE);
    cout<<"The minimum value is "<<min<<" and it is located in the following indices: ";
    sameValuesIndexes(array, MAX_ARRAY_SIZE, min);
    cout<<endl;
    return 0;
}

int minInArray(int arr[], int arrSize){
    int smallest=arr[0];
    
    for (int i = 1; i< arrSize; i++){
        
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    return smallest;
}

void sameValuesIndexes(int arr[], int arrSize, int value){
    
    for(int i=0; i<arrSize; i++){
        if (arr[i] == value)
            cout<<i<<" ";
    }
}

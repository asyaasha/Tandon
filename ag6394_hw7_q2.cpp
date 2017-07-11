
#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr[4] = {2, -1, 3, 10};
    int sum;
    sum = sumOfSquares(arr, 4);
    cout<<sum<<endl;
    
    if (isSorted(arr, 4)){
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    int sum = 0;
    if( arrSize==1){
        sum += pow(arr[0],2);
    }
    else{
        sum += sumOfSquares( arr, arrSize -1);
        sum += pow(arr[arrSize-1],2);
    }
    return sum;
}

bool isSorted(int arr[], int arrSize){ //fix
    bool sortedStatus = true;
    if (arrSize ==1){
        return sortedStatus;
    }
    while(sortedStatus && arrSize >=1){
        arrSize--;
        if(arr[arrSize-1]<arr[arrSize]){
            isSorted(arr, arrSize);
        }
        else{
            sortedStatus = false;
        }
    }
    return sortedStatus;
}

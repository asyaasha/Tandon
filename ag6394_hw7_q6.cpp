
#include <iostream>
using namespace std;

int binarySearch(int arr[], int arrSize, int val);

int main() {
    
    int arr[10] = {2,3,4,5,6,2,11,2,20,23}; //test array
    
    int pos;
    pos = binarySearch(arr, 10, 2);
    
    cout<<pos<<endl;
    return 0;
}

int binarySearch(int arr[], int arrSize, int val){
    bool found = false;
    int low =0, high = arrSize, mid = arrSize/2;
    
    while((!found) && (low <= high)){
        mid = low + (high-low)/2;
        
        if( val > arr[mid]){
            low = mid+1;
        }
        if(val< arr[mid]){
            high = mid -1;
        }
        if(val == arr[mid]){
            found = true;
            return mid;
        }
    }
    return -1;
}

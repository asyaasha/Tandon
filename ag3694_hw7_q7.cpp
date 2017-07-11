
#include <iostream>
using namespace std;

int findChange(int arr01[], int arr01Size);

int main() {
    
    int arr[8] = {0 , 0, 0, 0, 0, 0 ,1 ,1}; //test
    int firstOne;
    
    firstOne = findChange(arr, 8);
    cout<<firstOne<<endl;
    
    return 0;
}

int findChange(int arr01[], int arr01Size){
    int ind, mid, low=0, high = arr01Size-1;
    
    if (arr01[arr01Size-1] ==0){
        ind= -1;
    }
    else{
        while (arr01Size >0){
            mid = (low +high)/2;
            if (arr01Size ==1){
                ind = low;
            }
            if ( arr01[mid] == 0){
                low = mid +1;
                arr01Size = arr01Size/2;
            }
            else if (arr01[mid] == 1){
                high = mid- 1;
                arr01Size = arr01Size/2;
                findChange(arr01, arr01Size);
                }
            }
        }
    return ind;
}

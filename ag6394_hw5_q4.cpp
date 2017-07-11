
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void generateRandomArray (int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void compareToPin(string wholeSequence, int start, string saved);
int findLocation( string str, int arr[]);
bool isEqual(string str1, string str2);

const string PIN = "12345";
const int PIN_SIZE = 5;

int main() {
   
    int num[10] = {};
    string inputPin = " ";
    string pin = "0123456789";
    
    do{
    cout<<"Please enter your PIN according to the following mapping:"<<endl;
    cout<<"PIN: 0 1 2 3 4 5 6 7 8 9"<<endl;
    generateRandomArray(num, 10);
    cout<<"NUM: ";
    printArray(num, 10);
    cin>>inputPin;
    }while(inputPin.length()!=PIN_SIZE);
    
    int start = findLocation(inputPin, num);
    if (start <0){
        cout<<"Your PIN is not correct"<<endl;
    }
    else
        compareToPin(pin, start, PIN);
    return 0;
}

void generateRandomArray (int arr[], int arrSize){
    int x;
    srand(time(0));
    
    for(int i =0; i < arrSize; i ++){
        x = rand() % 10;
        arr[i] =x;
    }
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int findLocation( string str, int arr[]){
    int start =0;
    string temp=" ";
    bool finisCheck = false;
    string toCheck;
    int index;
    
    for(int i=0; i< 10; i++){
        temp += to_string(arr[i]);
    }
    while (finisCheck == false){
        index = temp.find(str[0], start);
        if (index != string::npos && index<5){
            toCheck = temp.substr(index, PIN_SIZE);
            finisCheck = isEqual(str, toCheck);
            start = index+1;
            }
        else {
            finisCheck =true;
        }
    }
    return index-1;
}
        
 void compareToPin(string wholeSequence, int start, string saved){
     string toCheck;
     toCheck = wholeSequence.substr(start, PIN_SIZE);
     
     if (isEqual(saved, toCheck)){
         cout<<"Your PIN is correct"<<endl;
     }
     else
         cout<<"Your PIN is not correct"<<endl;
}

bool isEqual(string str1, string str2){
    bool equal =false;
    for(int i = 0; i< PIN_SIZE; i++){
        if(str1[i] != str2[i]){
            equal= false;
        }
        else{
            equal= true;
        }
    }
    return equal;
}


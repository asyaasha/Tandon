#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char str[]);

int main() {
    char str[150];
    cout<<"Please enter the string"<<endl;
    cin.getline(str, 150, '\n');
   
    reverseString(str);
    
    return 0;
}

void reverseString(char str[]){
    char *front, *rear;
    char temp;
    front = str;
    rear = str +strlen(str)-1;
    
    for(int i=0; i<strlen(str)/2; i++){
        temp = *front;
        *front = *rear;
        *rear=temp;
        front++;
        rear--;
    }
    cout<<str<<endl;
}

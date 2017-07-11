#include <iostream>
#include <vector>
using namespace std;

int main() {
    int max = 0;
    int intGrade;
   
    vector<int> grades;
    
    cout<<"Please enter your grades: ";
    do{
    cin>>intGrade;
        if (intGrade >max){
            max = intGrade;
        }
    grades.push_back(intGrade);
    }while( intGrade!= -1);
    
    int *count = new int[max];
    
    for ( int i = 0; i < max; i++ )
    {
        count[i] = 0;
    }
    
    for(int i=0; i< grades.size();i++){
        count[grades[i]] +=1;
    }
    
    for(int i=0; i<=max; i++){
        if(count[i]!=0){
            cout<<"Number of "<<i<<"'s: "<<count[i]<<endl;
        }
    }
    delete[] count;
    return 0;
}

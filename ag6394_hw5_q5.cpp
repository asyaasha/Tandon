
#include <iostream>
using namespace std;

int main() {
    
    string lastName, firstName, middleInit;
    string dot =".";
    
    cout<<"Please enter first name, middle name or initial and last name: "<<endl;
    cin>>firstName;cin>>middleInit;cin>>lastName;
    middleInit = middleInit[0] + dot;
    
    cout<<lastName<<", "<<firstName<<" "<<middleInit;
    
       return 0;
    
}



#include <iostream>
using namespace std;

int main() {
    string dayOfCall;
    int timeCallStartedInteger, lengthOfCall;
    string timeCallStartedInput, timeCallStartedConverted;
    double cost=0,weekendRate =0.15, dayRate=0.40, nightRate=0.25;
    

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout<<"What is the day of the call (input format is first two chars: Mo, Tu etc) :";
    cin>>dayOfCall;
    cout<<"What time the call started? ( in 24-hour notation):";
    cin>>timeCallStartedInput;
    cout<<"Enter the length of the call in minutes:";
    cin>>lengthOfCall;
    
    for(int i = 0; i < timeCallStartedInput.size(); ++i)
        if(timeCallStartedInput[i] != ':')
            timeCallStartedConverted += timeCallStartedInput[i];
    
    timeCallStartedInteger =stoi(timeCallStartedConverted);
    
    if ((dayOfCall != "Sa")&&(dayOfCall!="Su"))
    {
        if ((timeCallStartedInteger >830)&(timeCallStartedInteger<1800))
             cost=dayRate*lengthOfCall;
        else
             cost=nightRate*lengthOfCall;
    }
    else if ((dayOfCall == "Sa")||(dayOfCall == "Su"))
    {
         cost=weekendRate*lengthOfCall;
    }
    

    cout<<"The cost of the call is : $ "<<cost<<endl;
    
    return 0;
}

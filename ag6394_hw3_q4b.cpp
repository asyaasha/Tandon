
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int lengthOfSequence=0, nextNumberInSequence, multipl = 1;
    double geometricMean;

    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typind -1:"<<endl;
    do{
        cin>>nextNumberInSequence;
        if (nextNumberInSequence > 0)
        {
            multipl = multipl * nextNumberInSequence;
            lengthOfSequence +=1;
        }
        
    }while (nextNumberInSequence != -1);
    
    geometricMean = pow(multipl, 1/(float)lengthOfSequence);
    cout<<geometricMean<<endl;
    
    return 0;
}


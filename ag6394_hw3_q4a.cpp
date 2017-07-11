
#include <iostream>
#include <cmath>
using namespace std;


int main() {

    int lengthOfSequence, nextNumberInSequence, multipl = 1;
    double geometricMean;
    cout<<"Please enter the length of the sequence: ";
    cin>>lengthOfSequence;
    cout<<"Please enter your sequence:"<<endl;
    for (int i=0; i < lengthOfSequence; ++i)
    {
        cin>>nextNumberInSequence;
        multipl = multipl * nextNumberInSequence;
    }
    geometricMean = pow(multipl, 1/(float)lengthOfSequence);
    cout<<geometricMean<<endl;
    return 0;
}

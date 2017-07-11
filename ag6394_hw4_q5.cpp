#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int outCountDivs, outSumDivs, outCountDivsTwo, outSumDivsTwo;
    int M;
    int countPer =0, countAm=0;
    do{
    cout<<"To see all perfect numbers and amicable pairs enter a positive integer >= 2 for the max range: ";cin>>M;
    }while( M < 2);
    
    for( int i = 2; i<=M; i++){
    
        if (isPerfect(i)){
            
            cout<<" Perfect number: "<<i<<endl;
            countPer ++;
        }
        analyzeDividors(i, outCountDivs,outSumDivs);
        
        int numTwo = outSumDivs;
        analyzeDividors(numTwo, outCountDivsTwo,outSumDivsTwo);
        
        if (( i < numTwo) && (numTwo <= M) && ( outSumDivsTwo == i)){
            cout<<numTwo<<" and "<<i<<" amicable pair."<<endl;
            countAm++;
        }
    }
    if (countPer == 0)
        cout<<"There are no perfect numbers in this range."<<endl;
    if (countAm == 0)
        cout<<"There are no amicable pairs in this range."<<endl;
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
        int n = num;
        outSumDivs = 1;
        outCountDivs = 1;
    
        for(int i = 2; i <= sqrt(n); ++i)
        {
            int x = 1;
            while(n % i == 0)
            {
                x = x * i + 1;
                n = n/i;
                outCountDivs+=2;
            }
            outSumDivs *= x;
        }
        if(n> 1)
        {
            outSumDivs *= 1 + n;
        }
        outSumDivs = outSumDivs - num;
    }

bool isPerfect(int num){
    int outSumDivs, counter;
    analyzeDividors(num, counter, outSumDivs);
    if (num == outSumDivs)
        return true;
    else
        return false;
}

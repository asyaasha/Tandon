
#include <iostream>
using namespace std;

double eApprox(int n);
double fact(double x);

int main() {
    
    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    
      return 0;
}

double eApprox(int n){
    double factorial = 1.0;
    double e = 1.0;
    
    for ( int i = 1; i<= (n +1); i++)
    {
        factorial *=i;
        e = e + 1/factorial;
    }
    return e;
}

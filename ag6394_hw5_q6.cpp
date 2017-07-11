
#include <iostream>
#include<string>
using namespace std;

void substituteWithSymbol( string& str, int indexStr, int indexEnd);
bool onlyNumbers(string str,int start,int lenght);

int main() {
    string textLine;
    bool endOfLine = false;
    int start = 0, end, lenght;
    int i =0;
    
    cout<<"Please enter a line o text:"<<endl;
    getline(cin, textLine);
    
    while(endOfLine==false){
        end = textLine.find(" ", start);
        lenght = end - start;
        if(end == string::npos)
        {
            end = textLine.length();
            lenght = end - start;
            if (onlyNumbers(textLine, start, lenght)){
                substituteWithSymbol( textLine, start, end);
            }
            endOfLine = true;
        }
        else if (onlyNumbers(textLine, start, lenght)){
            substituteWithSymbol(textLine, start, end);
            start = end+1;
        }
        else
            start = end+1;
    }
    cout<<textLine<<endl;
    return 0;
}

void substituteWithSymbol( string& str, int indexStr, int indexEnd){
    for(indexStr; indexStr< indexEnd; indexStr++){
        str.at(indexStr) = 'x';
    }
}

bool onlyNumbers(string str,int start,int lenght){
    bool allNumbers= false;
    allNumbers = (str.substr(start,lenght).find_first_not_of( "0123456789" ) == string::npos);
    
    return allNumbers;
}

//bool onlyNumbers(string str, int start, int lenght){  // in case we shouldn't use find_first_not_of() method
//    bool allNumbers= true;
//    string numbersSequence = "0123456789";
//    string toCheck = str.substr(start,lenght);
//    for (int i =0; i< toCheck.length(); i++){
//        int index = numbersSequence.find(toCheck[i], 0);
//        if (index == string::npos){
//            allNumbers = false;
//        }
//    }
//    return allNumbers;
//}






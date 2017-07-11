
#include <iostream>
#include <string>
using namespace std;

int countWords(string sentence);
int countLetters(string sentence);
void toLower(string& str);
void removeSpacesAndPunctuation( string& str);

int main() {
    string textLine;
    int numOfWords;
    
    
    cout<<"Please enter a line of text: "<<endl;
    getline(cin, textLine);
    
    numOfWords = countWords(textLine);
    cout<<numOfWords<<"\t words"<<endl;
    toLower( textLine);
    removeSpacesAndPunctuation(textLine);
    countLetters(textLine);
    return 0;
}

int countLetters(string sentence){
    char check ='a';
    int counter =0;
    while (check <='z'){
        counter = 0;
        for(int i=0; i< sentence.length(); i++)
            if(check == sentence[i]){
                counter += 1;
            }
        if (counter !=0){
            cout<<counter<<"\t"<<check<<endl;
        }
        check+=1;
    }
    return 0;
}


void toLower( string& str){
    for (int i=0; i<str.length(); ++i){
        if ('A'<=str[i] && str[i]<='Z'){
            str[i]=char(((int)str[i])+32);
        }
    }
}

int checkLetter (char letter, string str)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] ==  letter)
        {
            ++ count;
        }
    }
    return count;
}

int countWords(string sentence){
    int count;
    int start;
    int check;
    bool endOfLine;
    
    count = 0;
    start = 0;
    endOfLine = false;
    while (endOfLine == false) {
        check = sentence.find(" ", start);
        if(check == string::npos)
            endOfLine = true;
        else{
            count++;
            start = check + 1;
        }
    }
    return count + 1;
}

void removeSpacesAndPunctuation( string& str){
    string temp;
    for(int i=0; i< str.length(); i++){
        if (str[i] != ' '&& str[i] != '.' && str[i]!=','){
            temp += str[i];
        }
    }
    str = temp;
}


#include <iostream>
#include <string>
using namespace std;

void checkIfAnagram( string first, string second);
void toLower( string& str);
void removeSpacesAndPunctuation( string& str);

int main() {

    string str1, str2;
    
    cout<<" Enter the first string: ";getline(cin,str1);
    cout<<"Enter second string: ";getline(cin, str2);
    
    checkIfAnagram( str1, str2);
    
    return 0;
}

void checkIfAnagram( string first, string second){
    
    bool isAnagram = true;
    int count1[26] = {0};
    int count2[26] = {0};

    removeSpacesAndPunctuation(first);
    removeSpacesAndPunctuation( second);
    if (first.length() != second.length())
    {
        isAnagram = false;
    }
    else
    {
        toLower(first);
        toLower(second);
        
        for (int i = 0; i < first.length(); i++) {
          
            if ((first[i]>='a') && (first[i] <= 'z'))
             
                count1[first[i]-'a'] ++;
            
            if ((second[i]>='a') && (second[i] <= 'z'))
               
                count2[second[i]-'a'] ++;
        }

    }
    
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            isAnagram = false;
        }
    }
    
    if (isAnagram){
        cout<<"Anagram"<<endl;
    }
    else{
        cout<<"Not Anagram"<<endl;
    }
}

void toLower( string& str){
    for (int i=0; i<str.length(); ++i){
        if ('A'<=str[i] && str[i]<='Z'){
            str[i]=char(((int)str[i])+32);
        }
    }
}

void removeSpacesAndPunctuation( string& str){
    string temp = " ";
    for(int i=0; i< str.length(); i++){
        if (str[i] != ' '&& str[i] != '.' && str[i]!=','){
            temp += str[i];
        }
    }
    str = temp;
}

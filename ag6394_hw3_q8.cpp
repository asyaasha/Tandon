//
//  main.cpp
//  hw3_q8
//
//  Created by A on 6/7/17.
//  Copyright © 2017 A. All rights reserved.
//

#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    
    int maxGuesses = 5, usersGuess;
    int lowerRange=1, higherRange = 100;
    int guessesLeft = maxGuesses;
    int numberToGuess;
    srand(time(0));
    numberToGuess = (rand() % 100 )+1;
    
    cout<<"I thought of a number betwen 1and 100! Try to guess it!"<<endl;
    do
    {
        cout<<"Range: ["<<lowerRange<<","<<higherRange<<" ], Number of guesses left: "<<guessesLeft<<endl;
        cout<<"Your guess: ";
        cin>>usersGuess;
    
        if (usersGuess < numberToGuess)
        {
            cout<<"Wrong! My number is bigger."<<endl<<endl;
            lowerRange = usersGuess+1;
            guessesLeft -=1;
        }
        else if (usersGuess > numberToGuess)
        {
            cout<<"Wrong! My number is smaller."<<endl<<endl;
            higherRange = usersGuess-1;
            guessesLeft -=1;
        }
    }while (guessesLeft!=0&&usersGuess!=numberToGuess);
    
    if (guessesLeft == 0)
    {
        cout<<"Out of guesses! My number is "<<numberToGuess<<endl;
    }
    else
    {
        guessesLeft -=1;
        int numberOfGuesses = maxGuesses-guessesLeft;
        string ending = " guesses";
        if (numberOfGuesses == 1)
        {
            ending = " guess";
        }
        cout<<"Congrats! You guessed my number in "<<numberOfGuesses<<ending<<"!"<<endl;
    }
    return 0;
}

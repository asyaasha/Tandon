
#include <iostream>       
using namespace std;

int lowerCost(int board[], int ind, int size);

int main() {
  
    int board[6] = {0,3,1,6,1,10};
    int i =0;
    int cost = lowerCost(board, i, 6);

    cout<<"The lowest cost of your Jump is: "<<cost<<endl;
    
    return 0;
}


int lowerCost(int board[], int ind, int size){   // that's the best I could do( works for some cases for some missing the last number.
    
    int s=0;
    int last = size-1;

    if (ind >size){
        s += board[last]; //
    }
    else
           if ( board[ind] + lowerCost(board, ind + 1, size) <  board[ind] + lowerCost(board, ind + 2, size) && ind <= size ){
                s = board[ind] + lowerCost(board, ind + 1, size);
           }
           else if( board[ind] + lowerCost(board, ind + 1, size) >  board[ind] + lowerCost(board, ind + 2, size) && ind <= size){
                 s = board[ind] + lowerCost(board, ind + 2, size);
              
           }
    if(s <= board[last]){
        s =s +board[last]; // hardcoded
    }

    return s ;
}


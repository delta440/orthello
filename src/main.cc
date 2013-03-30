#include "Board.h"


#include <iostream>
#include <vector>
#include <utility>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(){
  Board x;
  vector<int> Moves;
  char player = 'w';
  while(1){
    player == 'w' ? player='b' : player='w';
    int mx, my;
    x.OutputBoard();  
    Moves = x.getMoves(player);
    for(vector<int>::size_type i = 0; i < Moves.size(); ++i){
      cout<<Moves[i];
      if((i+1)%2 == 0) {cout<<endl;}
    }
    cin>>mx;
    cin>>my;
    x.Move(mx, my,player);
  }
  return 0;
}

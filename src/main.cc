#include "Board.h"


#include <iostream>
using std::cin;

int main(){
  Board x;
  while(1){
    int mx, my;
    char p;
    x.OutputBoard();  
    cin>>mx;
    cin>>my;
    cin>>p;
    x.Move(mx, my, p);
  }
  return 0;
}

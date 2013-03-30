#include "Board.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
Board::Board(): board_ (8, vector<char>(8, 'e')){
  board_[3][3] = 'w';
  board_[4][3] = 'b';
  board_[3][4] = 'b';
  board_[4][4] = 'w';
}

char Board::operator()(int x, int y)const {return board_[x][y];}

vector<vector<char> > Board::getMoves(char player){



}

void Board::CheckDirection(int x, int y, int xt, int yt, char player, char nplayer, string di){
  while(board_[xt][yt] == nplayer && xt < 8 && xt >= 0 && yt < 8 && yt >= 0){
    if(board_[xt][yt] == player){
      flip(x, y, xt, yt);
      break;
    }
    if(di=="r"||di=="ur"||di=="dr"){++xt;}
    if(di=="l"||di=="ul"||di=="dl"){--xt;}
    if(di=="u"||di=="ur"||di=="ul"){++yt;}
    if(di=="d"||di=="ud"||di=="ud"){++yt;}
  }
}
    
    
void Board::Move(int x, int y, char player){
  int xt = x + 1;
  int yt = y;
  char nplayer;
  (player == 'w') ? (nplayer = 'b') : (nplayer = 'w');
  CheckDirection(x, y, xt, yt, player, nplayer, "r");
  ++yt;
  CheckDirection(x, y, xt, yt, player, nplayer, "ur");
  xt = x;
  CheckDirection(x, y, xt, yt, player, nplayer, "u");
  --xt;
  CheckDirection(x, y, xt, yt, player, nplayer, "ul");
  yt = y;
  CheckDirection(x, y, xt, yt, player, nplayer, "l");
  --yt;
  CheckDirection(x, y, xt, yt, player, nplayer, "dl");
  xt = x;
  CheckDirection(x, y, xt, yt, player, nplayer, "d");
  ++xt;
  CheckDirection(x, y, xt, yt, player, nplayer, "dr");
}
    
void Board::flip(int x1, int y1, int x2, int y2){
  int xlow, xhigh, ylow, yhigh;
  if(x1 <= x2){
    xlow = x1;
    xhigh = x2;
  }
  else{
    xhigh = x1;
    xlow = x2;
  }
  if(y1 <= y2){
    ylow = y1;
    yhigh = y2;
  }
  else{
    yhigh = y1;
    ylow = y2;
  }
  //if horisontal 
  if(y1 == y2){
    for(;xlow <= xhigh; ++xlow){
      flip(xlow, ylow);
    }
  }
  //if vertical
  else if(x1 == x2){
    for(;ylow <= yhigh; ++ylow){
      flip(xlow, ylow);
    }
  }
  //if up and right diagonal
  else if(x1 < x2 && y1 < y2){
    while(xlow <= xhigh){
      flip(xlow, ylow);
      ++xlow; ++ylow;
    }
  }
  //if down and right diagonal
  else if(x1 < x2 && y1 > y2){
    while(xlow < xhigh){
      flip(xlow, yhigh);
      ++xlow; --ylow;
    }
  }
  //if up and left diagonal
  else if(x1 > x2 && y1 < y2){
    while(xhigh > xlow){
      flip(xhigh, ylow);
      --xhigh; ++ylow;
    }
  }
  //if down and left diagonal
  else if(x1 > x2 && y1 > y2){
    while(xhigh > xlow){
      flip(xhigh, yhigh);
      --xhigh; --yhigh;
    }
  }
  flip(x2, y2);
  flip(x1, y1);
}

void Board::flip(int x, int y){
  if(board_[x][y] == 'w')
    board_[x][y] = 'b';
  else if(board_[x][y] == 'b')
    board_[x][y] = 'w';
}

void Board::OutputBoard(){
  for(int y = 0; y < 8; ++y){
    for(int x = 0; x < 8; ++x){
      cout<<board_[x][y]<<' ';
    }
    cout<<endl;
  }
}

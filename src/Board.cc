#include "Board.h"
#include <string>
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::copy;
using std::cerr;
Board::Board(): board_ (8, vector<char>(8, 'e')){
   board_[3][3] = 'w';
   board_[4][3] = 'b';
   board_[3][4] = 'b';
   board_[4][4] = 'w';
}

char Board::operator()(int x, int y)const {return board_[x][y];}

vector<int> Board::getMoves(char player) const{
   char nplayer;
   vector<int> Moves;
   (player == 'w') ? (nplayer = 'b') : (nplayer = 'w');
   for(int y = 0; y < 8; ++y){
      for(int x = 0; x < 8; ++x){
	 if(board_[x][y] == 'e'){
	    if(CheckDirectionb(x, y, x + 1, y, player, nplayer, "r")
	       || CheckDirectionb(x, y, x + 1, y - 1, player, nplayer, "ur")
	       || CheckDirectionb(x, y, x, y - 1, player, nplayer, "u")
	       || CheckDirectionb(x, y, x - 1, y - 1, player, nplayer, "ul")
	       || CheckDirectionb(x, y, x - 1, y, player, nplayer, "l")
	       || CheckDirectionb(x, y, x - 1, y + 1, player, nplayer, "dl")
	       || CheckDirectionb(x, y, x, y + 1, player, nplayer, "d")
	       || CheckDirectionb(x, y, x + 1, y + 1, player, nplayer, "dr")){
	       Moves.push_back(x);
	       Moves.push_back(y);
	    }
	 }
      }
   }
   return Moves;
}

void Board::CheckDirection(int x, int y, int xt, int yt, char player, char nplayer, string di){
   while(xt < 8 && xt >= 0 && yt < 8 && yt >= 0 && board_[xt][yt] == nplayer){
      if(di=="r"||di=="ur"||di=="dr"){++xt;}
      if(di=="l"||di=="ul"||di=="dl"){--xt;}
      if(di=="u"||di=="ur"||di=="ul"){--yt;}
      if(di=="d"||di=="dr"||di=="dl"){++yt;}
      if(xt < 8 && xt >= 0 && yt < 8 && yt >= 0 && board_[xt][yt] == player){
	 flip(x, y, xt, yt, player);
	 break;
      } 
   }
}

bool Board::CheckDirectionb(int x, int y, int xt, int yt, char player, char nplayer, string di)
   const{
   while(xt < 8 && xt >= 0 && yt < 8 && yt >= 0 && board_[xt][yt] == nplayer){
      if(di=="r"||di=="ur"||di=="dr"){++xt;}
      if(di=="l"||di=="ul"||di=="dl"){--xt;}
      if(di=="u"||di=="ur"||di=="ul"){--yt;}
      if(di=="d"||di=="dr"||di=="dl"){++yt;}
      if(xt < 8 && xt >= 0 && yt < 8 && yt >= 0
	 && board_[xt][yt] == player){
	 return 1;
      } 
   }
   return 0;
}
    
void Board::Move(int x, int y, char player){
   char nplayer;
   board_[x][y] = player;
   (player == 'w') ? (nplayer = 'b') : (nplayer = 'w');
   CheckDirection(x, y, x + 1, y, player, nplayer, "r");
   CheckDirection(x, y, x + 1, y - 1, player, nplayer, "ur");
   CheckDirection(x, y, x, y - 1, player, nplayer, "u");
   CheckDirection(x, y, x - 1, y - 1, player, nplayer, "ul");
   CheckDirection(x, y, x - 1, y, player, nplayer, "l");
   CheckDirection(x, y, x - 1, y + 1, player, nplayer, "dl");
   CheckDirection(x, y, x, y + 1, player, nplayer, "d");
   CheckDirection(x, y, x + 1, y + 1, player, nplayer, "dr");
}
    
void Board::flip(int x1, int y1, int x2, int y2, char player){
   int xlow, xhigh, ylow, yhigh;
   if(x1 <= x2){
      xlow = x1;
      xhigh = x2;
   }
   else{
      xhigh = x1;
      xlow = x2;
   }
   if(y1 >= y2){
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
	 board_[xlow][ylow] = player;
      }
   }
   //if vertical
   else if(x1 == x2){
      for(;ylow >= yhigh; --ylow){
	 board_[xlow][ylow] = player;
      }
   }
   //if up and right diagonal
   else if(x1 < x2 && y1 > y2){
      while(xlow <= xhigh){
	 board_[xlow][ylow] = player;
	 ++xlow; --ylow;
      }
   }
   //if down and right diagonal
   else if(x1 < x2 && y1 < y2){
      while(xlow < xhigh){
	 board_[xlow][yhigh] = player;
	 ++xlow; ++yhigh;
      }
   }
   //if up and left diagonal
   else if(x1 > x2 && y1 > y2){
      while(xhigh > xlow){
	 board_[xhigh][ylow] = player;
	 --xhigh; --ylow;
      }
   }
   //if down and left diagonal
   else if(x1 > x2 && y1 < y2){
      while(xhigh > xlow){
	 board_[xhigh][y1] = player;
	 --xhigh; ++y1;
      }
   }
}

void Board::flip(int x, int y){
   if(board_[x][y] == 'w')
      board_[x][y] = 'b';
   else if(board_[x][y] == 'b')
      board_[x][y] = 'w';
}

void Board::OutputBoard() const{
   for(int y = 0; y < 8; ++y){
      cout<<y<<' ';
      for(int x = 0; x < 8; ++x){
	 cout<<board_[x][y]<<' ';
      }
      cout<<endl;
   }
   cout<<"  ";
   for(int x = 0; x < 8; ++x){
      cout<<x<<' ';
   }
   cout<<endl;
}

char& Board::GetPos(int x, int y){
   return board_[x][y];
}

void Board::OutputBoard(){
   for(int y = 0; y < 8; ++y){
      cout<<y<<' ';
      for(int x = 0; x < 8; ++x){
	 board_[x][y] == 'e' ? cout<<"_ " : cout<<board_[x][y]<<' ';
      }
      cout<<endl;
   }
   cout<<"  ";
   for(int x = 0; x < 8; ++x){
      cout<<x<<' ';
   }
   cout<<endl;
}

bool Board::EndGame(){
   if(getMoves('w').size() == 0 && getMoves('b').size() == 0){
      return true;
   }
   return false;
}

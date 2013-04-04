#include "Board.h"
#include "MinMaxSearch.h"

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void oppmove(Board &B, char opp){
  int x, y;
  cout<<"Please enter opponent's move (x y): ";
  cin>>x>>y;
  B.Move(x, y, opp);
}
int main(){
  const int MAXDEPTH = 11;
  Board x;
  vector<int> Moves;
  char ai, first_player, opponent;
  pair<int, int> xy;
  cout<<"Please enter local AI color(w or b): ";
  cin>>ai;
  cout<<"Please enter which player goes first (w or b): ";
  cin>>first_player;
  ai == 'w' ? opponent = 'b' : opponent = 'w';
  MinMaxSearch Searcher(ai, opponent);
  x.OutputBoard();
  vector<int> pmoves;
  while(!x.EndGame()){
    if(ai == first_player){
      xy = Searcher.AlphaBetaSearch(x, MAXDEPTH);
      cout<<xy.first<<xy.second<<endl;
      if(xy.first != -1 && xy.second !=-1)
	x.Move(xy.first, xy.second, ai);
      x.OutputBoard();
      pmoves = x.getMoves(opponent);
      if(pmoves.size() !=0)
	oppmove(x, opponent);
    }
    else{
      pmoves = x.getMoves(opponent);
      if(pmoves.size() != 0)
	oppmove(x, opponent);
      x.OutputBoard();
      xy = Searcher.AlphaBetaSearch(x, MAXDEPTH);
      cout<<xy.first<<xy.second<<endl;
      if(xy.first != -1 && xy.second !=-1)
	x.Move(xy.first, xy.second, ai);
    }
    x.OutputBoard();	
  }
  int nb = 0, nw = 0;
  for(int i = 0; i < 8; i++)
    {
      for(int j = 0; j < 8; j++)
	{
	  char cur = x(i, j);
	  if(cur == 'b')
	    nb++;
	  else if(cur == 'w')
	    nw++;
	}
    }
  nb > nw ? cout<<"black wins"<<endl :
    (nb < nw ? cout<<"white wins"<<endl  : cout<<"Tie"<<endl);
   
  return 0;
}

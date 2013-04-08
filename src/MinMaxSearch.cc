#include "MinMaxSearch.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



pair<int, int> MinMaxSearch::MinMaxRunSearch(const Board &B, const int &depth){
  pair<int, int> xy;
  xy.first = -1; xy.second = -1;
  MaxValue(B, 0, depth, xy);
  return xy;
}

pair<int, int> MinMaxSearch::AlphaBetaSearch(const Board &B, const int &depth){
  pair<int, int> xy;
  xy.first = -1; xy.second = -1;
  int a = -1000000;
  int b = 1000000;
  ABMaxValue(B, a, b, 0, depth, xy);
  return xy;
}

int MinMaxSearch::GetVal(const Board &B, const int &M, const char&p)
{
  //weights for each feature
  const int w1 = 5, w2 = 7, w3 = 15;
  int D = 0, W = 0;
  for(int i = 0; i < 8; i++)
    {
      for(int j = 0; j < 8; j++)
	{
	  char cur = B(i, j);
	  if(cur == p){
	    D++;
	    W += NodeVal_[i][j];
	  }
	  else if(cur != p){
	    D--;
	    W -= NodeVal_[i][j];
	  }
	}
    }
  if(D < 0 && B.EndGame()){
    D *= 5;
    if(B.EndGame())
      D = -1000000;
  }
  return w1*D + w2*M + w3*W;
}

int MinMaxSearch::MaxValue(const Board &B, const int &d, const int &ter,
			   pair<int, int> &xy)
{
  vector<int> moves = B.getMoves(AiColor_);  //p is either 'b' or 'w'
  if(d == ter || moves.size() == 0)
    return GetVal(B, (moves.size()/2), AiColor_);
  int v = -1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i += 2)
    {
      if(i >= moves.size())
	cerr << "Error in MinMaxSearch.h function Maxvalue" << endl;
      int x = moves[i], y = moves[i+1];
      Board temp(B);
      temp.Move(x, y, AiColor_);
      states.push_back(temp);
    }
  char np;
  unsigned int k = 0;
  for(unsigned int i = 0; i < states.size(); i++){
    int tempv;
    tempv = max(v, MinValue(states[i], d + 1, ter, xy));
    if(tempv > v){
      v = tempv;
      k = i;
    }
  }
  if(d == 0){
    xy.first = moves[k*2];
    xy.second = moves[k*2+1];
  }
  return v;
}


int MinMaxSearch::MinValue(const Board &B, const int &d, const int &ter,
			   pair<int, int> &xy)
{
  vector<int> moves = B.getMoves(AiColor_);
  if(d >= ter || moves.size() == 0)
    return GetVal(B, (moves.size()/2), NAiColor_);
  int v = 1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i += 2)
    {
      if(i >= moves.size())
	cerr << "Error in MinMaxSearch.h function Minvalue" << endl;
      int x = moves[i], y = moves[i+1];
      Board temp(B);
      temp.Move(x, y, NAiColor_);
      states.push_back(temp);
    }
  char np;
  unsigned int k = 0;
  for(unsigned int i = 0; i < states.size(); i++){
    int tempv;
    tempv = min(v, MaxValue(states[i], d + 1, ter, xy));
    if(tempv < v){
      v = tempv;
      k = i;
    }
  }
  if(d == 0){
    xy.first = moves[k*2];
    xy.second = moves[k*2+1];
  } 
    
  return v;
}

int MinMaxSearch::ABMaxValue(const Board &B, int &a, int &b, 
			     const int &d, const int &ter, pair<int, int> &xy)
{
  vector<int> moves = B.getMoves(AiColor_);
  if(d == ter || moves.size() == 0)
    return GetVal(B, (moves.size()/2), AiColor_);
  int v = -1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i += 2)
    {
      if(i >= moves.size())
	cerr << "Error in MinMaxSearch.h function ABMaxvalue" << endl;
      int x = moves[i], y = moves[i+1];
      Board temp = B;
      temp.Move(x, y, AiColor_);      
      states.push_back(temp);
    }
  unsigned int k;
  for(unsigned int i = 0; i < states.size(); i++)
    {
      int tempv;
      tempv = max(v, ABMinValue(states[i], a, b, d + 1, ter, xy));
      if(tempv > v){
	v = tempv;
	k = i;
      }
      if(v >= b)
	return v;
      a = max(a, v);
    }
  if(d == 0){
    xy.first = moves[k*2];
    xy.second = moves[k*2+1];
  }
  return v;
}

int MinMaxSearch::ABMinValue(const Board &B, int &a, int &b, 
			     const int &d, const int &ter, pair<int, int> &xy)
{
  vector<int> moves = B.getMoves(NAiColor_);  //p is either 'b' or 'w'
  if(d == ter || moves.size() == 0)
    return GetVal(B, (moves.size()/2), NAiColor_);
  int v = 1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i += 2)
    {
      if(i >= moves.size())
	cerr << "Error in MinMaxSearch.h function ABMinvalue" << endl;
      int x = moves[i], y = moves[i+1];
      Board temp = B;
      temp.Move(x, y, NAiColor_);      
      states.push_back(temp);
    }
  unsigned k;
  for(unsigned int i = 0; i < states.size(); i++)
    {
      int tempv;
      tempv = min(v, ABMaxValue(states[i], a, b, d + 1, ter, xy));
      if(tempv < v){
	v = tempv;
	k = i;
      }
      if(v <= a)
	return v;
      b = min(b, v);
    }
  if(d == 0){
    xy.first = moves[k*2];
    xy.second = moves[k*2+1];
  }
  return v;
}


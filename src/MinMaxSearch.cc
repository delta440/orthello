#include "MinMaxSearch.h"
#include "Board.h"
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int MinMaxSearch::GetVal(const Board &B, const int &M, const char &p)
{
  //weights for each feature
  const int w1 = 1, w2 = 1, w3 = 1;
  int D = 0, W = 0, nb = 0, nw = 0;
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      char cur = B(i, j);
      if(cur == 'b')
        nb++;
      else if(cur == 'w')
        nw++;
      if(cur == p)
        W += NodeVal_[i][j];
    }
  }
  //Assumes white is max player
  D = nw - nb;
  return w1*D + w2*M + w3*W;
}

int MinMaxSearch::MaxValue(const Board &B, const char &p, const int &d, const int &ter)
{
  vector<int> moves = B.getMoves(char p);  //p is either 'b' or 'w'
  if(d == ter)
    return GetVal(B, (moves.size()/2), p);
  int v = -1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i+2)
  {
    if(i >= moves.size())
      cerr << "Error in MinMaxSearch.h function Maxvalue" << endl;
    int x = moves[i], y = moves[i+1];
    Board temp = B.move(x, y, p);
    states.push_back(temp);
  }
  char np;
  if(p == 'w')
    np = 'b';
  else if(p == 'b')
    np = 'w';
  for(unsigned int i = 0; i < states.size(); i++)
  {
    v = max(v, MinValue(states[i], np, d, ter);
  }
  return v;
}


int MinMaxSearch::MinValue(const Board &B, const char &p, const int &d, const int &ter)
{
  vector<int> moves = B.getMoves(char p);  //p is either 'b' or 'w'
  if(d == ter)
    return GetVal(B, (moves.size()/2), p);
  int v = 1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i+2)
  {
    if(i >= moves.size())
      cerr << "Error in MinMaxSearch.h function Minvalue" << endl;
    int x = moves[i], y = moves[i+1];
    Board temp = B.move(x, y, p);
    states.push_back(temp);
  }
  char np;
  if(p == 'w')
    np = 'b';
  else if(p == 'b')
    np = 'w';
  for(unsigned int i = 0; i < states.size(); i++)
  {
    v = min(v, MinValue(states[i], np, d, ter);
  }
  return v;
}

int MinMaxSearch::ABMaxValue(const Board &B, const char &p, int &a, int &b, 
                              const int &d, const int &ter)
{
  vector<int> moves = B.getMoves(char p);  //p is either 'b' or 'w'
  if(d == ter)
    return GetVal(B, (moves.size()/2), p);
  int v = -1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i+2)
  {
    if(i >= moves.size())
      cerr << "Error in MinMaxSearch.h function ABMaxvalue" << endl;
    int x = moves[i], y = moves[i+1];
    Board temp = B.move(x, y, p);
    states.push_back(temp);
  }
  char np;
  if(p == 'w')
    np = 'b';
  else if(p == 'b')
    np = 'w';
  for(unsigned int i = 0; i < states.size(); i++)
  {
    v = max(v, ABMinValue(states[i], np, a, b, d, ter);
    if(v >= b)
      return v;
    a = max(a, v);
  }
  return v;
}
  
int MinMaxSearch::ABMinValue(const Board &B, const char &p, int &a, int &b, 
                              const int &d, const int &ter)
{
  vector<int> moves = B.getMoves(char p);  //p is either 'b' or 'w'
  if(d == ter)
    return GetVal(B, (moves.size()/2), p);
  int v = 1000000;
  vector<Board> states;
  for(unsigned int i = 0; i < moves.size(); i+2)
  {
    if(i >= moves.size())
      cerr << "Error in MinMaxSearch.h function ABMinvalue" << endl;
    int x = moves[i], y = moves[i+1];
    Board temp = B.move(x, y, p);
    states.push_back(temp);
  }
  char np;
  if(p == 'w')
    np = 'b';
  else if(p == 'b')
    np = 'w';
  for(unsigned int i = 0; i < states.size(); i++)
  {
    v = min(v, ABMaxValue(states[i], np, a, b, d, ter);
    if(v <= a)
      return v;
    a = min(b, v);
  }
  return v;
}

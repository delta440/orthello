#ifndef MINMAXSEARCH_H
#define MINMAXSEARCH_H

#include <utility>
#include "Board.h"

using namespace std;

const int NodeVal_ [8][8] = {{9,5,5,5,5,5,5,9},
			     {5,1,1,1,1,1,1,5},
			     {5,1,1,1,1,1,1,5},
			     {5,1,1,2,2,1,1,5},
			     {5,1,1,2,2,1,1,5},
			     {5,1,1,1,1,1,1,5},
			     {5,1,1,1,1,1,1,5},
			     {9,5,5,5,5,5,5,9}};

class MinMaxSearch{
 public:
   
 MinMaxSearch(char AiColor, char NAiColor):AiColor_(AiColor), NAiColor_(NAiColor){}

  /*Performs Minimax search and returns the x, y coordinates for the move
    stored in a pair of ints*/
  pair<int, int> MinMaxRunSearch(const Board &B, const int &depth);
   
  //Performs AlphaBeta search
  pair<int, int> AlphaBetaSearch(const Board &B, const int &depth);

 private:
   
  //Returns the utility value of the current state
  int GetVal(const Board &B, const int &M, const char &p);
  
  //Helper function for MinMaxSearch for the max player
  int MaxValue(const Board &B, const int &d, const int &ter,
	       pair<int, int> &xy);
  
  //Helper function for MinMaxSearch for the min player
  int MinValue(const Board &B, const int &d, const int &ter,
	       pair<int, int> &xy);
  
  //Helper function for AlphaBetaSearch for the max player
  int ABMaxValue(const Board &B, int &a, int &b, const int &d, 
		 const int &ter, pair<int, int> &xy);
  
  //Helper function for AlphaBetaSearch for the min player
  int ABMinValue(const Board &B, int &a, int &b, const int &d, 
		 const int &ter, pair<int, int> &xy);
  
  const char AiColor_;
  const char NAiColor_;
};



#endif //MINMAXSEARCH_H

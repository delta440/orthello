#ifndef MINMAXSEARCH_H
#define MINMAXSEARCH_H

class MinMaxSearch{
public:	
  /*Performs Minimax search and returns the x, y coordinates for the move
    stored in a pair of ints*/
  pair<int, int> MinMaxSearch(const Board &B, const char &p, const int &depth);

  //Performs AlphaBeta search
  void AlphaBetaSearch(const Board &B, const int &depth);

private:
  int NodeVal_[8][8] = {{1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1}};

  //Returns the utility value of the current state
  int GetVal(const Board &B, const int &M, const char &p);
  
  //Helper function for MinMaxSearch for the max player
  int MaxValue(const Board &B, const char &p, const int &d, const int &ter);
  
  //Helper function for MinMaxSearch for the min player
  int MinValue(const Board &B, const char &p, const int &d, const int &ter);
  
  //Helper function for AlphaBetaSearch for the max player
  int ABMaxValue(const Board &B, const char &p, int &a, int &b, const int &d, 
                  const int &ter);
  
  //Helper function for AlphaBetaSearch for the min player
  int ABMinValue(const Board &B, const char &p, int &a, int &b, const int &d, 
                  const int &ter);
  
  
};



#endif //MINMAXSEARCH_H

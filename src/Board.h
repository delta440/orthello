#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
using std::string;
using std::vector;

//class used to store and modify what is currently on the board, note: I used char's to
//represent what is on a square to save space
class Board{
 public:
  //constructs a board with the default orthello starting position
  Board();

  //returns the contents of a square on the board e is empty 
  //w is white b is black
  char operator() (int x, int y) const;

  //returns a list of valid move coordinates for either the first or second player
  vector<int> getMoves(char player);

  //executes a move on a given xy coordinate by a given player
  void Move(int x, int y, char player);

  //for testing only
  void OutputBoard();
 private:
  vector<vector<char> > board_;

  //helper function for move to check for pieces which need to be flipped
  void CheckDirection(int x, int y, int xt, int yt, char player, char nplayer, string di);

  //helper function for getMoves to check for valid moves
  bool CheckDirectionb(int x, int y, int xt, int yt, char player, char nplayer, string di);

  //flips (exclusivly) all of the pieces between the two coordinates
  void flip(int x1, int y1, int x2, int y2, char player);

  //flips a single piece
  void flip(int x, int y);
};

#endif //BOARD_H

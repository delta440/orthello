#ifndef BOARD_H
#define BOARD_H

#include <vector>
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
	vector<vector<char> > getMoves(char player);

	//executes a move on a given xy coordinate by a given player
	void Move(int x, int y, char player);
private:
vector<vector<char> > board_;

//flips (inclusivly) all of the pieces between the two coordinates
void flip(int x1, int y1, int x2, int y2);

//flips a single piece
void flip(int x, int y);
};

#endif //BOARD_H
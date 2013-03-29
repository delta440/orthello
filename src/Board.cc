#include "Board.h"

Board::Board(){
	board_= new vector<vector<char> >(8, vector<char>(8, 'e'));
	board_[3][3] = 'w';
	board_[4][3] = 'b';
	board_[3][4] = 'b';
	board_[4][4] = 'w';
}

char Board::operator()(int x, int y){return board_[x][y];}

vector<vector<char> > Board_::getMoves(char player){



}

void Board::Move(int x, int y, char player){








}

void Board::flip(int x1, int y1, int x2, int y2){
	int xlow, xhigh, ylow, yhigh;
	if(x1 <= x2){
		xlow = x1;
		xhigh = x2;
	}
	else{
		xhigh = x1
		xlow = x2;
	}
	if(y1 <= y2){
		ylow = y1;
		yigh = y2;
	}
	else{
		yhigh = y1
		ylow = y2;
	}
	//if horisontal 
	if(yhigh == ylow){
		for(;xlow <= xhigh; ++xlow){
			flip(xlow, ylow);
		}
	}
	//if vertical
	else if(xlow == xhigh){
		for(;ylow <= yhigh; ++ylow){
			flip(xlow, ylow);
		}
	}
	//if up and right diagnal
	else if()


}

void Board::flip(int x, int y){
	if(board_[x][y] == 'w')
		board_[x][y] = 'b';
	else if(board[x][y] == 'b')
		board_[x][y] = 'w';
}
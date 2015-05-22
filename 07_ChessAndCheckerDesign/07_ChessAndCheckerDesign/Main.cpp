/*
Design a class to implement chess and checkers game individually.
*/
#include<iostream>

using namespace std;

class Pieces
{
	int x;
	int y;
	virtual void Move(int newX, int newY) = 0;
};

class King : Pieces
{
	void Move(int newX, int newY) override
	{
		//Implement King's move here
	};
};

class Queen : Pieces
{
	void Move(int newX, int newY) override
	{
		//Implement Queens's move here
	};
};

class Rook : Pieces
{
	void Move(int newX, int newY) override
	{
		//Implement Rook's move here
	};
};

class Bishop : Pieces
{
	void Move(int newX, int newY) override
	{
		//Implement Bishop's move here
	};
};

class Knight : Pieces
{
	void Move(int newX, int newY) override
	{
		//Implement Knight's move here
	};
};

class Pawn : Pieces
{
	void Move(int newX, int newY) override
	{
		//Implement Pawn's move here
	};
};

class Team
{
public:
	King king;
	Queen queen;
	Rook rook[2];
	Bishop bishop[2];
	Knight knight[2];
	Pawn pawn[8];
};

class Board
{
public:
	void UpdateDisplay(Team a, Team b)
	{
		// access each team's pieces and its location to update display after each move.
	};
};

class Chess
{
public:
	Team A;
	Team B;
	Board board;
};


class CheckerPieces
{
	int x;
	int y;
	void Move(int newX, int newY)
	{
		//Implement checker pieces move here
	}
};

class CheckerTeam
{
	CheckerPieces checkerPieces[12];
};

class CheckerBoard
{
public:
	void UpdateDisplay(CheckerTeam a, CheckerTeam b)
	{
		// access each checker team's pieces and its location to update display after each move.
	};
};

class Checker
{
public:
	CheckerTeam A;
	CheckerTeam B;
	CheckerBoard board;
};

int main()
{

}
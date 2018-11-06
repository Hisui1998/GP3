#pragma once
class VECTOR2;

enum PIECE_ST {
	ONE,
	TWO,
	MAX
};

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	bool CheckSet(PIECE_ST state);
	bool SelectPiece(VECTOR2 m_pos);
private:
};


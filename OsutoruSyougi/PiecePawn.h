#pragma once
#include "GamePiece.h"

// •à•º
class PiecePawn :
	public GamePiece
{
public:
	PiecePawn();
	~PiecePawn();
	
	bool SetPos(VECTOR2 pos);
	VECTOR2 GetPos();
	std::vector<VECTOR2> isMove();
	void Draw();
private:
	VECTOR2 pos;
	VECTOR2 offset;
	VECTOR2 DrawPos;
};


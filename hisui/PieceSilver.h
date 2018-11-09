#pragma once
#include "GamePiece.h"
class PieceSilver :
	public GamePiece
{
public:
	PieceSilver();
	~PieceSilver();
	bool SetPos(VECTOR2 pos, VECTOR2 Offset = -1);
	VECTOR2 GetPos();
	std::vector<VECTOR2> isMove();
	void Draw();
private:
	VECTOR2 pos;
	VECTOR2 offset;
	VECTOR2 DrawPos;
};


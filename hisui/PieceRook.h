#pragma once
#include "GamePiece.h"
// ”òŽÔ
class PieceRook :
	public GamePiece
{
public:
	PieceRook();
	~PieceRook();
	bool SetPos(VECTOR2 pos,VECTOR2 Offset = -1);
	VECTOR2 GetPos();
	std::vector<VECTOR2> isMove();
	void Draw();
	bool Endless();
private:
	VECTOR2 pos;
	VECTOR2 offset;
	VECTOR2 DrawPos;
};


#pragma once
#include "GamePiece.h"

// ����
class PiecePawn :
	public GamePiece
{
public:
	PiecePawn();
	~PiecePawn();
	
	bool SetPos(VECTOR2 pos);
	VECTOR2 GetPos();

	void Draw();
private:
	VECTOR2 pos;
	VECTOR2 offset;
};


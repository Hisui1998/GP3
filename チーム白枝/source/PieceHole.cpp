#include "PieceHole.h"
#include "GameBoard.h"

PieceHole::PieceHole()
{
	pos = VECTOR2(4,4);
	offset = VECTOR2((SCR_SIZR_X / 2) - (PIECE_SIZE / 2) * 8, (SCR_SIZR_Y / 2) - (PIECE_SIZE / 2) * 8);
}


PieceHole::~PieceHole()
{
}


bool PieceHole::SetPos(VECTOR2 pos, VECTOR2 Offset)
{
	if (Offset != -1)
	{
		offset = Offset;
	}
	this->pos = pos;
	return true;
}

VECTOR2 PieceHole::GetPos()
{
	return pos;
}

std::vector<VECTOR2> PieceHole::isMove()
{
	std::vector<VECTOR2> Data;
	Data.push_back(VECTOR2(-1, -1));
	Data.push_back(VECTOR2(0, -1));
	Data.push_back(VECTOR2(1, -1));
	Data.push_back(VECTOR2(-1, 0));
	Data.push_back(VECTOR2(1, 0));
	Data.push_back(VECTOR2(-1, 1));
	Data.push_back(VECTOR2(0, 1));
	Data.push_back(VECTOR2(1, 1));
	return  Data;
}

void PieceHole::Draw()
{
	DrawPos = (pos * PIECE_SIZE) + offset;
	DrawCircle(DrawPos.x, DrawPos.y,30,0,true);
}

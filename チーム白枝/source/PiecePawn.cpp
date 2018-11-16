#include "PiecePawn.h"


PiecePawn::PiecePawn()
{
	offset = VECTOR2(SCR_SIZR_X - (PIECE_SIZE / 2)-192, SCR_SIZR_Y - (PIECE_SIZE / 2)-192);
}


PiecePawn::~PiecePawn()
{
}

bool PiecePawn::SetPos(VECTOR2 pos, VECTOR2 Offset)
{
	if (Offset != -1)
	{
		offset = Offset;
	}
	this->pos = pos;
	return true;
}

VECTOR2 PiecePawn::GetPos()
{
	return pos;
}

std::vector<VECTOR2> PiecePawn::isMove()
{
	std::vector<VECTOR2> Data;
	Data.push_back(VECTOR2(0, -1));
	return  Data;
}

void PiecePawn::Draw()
{
	DrawPos = (pos * PIECE_SIZE) + offset;
	DrawBox(DrawPos.x + 7, DrawPos.y + 23, DrawPos.x + 57, DrawPos.y + 57, 0, true);
	DrawTriangle(DrawPos.x + 7, DrawPos.y + 23, DrawPos.x +57 , DrawPos.y + 23, DrawPos.x + 33, DrawPos.y + 7, 0, true);
	
	DrawBox(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 56, 0xcd853f, true);
	DrawTriangle(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 24, DrawPos.x + 32, DrawPos.y + 8, 0xcd853f, true);
	DrawString(DrawPos.x + 25, DrawPos.y + 28, "•à", 0, true);
}

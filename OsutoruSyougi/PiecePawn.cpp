#include "PiecePawn.h"


PiecePawn::PiecePawn()
{
	pos =VECTOR2 { 0, 1 };
	offset = { (SCR_SIZR_X / 2) - (PIECE_SIZE / 2) * 9, (SCR_SIZR_Y / 2) - (PIECE_SIZE / 2) * 9 };
}


PiecePawn::~PiecePawn()
{
}

bool PiecePawn::SetPos(VECTOR2 pos)
{
	this->pos = pos;
	return true;
}

VECTOR2 PiecePawn::GetPos()
{
	return pos;
}

std::vector<VECTOR2> PiecePawn::isMove()
{
	std::vector<VECTOR2> Date;
	Date.push_back(VECTOR2(0, -1));
	return  Date;
}

void PiecePawn::Draw()
{
	DrawPos = (pos * PIECE_SIZE) + offset;
	DrawBox(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 56, 0xcd853f, true);
	DrawTriangle(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 24, DrawPos.x + 32, DrawPos.y + 8, 0xcd853f, true);
	DrawString(DrawPos.x + 25, DrawPos.y + 28, "•à", 0, true);
}

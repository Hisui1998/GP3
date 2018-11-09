#include "PieceRook.h"



PieceRook::PieceRook()
{
	pos = VECTOR2{ 1, 1 };
	offset = { (SCR_SIZR_X / 2) - (PIECE_SIZE / 2) * 9, (SCR_SIZR_Y / 2) - (PIECE_SIZE / 2) * 9 };
}


PieceRook::~PieceRook()
{
}

bool PieceRook::SetPos(VECTOR2 pos)
{
	this->pos = pos;
	return true;
}

VECTOR2 PieceRook::GetPos()
{
	return pos;
}

std::vector<VECTOR2> PieceRook::isMove()
{
	std::vector<VECTOR2> Data;
	return  Data;
}

void PieceRook::Draw()
{
	DrawPos = (pos * PIECE_SIZE) + offset;
	DrawBox(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 56, 0xcd853f, true);
	DrawTriangle(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 24, DrawPos.x + 32, DrawPos.y + 8, 0xcd853f, true);
	DrawString(DrawPos.x + 25, DrawPos.y + 20, "”ò\nŽÔ", 0, true);
}

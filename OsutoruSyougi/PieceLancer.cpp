#include "PieceLancer.h"



PieceLancer::PieceLancer()
{
	pos = VECTOR2{ 0, 1 };
	offset = { (SCR_SIZR_X / 2) - (PIECE_SIZE / 2) * 9, (SCR_SIZR_Y / 2) - (PIECE_SIZE / 2) * 9 };
}


PieceLancer::~PieceLancer()
{
}

bool PieceLancer::SetPos(VECTOR2 pos)
{
	this->pos = pos;
	return true;
}

VECTOR2 PieceLancer::GetPos()
{
	return pos;
}

std::vector<VECTOR2> PieceLancer::isMove()
{
	std::vector<VECTOR2> Data;
	Data.push_back(VECTOR2(0, -1));
	return  Data;
}

void PieceLancer::Draw()
{
	DrawPos = (pos * PIECE_SIZE) + offset;
	DrawBox(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 56, 0xcd853f, true);
	DrawTriangle(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 24, DrawPos.x + 32, DrawPos.y + 8, 0xcd853f, true);
	DrawString(DrawPos.x + 25, DrawPos.y + 20, "��\n��", 0, true);
}
#include "PieceBishop.h"



PieceBishop::PieceBishop()
{
}


PieceBishop::~PieceBishop()
{
}

bool PieceBishop::SetPos(VECTOR2 pos, VECTOR2 Offset)
{
	if (Offset != -1)
	{
		offset = Offset;
	}
	this->pos = pos;
	return true;
}

std::vector<VECTOR2> PieceBishop::isMove()
{
	std::vector<VECTOR2> Data;
	Data.push_back(VECTOR2(-1, -1));
	Data.push_back(VECTOR2(1, -1));
	Data.push_back(VECTOR2(-1, 1));
	Data.push_back(VECTOR2(1, 1));
	return  Data;
}

VECTOR2 PieceBishop::GetPos()
{
	return pos;
}

void PieceBishop::Draw()
{
	DrawPos = (pos * PIECE_SIZE) + offset;
	DrawBox(DrawPos.x + 7, DrawPos.y + 23, DrawPos.x + 57, DrawPos.y + 57, 0, true);
	DrawTriangle(DrawPos.x + 7, DrawPos.y + 23, DrawPos.x + 57, DrawPos.y + 23, DrawPos.x + 33, DrawPos.y + 7, 0, true);

	DrawBox(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 56, 0xcd853f, true);
	DrawTriangle(DrawPos.x + 8, DrawPos.y + 24, DrawPos.x + 56, DrawPos.y + 24, DrawPos.x + 32, DrawPos.y + 8, 0xcd853f, true);
	DrawString(DrawPos.x + 25, DrawPos.y + 28, "Šp", 0, true);
}

bool PieceBishop::Endless()
{
	return true;
}

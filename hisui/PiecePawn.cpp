#include "PiecePawn.h"


PiecePawn::PiecePawn()
{
	pos = { 0, 0 };
	offset = { 540 - 32 * 9, 360 - 32 * 9 };
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

void PiecePawn::Draw()
{
	VECTOR2 DrawPos = pos + offset;
	DrawBox(DrawPos.x, DrawPos.y, DrawPos.x+64, DrawPos.y+64,0xffffff,true);
	DrawString(DrawPos.x+25, DrawPos.y+25,"•à",0,true);
}

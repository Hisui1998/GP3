#include <Dxlib.h>
#include "MouseCtl.h"


MouseCtl::MouseCtl()
{
	pos = { 0,0 };
}


MouseCtl::~MouseCtl()
{
}

void MouseCtl::UpDate(void)
{
	MouseSt[ST_OLD] = MouseSt[ST_NOW];
	MouseSt[ST_NOW] = GetMouseInput();

	GetMousePoint(&pos.x, &pos.y);
}

VECTOR2 MouseCtl::GetMousePos(void) const 
{
	return pos;
}

mInt MouseCtl::GetMouseState(void) const 
{
	return MouseSt;
}

#pragma once
#include <Dxlib.h>
#include "VECTOR2.h"
class GamePiece
{
public:
	virtual ~GamePiece();

	/// ç¿ïWånä÷êî
	virtual bool SetPos(VECTOR2 pos) = 0;
	virtual VECTOR2 GetPos() = 0;
	/// ï`âÊånä÷êî
	virtual void Draw() = 0;
};


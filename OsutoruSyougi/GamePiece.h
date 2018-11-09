#pragma once
#include <Dxlib.h>
#include <vector>
#include "VECTOR2.h"

#define SCR_SIZR_X 1080
#define SCR_SIZR_Y 720
#define PIECE_SIZE 64

class GamePiece
{
public:
	virtual ~GamePiece();

	/// ç¿ïWånä÷êî
	virtual bool SetPos(VECTOR2 pos) = 0;
	virtual VECTOR2 GetPos() = 0;
	/// ï`âÊånä÷êî
	virtual void Draw() = 0;
	virtual std::vector<VECTOR2> isMove() = 0;
};


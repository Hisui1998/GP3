#pragma once
#include <Dxlib.h>
#include "VECTOR2.h"
class GamePiece
{
public:
	virtual ~GamePiece();

	/// ���W�n�֐�
	virtual bool SetPos(VECTOR2 pos) = 0;
	virtual VECTOR2 GetPos() = 0;
	/// �`��n�֐�
	virtual void Draw() = 0;
};


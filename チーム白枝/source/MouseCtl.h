#pragma once
#include <array>
#include "VECTOR2.h"

enum MOUSE_ST
{
	ST_NOW,
	ST_OLD,
	ST_MAX
};

using mInt = std::array<int, ST_MAX>;

class MouseCtl
{
public:
	MouseCtl();
	~MouseCtl();

	// ϳ��̏�ԍX�V�֐�
	void UpDate(void);

	// ϳ��̍��W�擾�֐�
	VECTOR2 GetMousePos(void) const;

	// ϳ��̏�Ԏ擾�֐�
	mInt GetMouseState(void) const;
private:
	VECTOR2 pos;	// ���W
	mInt MouseSt;	// ϳ��̏��
};


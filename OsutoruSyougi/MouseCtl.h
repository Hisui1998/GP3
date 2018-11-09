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

	// ﾏｳｽの状態更新関数
	void UpDate(void);

	// ﾏｳｽの座標取得関数
	VECTOR2 GetMousePos(void) const;

	// ﾏｳｽの状態取得関数
	mInt GetMouseState(void) const;
private:
	VECTOR2 pos;	// 座標
	mInt MouseSt;	// ﾏｳｽの状態
};


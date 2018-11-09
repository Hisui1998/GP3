#pragma once
#include <memory>

class MouseControl;
struct GameBase;
using GState_ptr = std::unique_ptr<GameBase>;

struct GameBase
{
	virtual ~GameBase();
	virtual bool Init(void) = 0;
	virtual GState_ptr Update(GState_ptr own, const MouseControl & mouseCtl) = 0;
};

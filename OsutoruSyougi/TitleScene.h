#pragma once
#include <memory>
#include "GameBase.h"
class TitleScene :
	public GameBase
{
public:
	TitleScene();
	~TitleScene();
	bool Init(void);
	GState_ptr Update(GState_ptr own, const MouseControl & mouseCtl);
};


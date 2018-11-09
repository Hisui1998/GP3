#pragma once
#include "BaseScene.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	bool Init(void);
	unique_Base Update(unique_Base ptr, MouseCtl mouseCtl);
private:
	int fontHandle;
};


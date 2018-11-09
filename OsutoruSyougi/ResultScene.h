#pragma once
#include "BaseScene.h"
class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	bool Init(void);
	unique_Base Update(unique_Base ptr, MouseCtl mouseCtl);
private:
	int fontHandle;
};


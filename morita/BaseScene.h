#pragma once
#include <memory>
#include "MouseCtl.h"
#include "DxLib.h"
#include "GameTask.h"
class MouseCtl;
class BaseScene;

#define SCREEN_SIZE_X 1080
#define SCREEN_SIZE_Y 720

typedef std::unique_ptr<BaseScene> unique_Base;

class BaseScene
{
public:
	virtual ~BaseScene();
	virtual bool Init(void) = 0;											
	virtual unique_Base Update(unique_Base ptr, MouseCtl mouseCtl) = 0;
};


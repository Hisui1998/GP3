#include "ResultScene.h"
#include "TitleScene.h"


ResultScene::ResultScene()
{
	Init();
}


ResultScene::~ResultScene()
{
}

bool ResultScene::Init(void)
{
	return false;
}

unique_Base ResultScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	ClsDrawScreen();

	DrawString(0, 0, "‚è‚´‚é‚Æ", 0xffffff, true);

	ScreenFlip();
	if ((mouseCtl.GetBtn()[ST_NOW] & (~mouseCtl.GetBtn()[ST_OLD])) & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<TitleScene>();
	}
	return ptr;
}

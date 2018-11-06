#include "ResultScene.h"
#include "TitleScene.h"


ResultScene::ResultScene()
{
	Init();
}


ResultScene::~ResultScene()
{
	DeleteFontToHandle(fontHandle);
}

bool ResultScene::Init(void)
{
	fontHandle = CreateFontToHandle("Georgia", 32, 8, DX_FONTTYPE_EDGE);
	return false;
}

unique_Base ResultScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	ClsDrawScreen();

	DrawString(0, 0, "�肴���", 0xffffff, true);
	DrawStringToHandle(SCREEN_SIZE_X / 2 - 133, SCREEN_SIZE_Y / 2 + 150, "Please Click,", 0xffffff, fontHandle);
	DrawStringToHandle(SCREEN_SIZE_X / 2 - 100, SCREEN_SIZE_Y / 2 + 180, "Return to Title.", 0xffffff, fontHandle);

	ScreenFlip();
	if ((mouseCtl.GetBtn()[ST_NOW] & (~mouseCtl.GetBtn()[ST_OLD])) & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<TitleScene>();
	}
	return ptr;
}

#include "TitleScene.h"
#include "MainScene.h"
#define SCREEN_SIZE_X 1080
#define SCREEN_SIZE_Y 720


TitleScene::TitleScene()
{
	Init();
}


TitleScene::~TitleScene()
{
}

bool TitleScene::Init(void)
{
	
	return false;
}

unique_Base TitleScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	int fontHandle;
	ClsDrawScreen();

	DrawString(0, 0, "‚½‚¢‚Æ‚é", 0xffffff, true);
	fontHandle = CreateFontToHandle(NULL,32,8, DX_FONTTYPE_EDGE);
	DrawStringToHandle(SCREEN_SIZE_X/2-133,SCREEN_SIZE_Y/2 + 200 , "Please Click", 0xffffff, fontHandle);
	DeleteFontToHandle(fontHandle);

	ScreenFlip();

	if ((mouseCtl.GetBtn()[ST_NOW] & (~mouseCtl.GetBtn()[ST_OLD])) & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<MainScene>();
	}
	return ptr;
}

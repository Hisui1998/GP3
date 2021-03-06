#include "TitleScene.h"
#include "MainScene.h"



TitleScene::TitleScene()
{
	Init();
}


TitleScene::~TitleScene()
{
	DeleteFontToHandle(fontHandle);
}

bool TitleScene::Init(void)
{

	fontHandle = CreateFontToHandle("Georgia", 32, 8, DX_FONTTYPE_EDGE);
	BlinkCnt = 0;
	return false;
}

unique_Base TitleScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	BlinkCnt++;
	ClsDrawScreen();

	DrawString(0, 0, "�����Ƃ�", 0xffffff, true);
	if ((BlinkCnt / 30) % 2)
	{
		DrawStringToHandle(SCREEN_SIZE_X / 2 - 133, SCREEN_SIZE_Y / 2 + 150, "Please Click", 0xffffff, fontHandle);
	}

	ScreenFlip();

	if ((mouseCtl.GetMouseState()[ST_NOW] & (~mouseCtl.GetMouseState()[ST_OLD])) & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<MainScene>();
	}
	return ptr;
}

#include "DxLib.h"
#include "TitleScene.h"
#include "ImageManager.h"
#include "MouseControl.h"
#include "GameMain.h"

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

bool TitleScene::Init(void)
{
	return false;
}

GState_ptr TitleScene::Update(GState_ptr own, const MouseControl & mouseCtl)
{
	if ((mouseCtl.GetButton()[ST_NOW]) & (~mouseCtl.GetButton()[ST_OLD]))
	{
		return std::make_unique<GameMain>();
	}
	ClsDrawScreen();
	DrawGraph(0, 0, IMAGE_ID("image/IMG_6428.png")[0], true);
	DrawString(0, 0, "Title", 0xffffff, true);
	ScreenFlip();
	return move(own);
}

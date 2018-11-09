#include "ResultScene.h"
#include "TitleScene.h"
#include "GameBoard.h"


ResultScene::ResultScene(std::shared_ptr<GameBoard> _ptr, player_List _plist)
{
	Init();
	gBoard = _ptr;
	playerList = _plist;
}


ResultScene::~ResultScene()
{
	DeleteFontToHandle(fontHandle);
}

bool ResultScene::Init(void)
{
	fontHandle = CreateFontToHandle("Georgia", 32, 8, DX_FONTTYPE_EDGE);
	BlinkCnt = 0;
	return false;
}

unique_Base ResultScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	BlinkCnt++;
	ClsDrawScreen();

	DrawString(0, 0, "‚è‚´‚é‚Æ", 0xffffff, true);
	if ((BlinkCnt / 30) % 2)
	{
		DrawStringToHandle(SCREEN_SIZE_X / 2 - 133, SCREEN_SIZE_Y / 2 + 150, "Please Click,", 0xffffff, fontHandle);
		DrawStringToHandle(SCREEN_SIZE_X / 2 - 100, SCREEN_SIZE_Y / 2 + 180, "Return to Title.", 0xffffff, fontHandle);
	}

	gBoard->Draw();
	for (auto itr : playerList)
	{
		itr->Draw();
	}

	ScreenFlip();
	if ((mouseCtl.GetMouseState()[ST_NOW] & (~mouseCtl.GetMouseState()[ST_OLD])) & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<TitleScene>();
	}
	return ptr;
}

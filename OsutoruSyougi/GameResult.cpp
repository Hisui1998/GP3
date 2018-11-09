#include "DxLib.h"
#include "GameResult.h"
#include "MouseControl.h"
#include "TitleScene.h"

GameResult::GameResult()
{
	Init();
}

GameResult::GameResult(std::shared_ptr<GameBoard> gameboard)
{
	Init();
	this->gameboard = gameboard;
}


GameResult::~GameResult()
{
}

bool GameResult::Init(void)
{
	return false;
}

GState_ptr GameResult::Update(GState_ptr own, const MouseControl & mouseCtl)
{
	if ((mouseCtl.GetButton()[ST_NOW]) & (~mouseCtl.GetButton()[ST_OLD]))
	{
		return std::make_unique<TitleScene>();
	}
	ClsDrawScreen();
	gameboard->Draw();
	DrawString(0, 0, "Rez", 0xffffff, true);
	ScreenFlip();
	return move(own);
}

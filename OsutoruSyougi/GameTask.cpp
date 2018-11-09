#include "DxLib.h"
#include "GameTask.h"
#include "ImageManager.h"
#include "TitleScene.h"
#include "MainScene.h"
#include "ResultScene.h"

std::unique_ptr<GameTask, GameTask::GameTaskDeleter> GameTask::s_Instance(new GameTask());

GameTask::GameTask()
{
	SysInit();
}


GameTask::~GameTask()
{
	DxLib_End();	// DX×²ÌŞ×Ø‚ÌI—¹ˆ—
}

void GameTask::Run(void)
{
	mouseCtl = std::make_unique<MouseCtl>();
	activSceen = std::make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		mouseCtl->UpDate();
		activSceen = (*activSceen).Update(std::move(activSceen), *mouseCtl);
	}
}

VECTOR2 GameTask::GetScreenSize(void)
{
	return VECTOR2(SCREEN_SIZE_X, SCREEN_SIZE_Y);
}

int GameTask::SysInit(void)
{
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		// 65536FÓ°ÄŞ‚Éİ’è
	ChangeWindowMode(true);				// true:window@false:ÌÙ½¸Ø°İ
	SetWindowText("1701319_”’}—F‹I_ƒIƒZƒ");
	if (DxLib_Init() == -1)
	{
		return false;					// DX×²ÌŞ×Ø‰Šú‰»ˆ—
	}
	SetDrawScreen(DX_SCREEN_BACK);		// ‚Ğ‚Æ‚Ü‚¸ÊŞ¯¸ÊŞ¯Ì§‚É•`‰æ
	return true;
}

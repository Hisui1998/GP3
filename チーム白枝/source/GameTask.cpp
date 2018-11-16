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
	DxLib_End();	// DXﾗｲﾌﾞﾗﾘの終了処理
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
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		// 65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);				// true:window　false:ﾌﾙｽｸﾘｰﾝ
	SetWindowText("オウオストル");
	if (DxLib_Init() == -1)
	{
		return false;					// DXﾗｲﾌﾞﾗﾘ初期化処理
	}
	SetDrawScreen(DX_SCREEN_BACK);		// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
	return true;
}

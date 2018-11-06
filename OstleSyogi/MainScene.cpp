#include "MainScene.h"
#include"ResultScene.h"


MainScene::MainScene()
{
	Init();
}

MainScene::~MainScene()
{
}

bool MainScene::Init(void)
{
	auto Makeplayer = [=]() {
		//playerList.push_back(*&std::shared_ptr<Player>(new Player()));
	};
	//player = playerList.begin();
	return false;
}

unique_Base MainScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	ClsDrawScreen();

	DrawString(0, 0, "�߂���", 0xffffff, true);

	ScreenFlip();
	if ((mouseCtl.GetBtn()[ST_NOW] & (~mouseCtl.GetBtn()[ST_OLD])) & MOUSE_INPUT_LEFT)
	{
		return std::make_unique<ResultScene>();
	}
	return ptr;
}

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
		playerList.push_back(*&std::shared_ptr<Player>(new Player()));
	};
	gBoard = std::make_shared<GameBoard>();
	playerList.clear();

	Makeplayer();
	Makeplayer();
	player = playerList.begin();
	return false;
}

unique_Base MainScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	ClsDrawScreen();

	DrawString(0, 0, "‚ß‚¢‚ñ", 0xffffff, true);

	if ((*player)->CheckTurn(mouseCtl, *gBoard) == true)
	{
		player++;
		if (player == playerList.end())
		{
			player = playerList.begin();
		}
	}

	gBoard->Draw();
	for (auto itr : playerList)
	{
		itr->Draw();
	}

	ScreenFlip();
	if ((mouseCtl.GetMouseState()[ST_NOW] & (~mouseCtl.GetMouseState()[ST_OLD])) & MOUSE_INPUT_RIGHT)
	{
		return std::make_unique<ResultScene>(gBoard,playerList);
	}
	return ptr;
}

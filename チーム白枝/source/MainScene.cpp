#include "MainScene.h"
#include "ResultScene.h"
#include "MouseCtl.h"
#include "GameBoard.h"

MainScene::MainScene()
{
	Init();
}

MainScene::~MainScene()
{
}

bool MainScene::Init(void)
{
	gBoard = std::make_shared<GameBoard>();
	auto Makeplayer = [=]() {
		playerList.push_back(*&std::shared_ptr<Player>(new Player(gBoard)));
	};
	playerList.clear();

	Makeplayer();
	Makeplayer();
	player = playerList.begin();
	return false;
}

unique_Base MainScene::Update(unique_Base ptr, MouseCtl mouseCtl)
{
	ClsDrawScreen();


	if ((*player)->CheckTurn(mouseCtl) == true)
	{
		player++;
		if (player == playerList.end())
		{
			player = playerList.begin();
		}
	}
	if ((*player)->CheckPiece(mouseCtl))
	{

	}
	gBoard->Draw();
	for (auto itr : playerList)
	{
		itr->Update();
		itr->Draw();
	}
	DrawString(0,50,"右クリック、強制リザルト",0xffffff,true);
	ScreenFlip();
	if ((mouseCtl.GetMouseState()[ST_NOW] & (~mouseCtl.GetMouseState()[ST_OLD])) & MOUSE_INPUT_RIGHT)
	{
		return std::make_unique<ResultScene>(gBoard/*,playerList*/);
	}
	return ptr;
}

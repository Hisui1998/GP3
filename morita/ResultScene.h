#pragma once
#include "BaseScene.h"
#include "MainScene.h"
class GameBoard;

class ResultScene :
	public BaseScene
{
public:
	ResultScene(std::shared_ptr<GameBoard> _ptr, player_List _plist);
	~ResultScene();
	bool Init(void);
	unique_Base Update(unique_Base ptr, MouseCtl mouseCtl);
private:
	int fontHandle;
	int BlinkCnt;

	std::shared_ptr<GameBoard> gBoard;
	player_List playerList;
};


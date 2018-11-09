#pragma once
#include "GameBase.h"
#include "GameBoard.h"
class GameResult :
	public GameBase
{
public:
	GameResult();
	GameResult(std::shared_ptr<GameBoard> gameboard);
	~GameResult();
	bool Init(void);
	GState_ptr Update(GState_ptr own, const MouseControl & mouseCtl);
private:
	std::shared_ptr<GameBoard> gameboard;
};


#pragma once
#include "BaseScene.h"

class GameBoard;

class ResultScene :
	public BaseScene
{
public:
	ResultScene(std::shared_ptr<GameBoard> _ptr);
	~ResultScene();
	bool Init(void);
	unique_Base Update(unique_Base ptr, MouseCtl mouseCtl);
private:
	int fontHandle;
	int BlinkCnt;

	std::shared_ptr<GameBoard> gBoard;
};


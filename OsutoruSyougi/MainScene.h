#pragma once
#include "BaseScene.h"
class MouseCtl;

//typedef std::shared_ptr<Player> player_ptr;
//typedef std::list<player_ptr> player_List;

class MainScene :
	public BaseScene
{
public:
	MainScene();
	~MainScene();
	bool Init(void);
	unique_Base Update(unique_Base ptr, MouseCtl mouseCtl);

private:
	//std::shared_ptr<GameBoard> gBoard;
	//player_List playerList;
	//player_List::iterator player;
};


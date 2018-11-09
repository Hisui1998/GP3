#pragma once
#include "GameBase.h"
#include "Player.h"

typedef std::shared_ptr<Player> player_ptr;
typedef std::list<player_ptr> player_List;

class GameMain :
	public GameBase
{
public:
	GameMain();
	~GameMain();
	bool Init();
	GState_ptr Update(GState_ptr own,const MouseControl & mouseCtl);
	const VECTOR2 GetActiveBoardSize(void);
private:
	void MakePlayer(void);
	//bool SetNextPlayer(void);

	std::shared_ptr<GameBoard> gameboard;
	player_List::iterator player;
	player_List playerList;
};


#include "DxLib.h"
#include "GameMain.h"
#include "MouseControl.h"
#include "GameResult.h" 

GameMain::GameMain()
{
	Init();
}


GameMain::~GameMain()
{
}

bool GameMain::Init()
{
	gameboard = std::make_unique<GameBoard>();

	playerList.clear();
	for (int i = 0; i < 2; i++)
	{
		MakePlayer();
	}
	player = playerList.begin();
	(*player)->SetTurn(true);
	//TurnPL_Piece = std::make_unique<GamePiece>(VECTOR2(15, 15), VECTOR2(0, 0), (*player)->GetPiece());
	gameboard->SetPiece(PIECE_B, 3, 4);
	gameboard->SetPiece(PIECE_W, 3, 3);
	gameboard->SetPiece(PIECE_B, 4, 3);
	gameboard->SetPiece(PIECE_W, 4, 4);
	gameboard->PieceCnt();
	return true;
}

GState_ptr GameMain::Update(GState_ptr own, const MouseControl & mouseCtl)
{
	auto setNextPlayer = [&]{
		(*player)->SetTurn(false);
		player++;
		if (player == playerList.end())
		{
			player = playerList.begin();
		}
		(*player)->SetTurn(true);
		//TurnPL_Piece->SetState((*player)->GetPiece());
		gameboard->PieceCnt();
		gameboard->PiecePointSize((*player)->GetPiece());
		if (gameboard->CheckAutoPass())
		{
			return false;
		}
		return true;
	};

	if ((*player)->TunAct(mouseCtl, *gameboard))
	{
		gameboard->SetReverse((*player)->GetPiece(), mouseCtl.GetPoint());
		//SetNextPlayer();
		setNextPlayer();
	}
	if (gameboard->CheckAutoPass())
	{
		if (!setNextPlayer())
		{
			return std::make_unique<GameResult>(gameboard);
		}
	}

	ClsDrawScreen();
	gameboard->Update();
	gameboard->Draw();
	for (auto data : playerList)
	{
		(*data).Draw();
	}
	DrawString(0, 0, "GameMain", 0xffffff);
	ScreenFlip();

	return std::move(own);
}

const VECTOR2 GameMain::GetActiveBoardSize(void)
{
	return gameboard->GetBoradSize();
}

void GameMain::MakePlayer(void)
{
	playerList.push_back(std::make_shared<Player>(gameboard));
}

//bool GameMain::SetNextPlayer(void)
//{
//	(*player)->SetTurn(false);
//	player++;
//	if (player == playerList.end())
//	{
//		player = playerList.begin();
//	}
//	(*player)->SetTurn(true);
//	//TurnPL_Piece->SetState((*player)->GetPiece());
//	gameboard->PieceCnt();
//	gameboard->PiecePointSize((*player)->GetPiece());
//	if (gameboard->CheckAutoPass())
//	{
//		return false;
//	}
//	return true;
//}

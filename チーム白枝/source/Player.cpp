#include "Player.h"
#include "MouseCtl.h"
#include "GameBoard.h"
#include "GamePiece.h"
#include "PieceTray.h"


int Player::PlCnt = 0;

Player::Player(std::shared_ptr<GameBoard> gameboard)
{
	state = (PIECE_ST)PlCnt++;
	isSelect = false;
	this->gameboard = gameboard;
	pieceTray = std::make_unique<PieceTray>(state);
	/*
	生成時にﾋﾟｰｽを作ってボードに設置する
	そのあとﾋﾟｰｽﾄﾚｲにも歩のコマを三つ追加する
	*/
}


Player::~Player()
{
}

bool Player::CheckTurn(MouseCtl & _Mc)
{
	bool rtnFlag = false;

	// ﾏｳｽの状態保持変数
	mInt m_info = _Mc.GetMouseState();

	if ((_Mc.GetMouseState()[ST_NOW] & (~_Mc.GetMouseState()[ST_OLD])) & MOUSE_INPUT_LEFT)
	{
		if (!isSelect)
		{
			if (CheckPiece(_Mc))
			{
				isSelect = true;
				oldmPos = _Mc.GetMousePos();
			}
			else if((*gameboard).GetHolePos() == gameboard->ChangeScreenToTable(_Mc.GetMousePos()))
			{
			}
		}
		else
		{
			if (MovePiece(_Mc, oldmPos))
			{
				isSelect = false;
				rtnFlag = true;
				oldmPos = VECTOR2(0,0);
			}
			else
			{
				isSelect = false;
			}
		}
	}

	return rtnFlag;
}


bool Player::CheckPiece(MouseCtl & mouseCtl)
{
	bool retFlag = false;
	VECTOR2 mPos = gameboard->ChangeScreenToTable(mouseCtl.GetMousePos());
	auto piece = pieceTray->GetPiece(mPos);
	if (piece != nullptr)
	{
		if (VECTOR2(0,0) <= piece->GetPos() && piece->GetPos() < gameboard->GetBoardSize())
		{
			for (auto data : piece->isMove())
			{
				retFlag |= CheckPiece(piece, mPos, data);
			}
		}
	}
	return retFlag;
}

bool Player::CheckPiece(std::shared_ptr<GamePiece> piece, VECTOR2 mPos, VECTOR2 vec)
{
	bool retFlag = false;
	VECTOR2 tmpPos = (mPos + vec);
	{
		if (VECTOR2(0, 0) <= tmpPos && tmpPos < gameboard->GetBoardSize())
		{
				retFlag = true;
		}
	}
	return retFlag;
}

bool Player::MovePiece(MouseCtl & mouseCtl, VECTOR2 pos)
{
	bool retFlag = false;
	bool nextFlag = true;
	VECTOR2 mPos = gameboard->ChangeScreenToTable(mouseCtl.GetMousePos());
	VECTOR2 oldmPos = gameboard->ChangeScreenToTable(pos);
	auto mpiece = pieceTray->GetPiece(mPos);
	auto oldpiece = pieceTray->GetPiece(oldmPos);
	if (VECTOR2(0, 0) <= mPos && mPos < gameboard->GetBoardSize())
	{
		for (auto data : oldpiece->isMove())
		{
			while (nextFlag)
			{
				nextFlag = false;
				if (oldpiece->Endless())
				{
					nextFlag = true;
					oldmPos = oldmPos + data;
					if (VECTOR2(0, 0) <= oldmPos && oldmPos < gameboard->GetBoardSize())
					{
						if (mPos == (oldmPos))
						{
							oldpiece->SetPos(mPos);
							if (mpiece != nullptr)
							{
								mpiece->SetPos(mPos + data);
							}
							oldmPos = gameboard->ChangeScreenToTable(pos);
							nextFlag = false;
							retFlag = true;
						}
						else
						{
							nextFlag = true;
						}
					}
					else
					{
						oldmPos = gameboard->ChangeScreenToTable(pos);
						nextFlag = false;
					}
				}
				else
				{
					if (mPos == (oldmPos + data))
					{
						oldpiece->SetPos(mPos);
						if (mpiece != nullptr)
						{
							mpiece->SetPos(mPos + data);
						}
						retFlag = true;
					}
					else
					{
						nextFlag = false;
						oldmPos = gameboard->ChangeScreenToTable(pos);
					}
				}
			}
			nextFlag = true;
		}
	}
	return retFlag;
}

void Player::Update(void)
{
	auto piece = pieceTray->GetPiece((*gameboard).GetHolePos());
	if (piece != nullptr)
	{
		piece->SetPos(VECTOR2(0, 1), VECTOR2(SCR_SIZR_X - (PIECE_SIZE / 2) - 192, SCR_SIZR_Y - (PIECE_SIZE / 2) - 192));
	}
}

void Player::Draw()
{
	VECTOR2 offset = gameboard->GetDrawLT();
	// pieceTrayの中身があれば
	if(pieceTray)
	{
		pieceTray->Draw();
	}
	for (auto itr = piecePointList.begin(); itr != piecePointList.end(); itr++)
	{
		DrawBox((*itr).x * 64 + offset.x, (*itr).y * 64 + offset.y, ((*itr).x + 1) * 64 + offset.x, ((*itr).y + 1) * 64 + offset.y, 0x00ffff, true);
	}
	//DrawFormatString(0, 0, 0xffffff, "ターンプレイヤーはP%dです", );
}

void Player::PiecePosintSize()
{
	piecePointList.clear();
	VECTOR2 boardSize = gameboard->GetBoardSize();
	for (unsigned int y = 0; y < (unsigned int)boardSize.y; y++)
	{
		for (unsigned int x = 0; x < (unsigned int)boardSize.x; x++)
		{
			//if ()
			{
				piecePointList.push_back(VECTOR2(x, y));
			}
		}
	}
}

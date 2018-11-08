#include "PieceTray.h"
#include "Player.h"
#include "MouseCtl.h"
#include "GameBoard.h"
#include "DxLib.h"

int Player::playerCnt = 0;
Player::Player()
{
	state = (PIECE_ST)playerCnt;
	playerCnt++;
	ClickPos = { 0,0 };
	pieceTray = std::make_unique<PieceTray>(state);
}

Player::~Player()
{
}

bool Player::Draw(void)
{
	if (pieceTray)
	{
		pieceTray->Draw();
		return true;
	}
	return false;
}

PIECE_ST Player::GetPlayer(void)
{
	return Player::state;
}

int Player::GetPlayerCnt(void)
{
	return Player::playerCnt;
}

void Player::SetClickPos(VECTOR2 pos)
{
	ClickPos = pos;
}

VECTOR2 Player::GetClickPos(void)
{
	return ClickPos;
}

bool Player::CheckTurn(const MouseCtl & _mCtl, GameBoard & _gB)
{
	pieceTray->SetTurnFlag(true);
	VECTOR2 mPos = _gB.ChangeScreenToTable(_mCtl.GetPoint());
	if ((_mCtl.GetMouseState()[ST_NOW] & MOUSE_INPUT_LEFT) && !(_mCtl.GetMouseState()[ST_OLD] & MOUSE_INPUT_LEFT))
	{
		if (_gB.GetBoardLT() < _mCtl.GetMousePos())
		{
			if (VECTOR2(0, 0) <= mPos && mPos <= _gB.GetDataSize())
			{
				// 押した座標が自分の駒の存在する場所か
				if (_gB.GetPiece((PIECE_ST)state, _mCtl.GetPoint()) == (PIECE_ST)state)
				{
					// 既に駒を押している場合
					if (playerFlag)
					{
						VECTOR2 checkPos = _gB.ChangePiece(GetClickPos());

						// 今押している座標が前回押した座標と一致する場合
						if (mPos == checkPos)
						{
							// ﾌﾗｸﾞを切り替えてﾘｾｯﾄする
							playerFlag = false;
							return false;
						}
					}
					// 一度も押していない場合
					else
					{
						// 前回押した座標として保存する
						SetClickPos(_mCtl.GetMousePos());

						// 既に駒を押している用にﾌﾗｸﾞを切り替える
						playerFlag = true;
						return false;
					}
				}
				// 自分の駒の存在しない座標の場合
				else
				{
					// 既に駒を押している場合
					if (playerFlag)
					{
						// ﾌﾗｸﾞを切り替えてﾘｾｯﾄする
						playerFlag = false;

						return true;
					}
					return false;
				}
			}
		}

	}
	return false;
}

bool Player::SetTurnPlayer(bool flag)
{
	return pieceTray->SetTurnFlag(flag);
}



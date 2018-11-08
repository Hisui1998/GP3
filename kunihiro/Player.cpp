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
				// ���������W�������̋�̑��݂���ꏊ��
				if (_gB.GetPiece((PIECE_ST)state, _mCtl.GetPoint()) == (PIECE_ST)state)
				{
					// ���ɋ�������Ă���ꍇ
					if (playerFlag)
					{
						VECTOR2 checkPos = _gB.ChangePiece(GetClickPos());

						// �������Ă�����W���O�񉟂������W�ƈ�v����ꍇ
						if (mPos == checkPos)
						{
							// �׸ނ�؂�ւ���ؾ�Ă���
							playerFlag = false;
							return false;
						}
					}
					// ��x�������Ă��Ȃ��ꍇ
					else
					{
						// �O�񉟂������W�Ƃ��ĕۑ�����
						SetClickPos(_mCtl.GetMousePos());

						// ���ɋ�������Ă���p���׸ނ�؂�ւ���
						playerFlag = true;
						return false;
					}
				}
				// �����̋�̑��݂��Ȃ����W�̏ꍇ
				else
				{
					// ���ɋ�������Ă���ꍇ
					if (playerFlag)
					{
						// �׸ނ�؂�ւ���ؾ�Ă���
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



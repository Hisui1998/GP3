#include "Player.h"
#include "MouseCtl.h"
#include "GameBoard.h"

int Player::PlCnt = 0;

Player::Player()
{
	state = (PIECE_ST)PlCnt++;
	isSelect = false;

	/*
	生成時にﾋﾟｰｽを作ってボードに設置する
	そのあとﾋﾟｰｽﾄﾚｲにも歩のコマを三つ追加する
	*/
}


Player::~Player()
{
}

bool Player::CheckTurn(MouseCtl & _Mc, GameBoard & _Gb)
{
	bool rtnFlag = false;

	// ﾏｳｽの状態保持変数
	mInt m_info = _Mc.GetMouseState();

	if (m_info[ST_NOW] != m_info[ST_OLD])
	{
		if (!isSelect)
		{
			if (_Gb.SelectPiece(_Mc.GetMousePos()))
			{
				isSelect = true;
			}
		}
		else
		{
			if (_Gb.CheckSet(state))
			{
				isSelect = false;
				rtnFlag = true;
			}
		}
	}

	return rtnFlag;
}

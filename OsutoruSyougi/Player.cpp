#include "Player.h"
#include "MouseCtl.h"
#include "GameBoard.h"
#include "GamePiece.h"
#include "PiecePawn.h"
int Player::PlCnt = 0;

Player::Player()
{
	state = (PIECE_ST)PlCnt++;
	isSelect = false;
	hu = std::make_unique<PiecePawn>();
	/*
	���������߰�������ă{�[�h�ɐݒu����
	���̂����߰��ڲ�ɂ����̃R�}���O�ǉ�����
	*/
}


Player::~Player()
{
}

bool Player::CheckTurn(MouseCtl & _Mc, GameBoard & _Gb)
{
	bool rtnFlag = false;

	// ϳ��̏�ԕێ��ϐ�
	mInt m_info = _Mc.GetMouseState();

	//if (m_info[ST_NOW] != m_info[ST_OLD])
	//{
	//	//if (!isSelect)
	//	//{
	//	//	if (_Gb.SelectPiece(_Mc.GetMousePos()))
	//	//	{
	//	//		isSelect = true;
	//	//	}
	//	//}
	//	//else
	//	//{
	//	//	if (_Gb.CheckSet(state))
	//	//	{
	//	//		isSelect = false;
	//	//		rtnFlag = true;
	//	//	}
	//	//}
	//}

	return rtnFlag;
}

void Player::Draw()
{
	hu->Draw();
}

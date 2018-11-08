#include <memory>
#include "VECTOR2.h"
#include "PieceState.h"

class MouseCtl;
class GameBoard;
class GamePiece;
class PieceTray;

#pragma once
class Player
{
public:
	Player();
	~Player();
	bool Draw(void);

	// ��ڲ԰�̊Ǘ�
	PIECE_ST GetPlayer(void);
	int GetPlayerCnt(void);

	// �����̋�����������̍��W�̊Ǘ�
	void SetClickPos(VECTOR2 pos);
	VECTOR2 GetClickPos(void);

	// �ړ��n�̊Ǘ�
	bool CheckTurn(const MouseCtl & mouseCtl, GameBoard & actBoard);

	bool SetTurnPlayer(bool flag);

private:

	// ��������̍��W�̕ۑ�
	VECTOR2 ClickPos = { 0,0 };
	// ���������̋���׸�
	bool playerFlag;

	static int playerCnt;

	PIECE_ST state;

	std::unique_ptr <PieceTray> pieceTray;

};


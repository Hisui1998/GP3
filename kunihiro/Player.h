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

	// ÌßÚ²Ô°‚ÌŠÇ—
	PIECE_ST GetPlayer(void);
	int GetPlayerCnt(void);

	// ©•ª‚Ì‹î‚ğ‰Ÿ‚µ‚½‚ÌÀ•W‚ÌŠÇ—
	void SetClickPos(VECTOR2 pos);
	VECTOR2 GetClickPos(void);

	// ˆÚ“®Œn‚ÌŠÇ—
	bool CheckTurn(const MouseCtl & mouseCtl, GameBoard & actBoard);

	bool SetTurnPlayer(bool flag);

private:

	// ‰Ÿ‚µ‚½‹î‚ÌÀ•W‚Ì•Û‘¶
	VECTOR2 ClickPos = { 0,0 };
	// ‰Ÿ‚µ‚½‚Ì‹î‚ÌÌ×¸Ş
	bool playerFlag;

	static int playerCnt;

	PIECE_ST state;

	std::unique_ptr <PieceTray> pieceTray;

};


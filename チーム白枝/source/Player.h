#pragma once
#include <memory>
#include <list>
#include "VECTOR2.h"
class MouseCtl;
class GameBoard;
class PieceTray;
class GamePiece;
enum PIECE_ST;

class Player
{
public:
	Player(std::shared_ptr<GameBoard> gameboard);
	~Player();
	void Update(void);
	void Draw();
	void PiecePosintSize();
	// ﾌﾟﾚｲﾔｰのﾀｰﾝ中の処理
	bool CheckTurn(MouseCtl & mouseCtl);
	bool CheckPiece(MouseCtl & mouseCtl);
	bool CheckPiece(std::shared_ptr<GamePiece> piece, VECTOR2 startpos, VECTOR2 vec);

	bool MovePiece(MouseCtl & mouseCtl, VECTOR2 pos);

	//bool MovePiece(std::shared_ptr<GamePiece> piece, VECTOR2 mPos, VECTOR2 vec);

private:
	static int PlCnt;
	PIECE_ST state;
	VECTOR2 oldmPos;
	std::shared_ptr<GameBoard> gameboard;
	// ﾋﾟｰｽ選択中かどうかのﾌﾗｸﾞ
	bool isSelect;
	// 各プレイヤーの持ち駒
	std::unique_ptr<PieceTray> pieceTray;
	// 置ける所リスト
	std::list<VECTOR2> piecePointList;

};


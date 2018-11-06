#pragma once
#include <memory>
class MouseCtl;
class GameBoard;
class PieceTray;
enum PIECE_ST;

class Player
{
public:
	Player();
	~Player();

	// ﾌﾟﾚｲﾔｰのﾀｰﾝ中の処理
	bool CheckTurn(MouseCtl & _Mc, GameBoard & _Gb);
private:
	static int PlCnt;
	PIECE_ST state;
	// ﾋﾟｰｽ選択中かどうかのﾌﾗｸﾞ
	bool isSelect;

	std::unique_ptr<PieceTray> PieceTray;
};


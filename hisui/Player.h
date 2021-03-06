#pragma once
#include <memory>
class MouseCtl;
class GameBoard;
class PieceTray;
class GamePiece;
enum PIECE_ST;

class Player
{
public:
	Player();
	~Player();

	// ﾌﾟﾚｲﾔｰのﾀｰﾝ中の処理
	bool CheckTurn(MouseCtl & _Mc, GameBoard & _Gb);

	void Draw();
private:
	static int PlCnt;
	PIECE_ST state;
	// ﾋﾟｰｽ選択中かどうかのﾌﾗｸﾞ
	bool isSelect;

	std::unique_ptr<PieceTray> Tray;
};


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

	// ÌßÚ²Ô°‚ÌÀ°İ’†‚Ìˆ—
	bool CheckTurn(MouseCtl & _Mc, GameBoard & _Gb);

	void Draw();
private:
	static int PlCnt;
	PIECE_ST state;
	// Ëß°½‘I‘ğ’†‚©‚Ç‚¤‚©‚ÌÌ×¸Ş
	bool isSelect;

	//std::unique_ptr<PieceTray> PieceTray;
	std::shared_ptr<GamePiece> hu;
};


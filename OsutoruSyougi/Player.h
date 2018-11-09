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

	// ��ڲ԰����ݒ��̏���
	bool CheckTurn(MouseCtl & _Mc, GameBoard & _Gb);

	void Draw();
private:
	static int PlCnt;
	PIECE_ST state;
	// �߰��I�𒆂��ǂ������׸�
	bool isSelect;

	//std::unique_ptr<PieceTray> PieceTray;
	std::shared_ptr<GamePiece> hu;
};


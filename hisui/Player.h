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

	// ��ڲ԰����ݒ��̏���
	bool CheckTurn(MouseCtl & _Mc, GameBoard & _Gb);
private:
	static int PlCnt;
	PIECE_ST state;
	// �߰��I�𒆂��ǂ������׸�
	bool isSelect;

	std::unique_ptr<PieceTray> PieceTray;
};


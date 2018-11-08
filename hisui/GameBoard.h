#pragma once
#include <array>
#include <vector>
#include <memory>
#include <list>
#include "VECTOR2.h"

enum PIECE_ST {
	ONE,
	TWO,
	MAX
};

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	void Update(void);
	void Draw(void);
	bool SelectPiece(VECTOR2 pos);
	bool CheckSet(PIECE_ST state);
	VECTOR2 GetBoardSize(void);
private:
	void ReSize(VECTOR2 vec);
	VECTOR2 ChangeScreenToTable(VECTOR2 pos);	// �X�N���[���T�C�Y����e�[�u���T�C�Y��
	VECTOR2 ChangeTableToScreen(VECTOR2 pos);	// �e�[�u���T�C�Y����X�N���[���T�C�Y��

	VECTOR2 screenSize;
	VECTOR2 boardSize;
	VECTOR2 drawLT;
};


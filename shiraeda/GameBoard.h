#pragma once
#include <array>
#include <vector>
#include <memory>
#include <list>
#include "VECTOR2.h"
#include "GamePiece.h"

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
	bool SetPiece(std::shared_ptr<GamePiece> piece,VECTOR2 pos);
private:
	void ReSize(VECTOR2 vec);
	VECTOR2 ChangeScreenToTable(VECTOR2 pos);	// �X�N���[���T�C�Y����e�[�u���T�C�Y��
	VECTOR2 ChangeTableToScreen(VECTOR2 pos);	// �e�[�u���T�C�Y����X�N���[���T�C�Y��

	VECTOR2 screenSize;
	VECTOR2 boardSize;
	VECTOR2 drawLT;
	piece_List pieceList;
};


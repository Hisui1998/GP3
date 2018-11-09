#pragma once
#include <vector>
#include <memory>
#include <list>
#include "VECTOR2.h"
#include "GamePiece.h"

class PieceTray;

using piece_unique = std::unique_ptr<GamePiece>;
using piece_uniqueList = std::unique_ptr<piece_unique>;

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	void Update(void);
	void Draw(void);
	bool CheckSet(const piece_unique & piece, VECTOR2 pos, VECTOR2 table);
	bool SetPiece(const piece_unique & piece, VECTOR2 pos);
	VECTOR2 GetBoardSize(void);
	//bool SelectPiece();
private:
	void ReSize(VECTOR2 vec);
	VECTOR2 ChangeScreenToTable(VECTOR2 pos);	// �X�N���[���T�C�Y����e�[�u���T�C�Y��
	VECTOR2 ChangeTableToScreen(VECTOR2 pos);	// �e�[�u���T�C�Y����X�N���[���T�C�Y��

	VECTOR2 screenSize;
	VECTOR2 boardSize;
	VECTOR2 drawLT;
	const VECTOR2 chTable[8];	// �אڂ��Ă��邩�̃`�F�b�N�p�e�[�u��(����8�}�X)
};


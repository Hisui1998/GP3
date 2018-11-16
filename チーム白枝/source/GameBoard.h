#pragma once
#include <array>
#include <vector>
#include <memory>
#include <list>
#include "VECTOR2.h"
#include "PieceHole.h"

class GamePiece;

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
	bool CheckSet();
	VECTOR2 GetBoardSize(void);
	VECTOR2 GetDrawLT(void);
	void    SetHolePos(VECTOR2 pos);
	VECTOR2 GetHolePos(void);
	VECTOR2 ChangeScreenToTable(VECTOR2 pos);	// スクリーンサイズからテーブルサイズに
	VECTOR2 ChangeTableToScreen(VECTOR2 pos);	// テーブルサイズからスクリーンサイズに

private:
	void ReSize(VECTOR2 vec);

	VECTOR2 screenSize;
	VECTOR2 boardSize;
	VECTOR2 drawLT;
	std::unique_ptr<PieceHole> hole;
};


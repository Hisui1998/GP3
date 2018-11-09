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
	VECTOR2 ChangeScreenToTable(VECTOR2 pos);	// スクリーンサイズからテーブルサイズに
	VECTOR2 ChangeTableToScreen(VECTOR2 pos);	// テーブルサイズからスクリーンサイズに

	VECTOR2 screenSize;
	VECTOR2 boardSize;
	VECTOR2 drawLT;
	const VECTOR2 chTable[8];	// 隣接しているかのチェック用テーブル(周囲8マス)
};


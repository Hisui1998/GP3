#include "DxLib.h"
#include "GameBoard.h"
#include "GameTask.h"
#include "GamePiece.h"

#define BOARD_CNT (9)
#define BOARD_SIZE (64)

GameBoard::GameBoard()
{
	ReSize(VECTOR2(BOARD_CNT, BOARD_CNT));
}


GameBoard::~GameBoard()
{
}

void GameBoard::Update(void)
{

}

void GameBoard::Draw(void)
{
	DrawBox(drawLT.x-10, drawLT.y-10, screenSize.x - drawLT.x + 10, screenSize.y - drawLT.y + 10, 0xffffff, true);
	DrawBox(drawLT.x, drawLT.y, screenSize.x - drawLT.x, screenSize.y - drawLT.y, 0xE6BC8D, true);
	for (int y = 0; y <= GetBoardSize().y; y++)
	{
		DrawLine(drawLT.x, (BOARD_SIZE * y) + drawLT.y, screenSize.x - drawLT.x, (BOARD_SIZE * y) + drawLT.y, 0x000000, true);
	}
	for (int x = 0; x <= GetBoardSize().x; x++)
	{
		DrawLine((BOARD_SIZE * x) + drawLT.x, drawLT.y, (BOARD_SIZE * x) + drawLT.x, screenSize.y - drawLT.y, 0x000000, true);
	}
}

bool GameBoard::SetPiece(pieceSt_unique & pieceSt, VECTOR2 pos)
{
	bool retFlag = false;
	VECTOR2 mousepos = ChangeScreenToTable(pos);
	if (VECTOR2(0, 0) <= mousepos && mousepos < VECTOR2(BOARD_CNT, BOARD_CNT))
	{
		pieceSt->SetPos(pos * BOARD_SIZE);
	}
	return retFlag;
}

VECTOR2 GameBoard::GetBoardSize(void)
{
	return VECTOR2(BOARD_CNT,BOARD_CNT);
}

void GameBoard::ReSize(VECTOR2 vec)
{
	screenSize = lpGameTask.GetScreenSize();	// スクリーンサイズ
	boardSize = vec * BOARD_SIZE;				// ボードサイズ
	drawLT = (screenSize - boardSize) / 2;		// 左端のオフセットサイズ
}

VECTOR2 GameBoard::ChangeScreenToTable(VECTOR2 pos)
{
	return (pos - drawLT) / BOARD_SIZE;		// スクリーンサイズからテーブルサイズに変換
}

VECTOR2 GameBoard::ChangeTableToScreen(VECTOR2 pos)
{
	return (pos * BOARD_SIZE) + drawLT;		// テーブルサイズからスクリーンサイズに変換
}

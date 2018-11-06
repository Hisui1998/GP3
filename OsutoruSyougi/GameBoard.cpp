#include "DxLib.h"
#include "GameBoard.h"
#include "GameTask.h"

#define BOARD_CNT (9)
#define BOARD_SIZE (64)

GameBolad::GameBolad()
{
	ReSize(VECTOR2(BOARD_CNT, BOARD_CNT));
}

GameBolad::GameBolad(VECTOR2 vec)
{
	ReSize(vec);
}


GameBolad::~GameBolad()
{
}

void GameBolad::Update(void)
{
}

void GameBolad::Draw(void)
{
	DrawBox(drawLT.x, drawLT.y, screenSize.x - drawLT.x, screenSize.y - drawLT.y, 0xE6BC8D, true);
}

void GameBolad::ReSize(VECTOR2 vec)
{
	screenSize = lpGameTask.GetScreenSize();	// スクリーンサイズ
	boardSize = vec * BOARD_SIZE;				// ボードサイズ
	drawLT = (screenSize - boardSize) / 2;		// 左端のオフセットサイズ
}

VECTOR2 GameBolad::ChangeScreenToTable(VECTOR2 pos)
{
	return (pos - drawLT) / BOARD_SIZE;		// スクリーンサイズからテーブルサイズに変換
}

VECTOR2 GameBolad::ChangeTableToScreen(VECTOR2 pos)
{
	return (pos * BOARD_SIZE) + drawLT;		// テーブルサイズからスクリーンサイズに変換
}

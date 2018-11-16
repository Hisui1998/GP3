#pragma once
#include <memory>
#include <list>
#include "VECTOR2.h"
class GamePiece;
class GameBoard;

class PieceTray
{
public:
	PieceTray(int playerCnt);
	~PieceTray();
	void Draw();
	std::shared_ptr<GamePiece> GetPiece(VECTOR2 pos);
private:
	std::shared_ptr<GamePiece> piece;
	std::list<std::shared_ptr<GamePiece>> pieceList;
};

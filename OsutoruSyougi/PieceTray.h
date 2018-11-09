#pragma once
#include <memory>
#include <list>
class GamePiece;
class PieceTray
{
public:
	PieceTray();
	~PieceTray();
	void Draw();
private:
	std::shared_ptr<GamePiece> piece;
	std::list<std::shared_ptr<GamePiece>> pieceList;
};


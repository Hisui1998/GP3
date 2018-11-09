#include "PieceTray.h"

#include "PiecePawn.h"
#include "PieceKing.h"
#include "PieceRook.h"
#include "PieceBishop.h"
#include "PieceSilver.h"
#include "PieceLancer.h"
#include "PieceGold.h"


PieceTray::PieceTray()
{
	pieceList.push_back(std::make_unique<PieceLancer>());
	pieceList.push_back(std::make_unique<PieceBishop>());
	pieceList.push_back(std::make_unique<PieceSilver>());
	pieceList.push_back(std::make_unique<PieceGold>());
	pieceList.push_back(std::make_unique<PieceKing>());
	pieceList.push_back(std::make_unique<PieceGold>());
	pieceList.push_back(std::make_unique<PieceSilver>());
	pieceList.push_back(std::make_unique<PieceLancer>());
	pieceList.push_back(std::make_unique<PieceRook>());
	pieceList.push_back(std::make_unique<PiecePawn>());
	pieceList.push_back(std::make_unique<PiecePawn>());
	pieceList.push_back(std::make_unique<PiecePawn>());

	auto itr = pieceList.begin();
	for (int i = 0; i<pieceList.size() - 3; i++)
	{
		(*itr)->SetPos(VECTOR2(i, 7));
		itr++;
	}
}


PieceTray::~PieceTray()
{
}

void PieceTray::Draw()
{
	for (auto Piece : pieceList)
	{
		Piece->Draw();
	}
}

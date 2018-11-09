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
	for (unsigned int i = 0; i<pieceList.size() - 3; i++)
	{
		(*itr)->SetPos(VECTOR2(i, 7), VECTOR2((SCR_SIZR_X / 2) - (PIECE_SIZE / 2) * 9, (SCR_SIZR_Y / 2) - (PIECE_SIZE / 2) * 9 ));
		itr++;
	}
	for (unsigned int i = 0; i< 3; i++)
	{
		(*itr)->SetPos(VECTOR2(i, 0));
		itr++;
	}
}


PieceTray::~PieceTray()
{
}

void PieceTray::Draw()
{
	DrawBox(SCR_SIZR_X - (PIECE_SIZE / 2), SCR_SIZR_Y - (PIECE_SIZE / 2),SCR_SIZR_X - (PIECE_SIZE / 2) - 192, SCR_SIZR_Y - (PIECE_SIZE / 2) - 192, 0xeeaa77, true);
	for (auto Piece : pieceList)
	{
		Piece->Draw();
	}
}

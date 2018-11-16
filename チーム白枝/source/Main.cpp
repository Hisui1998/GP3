#include <Dxlib.h>
#include "MouseCtl.h"
#include <memory>
#include <string>
#include "GameTask.h"
#include "Player.h"
#include "PieceHole.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	lpGameTask.Run();
	//	DrawString(0,  0, ("PosX" + std::to_string(MC->GetMousePos().x)).c_str(), 0xffffff);
	//	DrawString(0, 15, ("PosY" + std::to_string(MC->GetMousePos().y)).c_str(), 0xffffff);
	//	DrawBox(540 - 32 * 9, 360 - 32 * 9, 540 + 32 * 9, 360 + 32 * 9, 0xeeaa77, true);
	//	DrawBox(32, 32, 32 + 180, 32 + 180, 0xeeaa77, true);
	DxLib_End();	// DxLibÇÃèIóπ
	return 0;
}
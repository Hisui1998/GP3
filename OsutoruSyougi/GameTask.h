#pragma once
#include <mutex>
#include <memory>
#include <list>
#include "GameBoard.h"
#include "MouseCtl.h"
#include "BaseScene.h"

#define lpGameTask GameTask::GetInstance()

class GameTask
{
public:
	void Run(void);
	static GameTask &GetInstance(void)
	{
		return *s_Instance;
	}
	VECTOR2 GetScreenSize(void);
private:
	struct GameTaskDeleter
	{
		void operator()(GameTask* gameTask) const
		{
			delete gameTask;
		}
	};
	static std::unique_ptr<GameTask, GameTaskDeleter> s_Instance;
	GameTask();
	~GameTask();
	int SysInit(void);

	int (GameTask::*GTskPtr)(void);
	std::unique_ptr<MouseCtl> mouseCtl;

	unique_Base activSceen;
};


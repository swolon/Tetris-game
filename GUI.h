#pragma once

#include "GameDefine.h"

//Graphic User Interface
class GUI
{
public:
	//启动界面
	void GameStartUI();
	//游戏界面
	void TetrisUI(int **board,int score);
	//启动界面-设置界面
	void GameSettingUI();
	//启动界面-设置界面-游戏难度
	void GameSettingUI_Difficulty();
	//启动界面-设置界面-键位设置
	void GameSettingUI_Key_Mapping();
private:
};
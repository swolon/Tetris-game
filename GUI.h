#pragma once

#include "GameDefine.h"

//Graphic User Interface
class GUI
{
public:
	//��������
	void GameStartUI();
	//��Ϸ����
	void TetrisUI(int **board,int score);
	//��������-���ý���
	void GameSettingUI();
	//��������-���ý���-��Ϸ�Ѷ�
	void GameSettingUI_Difficulty();
	//��������-���ý���-��λ����
	void GameSettingUI_Key_Mapping();
private:
};
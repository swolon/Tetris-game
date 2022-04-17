#include "GUI.h"
#include <iostream>

using namespace std;

void GUI::GameStartUI()
{
	cout << "****************************************" << endl;
	cout << "             " << "����˹����" << "          " << endl;
	cout << "             " << "1.��ʼ��Ϸ" << endl;
	cout << "             " << "2.����" << endl;
	cout << "             " << "3.�˳���Ϸ" << endl;
	cout << "****************************************" << endl;
}

void GUI::TetrisUI(int** board, int score)
{
	cout << "Tetris Game -------- Your Score:" << score << endl;
	for (int row = 0; row < GAME_ROW; row++)
	{
		for (int col = 0; col < GAME_COL; col++)
		{
			switch (board[row][col])
			{
			case GAMEBORDER:cout << BORDERSYMBLE; break;
			case GAMEBLOCK:cout << BLOCKSYMBLE; break;
			case GAMEEMPTY:cout << EMPTYSYMBLE; break;
			}
		}
		cout << endl;
	}
}

void GUI::GameSettingUI()
{
	cout << "****************************************" << endl;
	cout << "             " << "��Ϸ����" << endl;
	cout << "             " << "1.�Ѷ�����" << endl;
	cout << "             " << "2.��λ����" << endl;
	cout << "             " << "3.����" << endl;
	cout << "****************************************" << endl;
}

void GUI::GameSettingUI_Difficulty()
{
	cout << "****************************************" << endl;
	cout << "             " << "1.�Ѷ�����" << endl;
	cout << "        " << "�ɵ��Ѷ�(1-10)" << endl;
	cout << "        " << "����������������Ѷ�" << endl;
	cout << "             " << "0.����" << endl;
	cout << "****************************************" << endl;
}

void GUI::GameSettingUI_Key_Mapping()
{
	cout << "****************************************" << endl;
	cout << "             " << "2.��λ����" << endl;
	cout << "        " << "1).����WASD��λ" << endl;
	cout << "        " << "2).С���̼�ͷ��λ" << endl;
	cout << "             " << "3.����" << endl;
	cout << "****************************************" << endl;
}


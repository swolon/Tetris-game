#include "GUI.h"
#include <iostream>

using namespace std;

void GUI::GameStartUI()
{
	cout << "****************************************" << endl;
	cout << "             " << "俄罗斯方块" << "          " << endl;
	cout << "             " << "1.开始游戏" << endl;
	cout << "             " << "2.设置" << endl;
	cout << "             " << "3.退出游戏" << endl;
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
	cout << "             " << "游戏设置" << endl;
	cout << "             " << "1.难度设置" << endl;
	cout << "             " << "2.键位设置" << endl;
	cout << "             " << "3.返回" << endl;
	cout << "****************************************" << endl;
}

void GUI::GameSettingUI_Difficulty()
{
	cout << "****************************************" << endl;
	cout << "             " << "1.难度设置" << endl;
	cout << "        " << "可调难度(1-10)" << endl;
	cout << "        " << "请输入你想游玩的难度" << endl;
	cout << "             " << "0.返回" << endl;
	cout << "****************************************" << endl;
}

void GUI::GameSettingUI_Key_Mapping()
{
	cout << "****************************************" << endl;
	cout << "             " << "2.键位设置" << endl;
	cout << "        " << "1).经典WASD键位" << endl;
	cout << "        " << "2).小键盘箭头键位" << endl;
	cout << "             " << "3.返回" << endl;
	cout << "****************************************" << endl;
}


#ifndef GAME_H
#define GAME_H
#include "GameBoard.h"    //后台数据 
#include "GUI.h"		  //前台界面 

class Game
{
private:
	GameBoard *gameBoard;     //后台数据
	GUI *gameUI;			  //前台UI 
	Group *pGroup;			  //方块 
	int score;				  //得分
	int KeyMapping;
	int Difficulty;
public:
	Game();						//构造函数 
	~Game();					//析构函数 
	void gameStart();			//游戏开始界面后台
	void gameSettingUI();		//游戏设置界面后台
	void gameSettingUI_Difficulty();		//游戏设置界面 难度 后台
	void gameSettingUI_Key_Mapping();		//游戏设置界面 键位 后台
	void KeyPressing_WASD(char);
	void KeyPressing_Arrow(char);
	void gameTetris();			//游戏操作界面后台
	void gameEnd();				//游戏结束
	void createGroup();			//随机产生Block 
	void insertIntoBoard();		//该方块到底，不能在移动。 
	void gameSummary();			//停止游戏后总结积分
	void SetColor(int color_num);		//设置颜色
};

#endif

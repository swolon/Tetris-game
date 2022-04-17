#include "Game.h"

#include "GroupL.h"
#include "GroupLine.h"
#include "GroupT.h"
#include "GroupWell.h"
#include "GroupZ.h"
#include "GroupRevZ.h"
#include "GroupRevL.h"

#include<iostream>
#include<stdlib.h>  //调用windows清屏命令 
#include<conio.h>	//捕捉按键中断 
#include<cstdlib>	//随机数函数 
#include<time.h>	//time()时间戳函数 
#include<windows.h> //延时函数 
#include<string>

using namespace std;

Game::Game()
{
	this->gameBoard = new GameBoard();
	this->gameUI = new GUI(); 
	score = 0;					//初始化为0分

	//构造默认按键映射
	KeyMapping = 1;

	//构造默认难度
	Difficulty = 1000;
}

Game::~Game()
{
	delete this->gameBoard;		//释放空间 
	delete this->gameUI;		//释放空间 
}

/*
		gameStart
		用户开始游戏菜单界面

		+停止游戏后结算界面
*/
void Game::gameStart() 
{
	int key = 0;
	while (key != 3)
	{
		system("cls");					//清屏命令 
		this->gameUI->GameStartUI();	//显示启动页面
		cin >> key;						//获取键盘输入 
		switch(key)
		{
			case 1:
				this->gameTetris();	 	//进入俄罗斯方块游戏
				this->gameSummary();	//结算界面
				break;
			case 2:
				this->gameSettingUI();
				break;
			case 3:
				exit(0);				//退出程序，0--代表正常退出 
				break;
			default:  
				break;
		};
	}
}

void Game::gameSettingUI()
{
	int key = 0;
	while (key != 3)
	{
		system("cls");					//清屏命令 
		this->gameUI->GameSettingUI();	//显示启动页面
		cin >> key;						//获取键盘输入 
		switch (key)
		{
		case 1:
			this->gameSettingUI_Difficulty();
			break;
		case 2:
			this->gameSettingUI_Key_Mapping();
			break;
		case 3:
			break;
		default:
			break;
		};
	}
}

void Game::gameSettingUI_Difficulty()
{
	int key = 11;
	while (key != 0)
	{
		system("cls");					//清屏命令 
		this->gameUI->GameSettingUI_Difficulty();	//显示启动页面
		cin >> key;						//获取键盘输入 
		switch (key)
		{
		case 0:							//返回上一级菜单
			break;
		case 1:Difficulty = 1000; break;
		case 2:Difficulty = 900; break;
		case 3:Difficulty = 800; break;
		case 4:Difficulty = 700; break;
		case 5:Difficulty = 600; break;
		case 6:Difficulty = 500; break;
		case 7:Difficulty = 400; break;
		case 8:Difficulty = 300; break;
		case 9:Difficulty = 200; break;
		case 10:Difficulty = 100; break;
		default:
			break;
		};
	}
}

void Game::gameSettingUI_Key_Mapping()
{
	int key = 0;
	while (key != 3)
	{
		system("cls");					//清屏命令 
		this->gameUI->GameSettingUI_Key_Mapping();	//显示启动页面
		cin >> key;						//获取键盘输入 
		switch (key)
		{
		case 1:KeyMapping = 1; break;
		case 2:KeyMapping = 2; break;
		case 3:
			break;
		default:
			break;
		};
	}
}

void Game::KeyPressing_WASD(char key)
{
	switch (key)
	{
	case 'w':						//字符'w'，功能翻转 
		if (!pGroup->GetStatus())
		{
			pGroup->Rotate();
			if (!gameBoard->determine(pGroup))  //如果判断不可以旋转，就还原。 
				pGroup->RotateBack();
		}
		break;
	case 's':						//字符's'：向下加速 
		insertIntoBoard();
		break;
	case 'a':						//字符'a': 向左移动 
		if (!pGroup->GetStatus())
		{
			pGroup->MoveLeft();
			if (!gameBoard->determine(pGroup))  //如果判断不可以左移，就还原。 
				pGroup->MoveRight();
		}
		break;
	case 'd':						//字符'd': 向右移动
		if (!pGroup->GetStatus())
		{
			pGroup->MoveRight();
			if (!gameBoard->determine(pGroup))  //如果判断不可以右移，就还原。 
				pGroup->MoveLeft();
		}
		break;
	default:
		insertIntoBoard();
		break;
	}
}

void Game::KeyPressing_Arrow(char key)
{
	switch (key)
	{
	case 72:						//字符'w'，功能翻转 
		if (!pGroup->GetStatus())
		{
			pGroup->Rotate();
			if (!gameBoard->determine(pGroup))  //如果判断不可以旋转，就还原。 
				pGroup->RotateBack();
		}
		break;
	case 80:						//字符's'：向下加速 
		insertIntoBoard();
		break;
	case 75:						//字符'a': 向左移动 
		if (!pGroup->GetStatus())
		{
			pGroup->MoveLeft();
			if (!gameBoard->determine(pGroup))  //如果判断不可以左移，就还原。 
				pGroup->MoveRight();
		}
		break;
	case 77:						//字符'd': 向右移动
		if (!pGroup->GetStatus())
		{
			pGroup->MoveRight();
			if (!gameBoard->determine(pGroup))  //如果判断不可以右移，就还原。 
				pGroup->MoveLeft();
		}
		break;
	default:
		insertIntoBoard();
		break;
	}
}



/*
		gameEnd
		游戏结束
*/
void Game::gameEnd()
{
	this->gameSummary();
	system("pause");
}

/*
		gameTetris
		用户操作核心，用于定义玩家按键
		
		+添加敲击ESC退出游戏的按键
*/
void Game::gameTetris()
{
	char key=0;
	createGroup();
	system("cls");
	
	while (key != 27)
	{ 
		gameBoard->combineGroup(pGroup);

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});//相当于清屏命令，避免闪屏 
		gameUI->TetrisUI(gameBoard->getBoard(), score);//显示俄罗斯方块游戏UI  
		gameBoard->removeGroup(pGroup);			//删除之前的一行 
		insertIntoBoard();						//自动下落一行

		fflush(stdin);
		if (_kbhit())							//判断按键是否按下 
		{
			key = _getch();						//获取按键输入 
			switch (KeyMapping)
			{
			case 1:
				KeyPressing_WASD(key);
				break;
			case 2:
				KeyPressing_Arrow(key);
				break;
			}
		} else {
			Sleep(Difficulty);								//延时1000ms
		}
	}
}

/*
		createGroup
		设置可以产生的方块
		- L型方块
		- 长条方块
		- T型方块
		- 田型方块
		- 倒L型方块
		- Z型方块
		- 倒Z型方块
*/
void Game::createGroup()
{
	/*
		随机数种子
		使用时间戳作为随机数种子
		设置随机数种子
	*/
    srand(time(0));
	unsigned blockRand = rand() % BLOCKNUMBER + 1;			//产生随机数 
	switch(blockRand)
	{
		case 1:
			pGroup = new L;				//L型方块
			this->SetColor(0);
			break;
		case 2:
			pGroup = new Line();		//长条型方块
			this->SetColor(1);
			break;
		case 3:
			pGroup = new T();			//T型方块
			this->SetColor(2);
			break;
		case 4:
			pGroup = new Well();		//田字形方块
			this->SetColor(3);
			break;
		case 5:
			pGroup = new RevL();		//倒L型方块
			this->SetColor(4);
			break;
		case 6:
			pGroup = new Z();			//Z型方块
			this->SetColor(0);
			break;
		case 7:
			pGroup = new RevZ();		//倒Z型方块
			this->SetColor(1);
			break;
		default:
			break;
	}
}

/*
		insertIntoBoard
		向游戏板中插入块
*/
void Game::insertIntoBoard()
{
	pGroup->MoveDown();							//方块下落 
	if(!gameBoard->determine(pGroup))			//如果判断不可以下落，就产生新的Block。 
	{
		pGroup->MoveUp();						//方块上升回去 
		gameBoard->combineGroup(pGroup);		//把方块并入board 
		score += gameBoard->removeRow() * 100;	//判断是否消行 
		createGroup();							//创建新的方块 
	}
}

/*
		gameSummary
		停止游戏后结算积分界面
*/
void Game::gameSummary()
{
	system("cls");
	cout << "========================================" << endl;
	cout << "          Your Score is " << score << endl;
	cout << "          为何不再来一把呢？" << endl;
	cout << "========================================" << endl;
	system("pause");
}

/*
		SetColor
		设置控制台文本颜色
*/
void Game::SetColor(int color_num)			//设置颜色
{
	int n = 0;
	switch (color_num)
	{
	case 0: n = 0x08; break;
	case 1: n = 0x0C; break;
	case 2: n = 0x0D; break;
	case 3: n = 0x0E; break;
	case 4: n = 0x0A; break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
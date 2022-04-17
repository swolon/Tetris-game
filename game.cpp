#include "Game.h"

#include "GroupL.h"
#include "GroupLine.h"
#include "GroupT.h"
#include "GroupWell.h"
#include "GroupZ.h"
#include "GroupRevZ.h"
#include "GroupRevL.h"

#include<iostream>
#include<stdlib.h>  //����windows�������� 
#include<conio.h>	//��׽�����ж� 
#include<cstdlib>	//��������� 
#include<time.h>	//time()ʱ������� 
#include<windows.h> //��ʱ���� 
#include<string>

using namespace std;

Game::Game()
{
	this->gameBoard = new GameBoard();
	this->gameUI = new GUI(); 
	score = 0;					//��ʼ��Ϊ0��

	//����Ĭ�ϰ���ӳ��
	KeyMapping = 1;

	//����Ĭ���Ѷ�
	Difficulty = 1000;
}

Game::~Game()
{
	delete this->gameBoard;		//�ͷſռ� 
	delete this->gameUI;		//�ͷſռ� 
}

/*
		gameStart
		�û���ʼ��Ϸ�˵�����

		+ֹͣ��Ϸ��������
*/
void Game::gameStart() 
{
	int key = 0;
	while (key != 3)
	{
		system("cls");					//�������� 
		this->gameUI->GameStartUI();	//��ʾ����ҳ��
		cin >> key;						//��ȡ�������� 
		switch(key)
		{
			case 1:
				this->gameTetris();	 	//�������˹������Ϸ
				this->gameSummary();	//�������
				break;
			case 2:
				this->gameSettingUI();
				break;
			case 3:
				exit(0);				//�˳�����0--���������˳� 
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
		system("cls");					//�������� 
		this->gameUI->GameSettingUI();	//��ʾ����ҳ��
		cin >> key;						//��ȡ�������� 
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
		system("cls");					//�������� 
		this->gameUI->GameSettingUI_Difficulty();	//��ʾ����ҳ��
		cin >> key;						//��ȡ�������� 
		switch (key)
		{
		case 0:							//������һ���˵�
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
		system("cls");					//�������� 
		this->gameUI->GameSettingUI_Key_Mapping();	//��ʾ����ҳ��
		cin >> key;						//��ȡ�������� 
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
	case 'w':						//�ַ�'w'�����ܷ�ת 
		if (!pGroup->GetStatus())
		{
			pGroup->Rotate();
			if (!gameBoard->determine(pGroup))  //����жϲ�������ת���ͻ�ԭ�� 
				pGroup->RotateBack();
		}
		break;
	case 's':						//�ַ�'s'�����¼��� 
		insertIntoBoard();
		break;
	case 'a':						//�ַ�'a': �����ƶ� 
		if (!pGroup->GetStatus())
		{
			pGroup->MoveLeft();
			if (!gameBoard->determine(pGroup))  //����жϲ��������ƣ��ͻ�ԭ�� 
				pGroup->MoveRight();
		}
		break;
	case 'd':						//�ַ�'d': �����ƶ�
		if (!pGroup->GetStatus())
		{
			pGroup->MoveRight();
			if (!gameBoard->determine(pGroup))  //����жϲ��������ƣ��ͻ�ԭ�� 
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
	case 72:						//�ַ�'w'�����ܷ�ת 
		if (!pGroup->GetStatus())
		{
			pGroup->Rotate();
			if (!gameBoard->determine(pGroup))  //����жϲ�������ת���ͻ�ԭ�� 
				pGroup->RotateBack();
		}
		break;
	case 80:						//�ַ�'s'�����¼��� 
		insertIntoBoard();
		break;
	case 75:						//�ַ�'a': �����ƶ� 
		if (!pGroup->GetStatus())
		{
			pGroup->MoveLeft();
			if (!gameBoard->determine(pGroup))  //����жϲ��������ƣ��ͻ�ԭ�� 
				pGroup->MoveRight();
		}
		break;
	case 77:						//�ַ�'d': �����ƶ�
		if (!pGroup->GetStatus())
		{
			pGroup->MoveRight();
			if (!gameBoard->determine(pGroup))  //����жϲ��������ƣ��ͻ�ԭ�� 
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
		��Ϸ����
*/
void Game::gameEnd()
{
	this->gameSummary();
	system("pause");
}

/*
		gameTetris
		�û��������ģ����ڶ�����Ұ���
		
		+����û�ESC�˳���Ϸ�İ���
*/
void Game::gameTetris()
{
	char key=0;
	createGroup();
	system("cls");
	
	while (key != 27)
	{ 
		gameBoard->combineGroup(pGroup);

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});//�൱����������������� 
		gameUI->TetrisUI(gameBoard->getBoard(), score);//��ʾ����˹������ϷUI  
		gameBoard->removeGroup(pGroup);			//ɾ��֮ǰ��һ�� 
		insertIntoBoard();						//�Զ�����һ��

		fflush(stdin);
		if (_kbhit())							//�жϰ����Ƿ��� 
		{
			key = _getch();						//��ȡ�������� 
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
			Sleep(Difficulty);								//��ʱ1000ms
		}
	}
}

/*
		createGroup
		���ÿ��Բ����ķ���
		- L�ͷ���
		- ��������
		- T�ͷ���
		- ���ͷ���
		- ��L�ͷ���
		- Z�ͷ���
		- ��Z�ͷ���
*/
void Game::createGroup()
{
	/*
		���������
		ʹ��ʱ�����Ϊ���������
		�������������
	*/
    srand(time(0));
	unsigned blockRand = rand() % BLOCKNUMBER + 1;			//��������� 
	switch(blockRand)
	{
		case 1:
			pGroup = new L;				//L�ͷ���
			this->SetColor(0);
			break;
		case 2:
			pGroup = new Line();		//�����ͷ���
			this->SetColor(1);
			break;
		case 3:
			pGroup = new T();			//T�ͷ���
			this->SetColor(2);
			break;
		case 4:
			pGroup = new Well();		//�����η���
			this->SetColor(3);
			break;
		case 5:
			pGroup = new RevL();		//��L�ͷ���
			this->SetColor(4);
			break;
		case 6:
			pGroup = new Z();			//Z�ͷ���
			this->SetColor(0);
			break;
		case 7:
			pGroup = new RevZ();		//��Z�ͷ���
			this->SetColor(1);
			break;
		default:
			break;
	}
}

/*
		insertIntoBoard
		����Ϸ���в����
*/
void Game::insertIntoBoard()
{
	pGroup->MoveDown();							//�������� 
	if(!gameBoard->determine(pGroup))			//����жϲ��������䣬�Ͳ����µ�Block�� 
	{
		pGroup->MoveUp();						//����������ȥ 
		gameBoard->combineGroup(pGroup);		//�ѷ��鲢��board 
		score += gameBoard->removeRow() * 100;	//�ж��Ƿ����� 
		createGroup();							//�����µķ��� 
	}
}

/*
		gameSummary
		ֹͣ��Ϸ�������ֽ���
*/
void Game::gameSummary()
{
	system("cls");
	cout << "========================================" << endl;
	cout << "          Your Score is " << score << endl;
	cout << "          Ϊ�β�����һ���أ�" << endl;
	cout << "========================================" << endl;
	system("pause");
}

/*
		SetColor
		���ÿ���̨�ı���ɫ
*/
void Game::SetColor(int color_num)			//������ɫ
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
#ifndef GAME_H
#define GAME_H
#include "GameBoard.h"    //��̨���� 
#include "GUI.h"		  //ǰ̨���� 

class Game
{
private:
	GameBoard *gameBoard;     //��̨����
	GUI *gameUI;			  //ǰ̨UI 
	Group *pGroup;			  //���� 
	int score;				  //�÷�
	int KeyMapping;
	int Difficulty;
public:
	Game();						//���캯�� 
	~Game();					//�������� 
	void gameStart();			//��Ϸ��ʼ�����̨
	void gameSettingUI();		//��Ϸ���ý����̨
	void gameSettingUI_Difficulty();		//��Ϸ���ý��� �Ѷ� ��̨
	void gameSettingUI_Key_Mapping();		//��Ϸ���ý��� ��λ ��̨
	void KeyPressing_WASD(char);
	void KeyPressing_Arrow(char);
	void gameTetris();			//��Ϸ���������̨
	void gameEnd();				//��Ϸ����
	void createGroup();			//�������Block 
	void insertIntoBoard();		//�÷��鵽�ף��������ƶ��� 
	void gameSummary();			//ֹͣ��Ϸ���ܽ����
	void SetColor(int color_num);		//������ɫ
};

#endif

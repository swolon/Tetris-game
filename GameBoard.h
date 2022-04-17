#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "GameDefine.h"
#include "Group.h"

class GameBoard
{
private:
	int **board;     	//��Ϸ���̶�Ӧ�Ķ�ά����

public:
	GameBoard();					//���캯�������ά�����ʼֵΪ0��
									//0-�����λΪ�գ�1-�����λΪ������ 
	int removeRow();                 //���к���������ֵΪ��ȥ��������
	void downRow(int row);			//0-��row-1���п�ʼ����������һ�� 
	int** getBoard();				//��ȡBoard 
	void combineGroup(Group * group); //�ѷ��������Ϸ������
	void removeGroup(Group *group);	  //�ѷ������Ϸ������ɾ��
	bool determine(Group *group);	  //�жϷ����Ƿ�����ƶ� true-���ԣ�false-������ 
};

#endif

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "GameDefine.h"
#include "Group.h"

class GameBoard
{
private:
	int **board;     	//游戏棋盘对应的二维矩阵

public:
	GameBoard();					//构造函数，令二维矩阵初始值为0；
									//0-代表该位为空，1-代表该位为有棋子 
	int removeRow();                 //消行函数，返回值为消去的行数；
	void downRow(int row);			//0-（row-1）行开始，整体下落一行 
	int** getBoard();				//获取Board 
	void combineGroup(Group * group); //把方块放入游戏矩阵中
	void removeGroup(Group *group);	  //把方块从游戏矩阵中删除
	bool determine(Group *group);	  //判断方块是否可以移动 true-可以，false-不可以 
};

#endif

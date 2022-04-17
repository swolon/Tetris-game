#include "GameBoard.h"

GameBoard::GameBoard()
{
	// ��ʼ������ 
	this->board = new int*[GAME_ROW];
	
	for(int row=0; row<GAME_ROW; row++)
	{
		this->board[row] = new int[GAME_COL];
		
		for(int col=0; col<GAME_COL; col++) 
		{
			if(row == 0 || row == GAME_ROW-1 || col == 0 || col == GAME_COL-1)
			{
				board[row][col] = GAMEBORDER;
			}else {
				board[row][col] = GAMEEMPTY;
			}
		}
	}
}

int GameBoard::removeRow()
{
	int rowCount = 0;							//����������������ʼֵΪ0
	bool flag = true;							//��־λ������ÿһ���Ƿ���Ա���ȥ��
	 
	for(int row=GAME_ROW-2; row>0; row--)
	{ 
		flag = true;
		for(int col=1; col<GAME_COL-1; col++)
		{
			if(board[row][col] == GAMEEMPTY)
			{
				flag = false; 
				break;
			} 
		}
		if(flag) { 
			downRow(row);						//��ȥrow�У�
			row++;								//���¼��row�У� 
			rowCount++;
		} 
	}
	
	return rowCount;
}

void GameBoard::downRow(int row)
{
	for(int r=row; r>0; r--)
		for(int col=1; col<GAME_COL-1; col++) 
			board[r][col] = board[r-1][col];
	for(int col=1; col<GAME_COL-1; col++)
		board[1][col] = GAMEEMPTY;                            //������0 
}

int ** GameBoard::getBoard()
{
	return board;
}

void GameBoard::combineGroup(Group *group)
{
	int row;
	int col;
	
	for(int i=0; i<4; i++)
	{
		row = (group->GetBlock())[i].GetRow();
		col = (group->GetBlock())[i].GetCol();
		
		if(row>-1 && row<GAME_ROW && col>-1 && col<GAME_COL)
			board[row][col]=GAMEBLOCK;
	}	
} 

void GameBoard::removeGroup(Group *group)
{
	int row;
	int col;
	
	for(int i=0; i<4; i++)
	{
		row = (group->GetBlock())[i].GetRow();
		col = (group->GetBlock())[i].GetCol();
		
		if(row>-1 && row<GAME_ROW && col>-1 && col<GAME_COL)
			if(row == 0)
				board[row][col]=GAMEBORDER;
			else
				board[row][col]=GAMEEMPTY;
	}
}

bool GameBoard::determine(Group *group)
{
	int row;
	int col;
	
	for(int i=0; i<4; i++)
	{
		row = (group->GetBlock())[i].GetRow();
		col = (group->GetBlock())[i].GetCol();
		
		if(row>-1 && row<GAME_ROW && col>-1 && col<GAME_COL)
		{
			if(board[row][col] != GAMEEMPTY && row!=0)
				return false;
		}
	}
	return true;
} 
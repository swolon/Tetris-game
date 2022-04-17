#include "GroupRevL.h"
#include "GameDefine.h"
#include <time.h>
#include <cstdlib>

RevL::RevL()
{
	srand(time(0));
	unsigned int BlockRand = rand() % 4;
	switch (BlockRand)
	{
	case 0:
	{
		block[0].SetRow(0); block[0].SetCol(GAME_COL / 2 + 1);
		block[1].SetRow(-1); block[1].SetCol(GAME_COL / 2 + 1);
		block[2].SetRow(0); block[2].SetCol(GAME_COL / 2 - 1);
		block[3].SetRow(0); block[3].SetCol(GAME_COL / 2);
		Pattern = 0;
		break;
	}
	case 1:
	{
		block[0].SetRow(0); block[0].SetCol(GAME_COL / 2);
		block[1].SetRow(-1); block[1].SetCol(GAME_COL / 2);
		block[2].SetRow(-2); block[2].SetCol(GAME_COL / 2);
		block[3].SetRow(0); block[3].SetCol(GAME_COL / 2 + 1);
		Pattern = 1;
		break;
	}
	case 2:
	{
		block[0].SetRow(0); block[0].SetCol(GAME_COL / 2 - 1);
		block[1].SetRow(-1); block[1].SetCol(GAME_COL / 2 - 1);
		block[2].SetRow(-1); block[2].SetCol(GAME_COL / 2);
		block[3].SetRow(-1); block[3].SetCol(GAME_COL / 2 + 1);
		Pattern = 2;
		break;
	}
	case 3:
	{
		block[0].SetRow(0); block[0].SetCol(GAME_COL / 2 + 1);
		block[1].SetRow(-1); block[1].SetCol(GAME_COL / 2 + 1);
		block[2].SetRow(-2); block[2].SetCol(GAME_COL / 2 + 1);
		block[3].SetRow(-2); block[3].SetCol(GAME_COL / 2);
		Pattern = 3;
		break;
	}
	}
}

void RevL::Rotate()
{
	switch (Pattern)
	{
	case 0:
	{
		block[2].SetRow(block[1].GetRow() - 1);
		block[2].SetCol(block[1].GetCol());
		block[3].SetRow(block[0].GetRow());
		block[3].SetCol(block[0].GetCol() + 1);
		Pattern = 1;
		break;
	}
	case 1:
	{
		block[2].SetRow(block[1].GetRow());
		block[2].SetCol(block[1].GetCol() + 1);
		block[3].SetRow(block[1].GetRow());
		block[3].SetCol(block[1].GetCol() + 2);
		Pattern = 2;
		break;
	}
	case 2:
	{
		block[2].SetRow(block[1].GetRow() - 1);
		block[2].SetCol(block[1].GetCol());
		block[3].SetRow(block[1].GetRow() - 1);
		block[3].SetCol(block[1].GetCol() - 1);
		Pattern = 3;
		break;
	}
	case 3:
	{
		block[2].SetRow(block[0].GetRow());
		block[2].SetCol(block[0].GetCol() - 2);
		block[3].SetRow(block[0].GetRow());
		block[3].SetCol(block[0].GetCol() - 1);
		Pattern = 0;
		break;
	}
	}
}

void RevL::RotateBack()
{
	switch (Pattern)
	{
	case 0:
	{
		block[2].SetRow(block[1].GetRow() - 1);
		block[2].SetCol(block[1].GetCol());
		block[3].SetRow(block[1].GetRow() - 1);
		block[3].SetCol(block[1].GetCol() - 1);
		Pattern = 3;
		break;
	}
	case 1:
	{
		block[2].SetRow(block[0].GetRow());
		block[2].SetCol(block[0].GetCol() - 2);
		block[3].SetRow(block[0].GetRow());
		block[3].SetCol(block[0].GetCol() - 1);
		Pattern = 0;
		break;
	}
	case 2:
	{
		block[2].SetRow(block[1].GetRow() - 1);
		block[2].SetCol(block[1].GetCol());
		block[3].SetRow(block[0].GetRow());
		block[3].SetCol(block[0].GetCol() + 1);
		Pattern = 1;
		break;
	}
	case 3:
	{
		block[2].SetRow(block[1].GetRow());
		block[2].SetCol(block[1].GetCol() + 1);
		block[3].SetRow(block[1].GetRow());
		block[3].SetCol(block[1].GetCol() + 2);
		Pattern = 2;
		break;
	}
	}
}

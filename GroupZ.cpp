#include "GroupZ.h"
#include "GameDefine.h"
#include <time.h>
#include <cstdlib>

Z::Z()
{
	srand(time(0));
	unsigned int BlockRand = rand() % 2;
	switch (BlockRand)
	{
	case 0:
	{
		block[0].SetRow(-1); block[0].SetCol(GAME_COL / 2 - 1);
		block[1].SetRow(-1); block[1].SetCol(GAME_COL / 2);
		block[2].SetRow(0); block[2].SetCol(GAME_COL / 2);
		block[3].SetRow(0); block[3].SetCol(GAME_COL / 2 + 1);
		Pattern = 0;
		break;
	}
	case 1:
	{
		block[0].SetRow(-2); block[0].SetCol(GAME_COL / 2 + 1);
		block[1].SetRow(-1); block[1].SetCol(GAME_COL / 2);
		block[2].SetRow(0); block[2].SetCol(GAME_COL / 2);
		block[3].SetRow(-1); block[3].SetCol(GAME_COL / 2 + 1);
		Pattern = 1;
		break;
	}
	}
}

void Z::Rotate()
{
	switch (Pattern)
	{
	case 0:
	{
		block[0].SetRow(block[1].GetRow() - 1);
		block[0].SetCol(block[1].GetCol() + 1);
		block[3].SetRow(block[1].GetRow());
		block[3].SetCol(block[1].GetCol() + 1);
		Pattern = 1;
		break;
	}
	case 1:
	{
		block[0].SetRow(block[1].GetRow());
		block[0].SetCol(block[1].GetCol() - 1);
		block[3].SetRow(block[1].GetRow() + 1);
		block[3].SetCol(block[1].GetCol() + 1);
		Pattern = 0;
		break;
	}
	}
}

void Z::RotateBack()
{
	switch (Pattern)
	{
	case 0:
	{
		block[0].SetRow(block[1].GetRow() - 1);
		block[0].SetCol(block[1].GetCol() + 1);
		block[3].SetRow(block[1].GetRow());
		block[3].SetCol(block[1].GetCol() + 1);
		Pattern = 1;
		break;
	}
	case 1:
	{
		block[0].SetRow(block[1].GetRow());
		block[0].SetCol(block[1].GetCol() - 1);
		block[3].SetRow(block[1].GetRow() + 1);
		block[3].SetCol(block[1].GetCol() + 1);
		Pattern = 0;
		break;
	}
	}
}

#include "GroupLine.h"
#include "GameDefine.h"
#include <time.h>
#include <cstdlib>

Line::Line()
{
	srand(time(0));
	unsigned int BlockRand = rand() % 2;
	switch (BlockRand)
	{
	case 0:
	{
		block[0].SetRow(0); block[0].SetCol(GAME_COL / 2 - 2);
		block[1].SetRow(0); block[1].SetCol(GAME_COL / 2 - 1);
		block[2].SetRow(0); block[2].SetCol(GAME_COL / 2);
		block[3].SetRow(0); block[3].SetCol(GAME_COL / 2 + 1);
		Pattern = 0;			//∫·Ãı
		break;
	}
	case 1:
	{
		block[0].SetRow(0); block[0].SetCol(GAME_COL / 2);
		block[1].SetRow(-1); block[1].SetCol(GAME_COL / 2);
		block[2].SetRow(-2); block[2].SetCol(GAME_COL / 2);
		block[3].SetRow(-3); block[3].SetCol(GAME_COL / 2);
		Pattern = 1;			// ˙Ãı
		break;
	}
	}
}

void Line::Rotate()
{
	switch (Pattern)
	{
	case 0:
	{
		block[1].SetRow(block[0].GetRow() - 1);
		block[1].SetCol(block[0].GetCol());
		block[2].SetRow(block[0].GetRow() - 2);
		block[2].SetCol(block[0].GetCol());
		block[3].SetRow(block[0].GetRow() - 3);
		block[3].SetCol(block[0].GetCol());
		Pattern = 1;
		break;
	}
	case 1:
	{
		block[1].SetRow(block[0].GetRow());
		block[1].SetCol(block[0].GetCol() + 1);
		block[2].SetRow(block[0].GetRow());
		block[2].SetCol(block[0].GetCol() + 2);
		block[3].SetRow(block[0].GetRow());
		block[3].SetCol(block[0].GetCol() + 3);
		Pattern = 0;
		break;
	}
	}
}
void Line::RotateBack()
{
	switch (Pattern)
	{
	case 0:
	{
		block[1].SetRow(block[0].GetRow() - 1);
		block[1].SetCol(block[0].GetCol());
		block[2].SetRow(block[0].GetRow() - 2);
		block[2].SetCol(block[0].GetCol());
		block[3].SetRow(block[0].GetRow() - 3);
		block[3].SetCol(block[0].GetCol());
		Pattern = 1;
		break;
	}
	case 1:
	{
		block[1].SetRow(block[0].GetRow());
		block[1].SetCol(block[0].GetCol() + 1);
		block[2].SetRow(block[0].GetRow());
		block[2].SetCol(block[0].GetCol() + 2);
		block[3].SetRow(block[0].GetRow());
		block[3].SetCol(block[0].GetCol() + 3);
		Pattern = 0;
		break;
	}
	}
}
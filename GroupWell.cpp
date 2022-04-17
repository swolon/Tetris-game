#include "GroupWell.h"
#include "GameDefine.h"

Well::Well()
{
	block[0].SetRow(0);block[0].SetCol(GAME_COL / 2 - 1);
	block[1].SetRow(0);block[1].SetCol(GAME_COL / 2);
	block[2].SetRow(-1);block[2].SetCol(GAME_COL / 2 - 1);
	block[3].SetRow(-1);block[3].SetCol(GAME_COL / 2);
}

void Well::Rotate()
{
}

void Well::RotateBack()
{
}

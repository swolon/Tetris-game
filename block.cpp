#include"block.h"

Block::Block()
{
}

//Block 构造函数
Block::Block(int IniRow, int IniCol)
{
	col = IniCol;
	row = IniRow;
}

//设置行
void Block::SetRow(int SetRow)
{
	row = SetRow;
}

//设置列
void Block::SetCol(int SetCol)
{
	col = SetCol;
}

//获得行值
int Block::GetRow()
{
	return row;
}

//获得列值
int Block::GetCol()
{
	return col;
}

//移动方块
void Block::Move(int r, int c)
{
	row += r;
	col += c;
}

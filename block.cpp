#include"block.h"

Block::Block()
{
}

//Block ���캯��
Block::Block(int IniRow, int IniCol)
{
	col = IniCol;
	row = IniRow;
}

//������
void Block::SetRow(int SetRow)
{
	row = SetRow;
}

//������
void Block::SetCol(int SetCol)
{
	col = SetCol;
}

//�����ֵ
int Block::GetRow()
{
	return row;
}

//�����ֵ
int Block::GetCol()
{
	return col;
}

//�ƶ�����
void Block::Move(int r, int c)
{
	row += r;
	col += c;
}

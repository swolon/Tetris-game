#ifndef BLOCK_H
#define BLOCK_H

/*
	全部完成
*/

class Block
{
public:
	//默认构造
	Block();
	//有参构造
	Block(int IniRow, int IniCol);
	//设置行值
	void SetRow(int SetRow);
	//设置列值
	void SetCol(int SetCol);
	//获取行值
	int GetRow();
	//获取列支
	int GetCol();
	//移动
	void Move(int r, int c);
private:
	int col,row;			//行列值
};
#endif // !BLOCK_H
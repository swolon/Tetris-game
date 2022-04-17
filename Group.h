#ifndef GROUP_H
#define GROUP_H
#include "block.h"

/*
		全部完成
*/

class Group:public Block
{
public:
	//默认构造
	Group();

	//移动定义
	//左减右加，上减下加
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();

	//旋转，回滚旋转
	//交给派生类定义
	virtual void Rotate() = 0;
	virtual void RotateBack() = 0;

	//判断是否游戏结束
	bool GetStatus();

	//获得组数据
	virtual Block* GetBlock();
protected:
	//一组方块由四块基本方块组成
	Block block[4];
	//一组方块可以组成多种图形
	int Pattern;
};
#endif // !BLOCK_H


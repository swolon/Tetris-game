#ifndef WELL_H
#define WELL_H
#include "Group.h"

/*
	构造:1种 构造
	旋转:无需实现
	回滚:无需实现
*/

class Well:public Group
{
public:
	Well();
	void Rotate();
	void RotateBack();
};
#endif // !BLOCK_H
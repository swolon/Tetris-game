#pragma once
#include "Group.h"

/*
	构造:4种 随机构造
	旋转:4种
	回滚:全部实现
*/
	
class L:public Group
{
public:
	L();
	void Rotate();
	void RotateBack();
};
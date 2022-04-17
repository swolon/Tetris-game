#pragma once
#include "Group.h"

/*
	构造:4种 随机构造
	旋转:4种
	回滚:全部实现
*/

class T:public Group
{
public:
	T();
	void Rotate();
	void RotateBack();
};


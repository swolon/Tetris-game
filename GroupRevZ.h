#pragma once
#include "Group.h"

/*
	构造:2种 随机构造
	旋转:2种
	回滚:全部实现
*/

class RevZ:public Group
{
public:
	RevZ();
	void Rotate();
	void RotateBack();
};


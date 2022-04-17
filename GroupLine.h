#ifndef LINE_H
#define LINE_H
#include "Group.h"
#include "GameDefine.h"

/*
	构造:2种 随机构造
	旋转:2种
	回滚:全部实现
*/

class Line:public Group
{
public:
	Line();
	void Rotate();
	void RotateBack();
};
#endif // !LINE_H
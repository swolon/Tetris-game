#ifndef LINE_H
#define LINE_H
#include "Group.h"
#include "GameDefine.h"

/*
	����:2�� �������
	��ת:2��
	�ع�:ȫ��ʵ��
*/

class Line:public Group
{
public:
	Line();
	void Rotate();
	void RotateBack();
};
#endif // !LINE_H
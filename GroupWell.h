#ifndef WELL_H
#define WELL_H
#include "Group.h"

/*
	����:1�� ����
	��ת:����ʵ��
	�ع�:����ʵ��
*/

class Well:public Group
{
public:
	Well();
	void Rotate();
	void RotateBack();
};
#endif // !BLOCK_H
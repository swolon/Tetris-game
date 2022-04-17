#ifndef GROUP_H
#define GROUP_H
#include "block.h"

/*
		ȫ�����
*/

class Group:public Block
{
public:
	//Ĭ�Ϲ���
	Group();

	//�ƶ�����
	//����Ҽӣ��ϼ��¼�
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();

	//��ת���ع���ת
	//���������ඨ��
	virtual void Rotate() = 0;
	virtual void RotateBack() = 0;

	//�ж��Ƿ���Ϸ����
	bool GetStatus();

	//���������
	virtual Block* GetBlock();
protected:
	//һ�鷽�����Ŀ�����������
	Block block[4];
	//һ�鷽�������ɶ���ͼ��
	int Pattern;
};
#endif // !BLOCK_H


#ifndef BLOCK_H
#define BLOCK_H

/*
	ȫ�����
*/

class Block
{
public:
	//Ĭ�Ϲ���
	Block();
	//�вι���
	Block(int IniRow, int IniCol);
	//������ֵ
	void SetRow(int SetRow);
	//������ֵ
	void SetCol(int SetCol);
	//��ȡ��ֵ
	int GetRow();
	//��ȡ��֧
	int GetCol();
	//�ƶ�
	void Move(int r, int c);
private:
	int col,row;			//����ֵ
};
#endif // !BLOCK_H
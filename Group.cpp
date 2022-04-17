#include "Group.h"

Group::Group()
{
}

void Group::MoveLeft()
{
	int i;
	for (i = 0; i <= 3; i++)
	{
		block[i].Move(0,-1);
	}
}

void Group::MoveRight()
{
	int i;
	for (i = 0; i <= 3; i++)
	{
		block[i].Move(0, 1);
	}
}

void Group::MoveUp()
{
	for (int i = 0; i < 4; i++)
	{
		block[i].Move(-1, 0);
	}
}

void Group::MoveDown()
{
	int i;
	for (i = 0; i <= 3; i++)
	{
		block[i].Move(1, 0);
	}
}

bool Group::GetStatus()
{
	int i;
	for ( i = 0; i <= 3; i++)
	{
		if (block[i].GetRow() <= 0)
		{
			return true;
		}
	}
	return false;
}

Block* Group::GetBlock()
{
	return block;
}

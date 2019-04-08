#ifndef __ONESTAR_H__
#define __ONESTAR_H__
#include <cstdio>
#include "Base.h"

class OneStar : public BaseObject
{
	bool Action()
	{
		_X++;
		if (_X > 79)
			return false;
		return true;
	}

	void Draw()
	{
		for (int i = 0; i < _X; i++)
			wprintf(L" ");
		wprintf(L"*");
	}
};

#endif
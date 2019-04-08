#ifndef __TWOSTAR_H__
#define __TWOSTAR_H__
#include <cstdio>
#include "Base.h"

class TwoStar : public BaseObject
{
	bool Action()
	{
		_X += 2;
		if (_X > 79)
			return false;
		return true;
	}

	void Draw()
	{
		for (int i = 0; i < _X; i++)
			wprintf(L" ");
		wprintf(L"**");
	}
};

#endif
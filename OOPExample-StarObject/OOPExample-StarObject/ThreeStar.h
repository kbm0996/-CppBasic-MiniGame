#ifndef __THREESTAR_H__
#define __THREESTAR_H__
#include <cstdio>
#include "Base.h"

class ThreeStar : public BaseObject
{
	bool Action()
	{
		_X += 3;
		if (_X > 79)
			return false;
		return true;
	}

	void Draw()
	{
		for (int i = 0; i < _X; i++)
			wprintf(L" ");
		wprintf(L"***");
	}
};

#endif
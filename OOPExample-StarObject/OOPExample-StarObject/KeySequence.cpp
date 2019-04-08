#include "KeySequence.h"

void KeySequence()
{
	BaseObject * pBaseObject = nullptr;

	if (_kbhit())
	{
		switch (_getwch())
		{
		case L'1':
			pBaseObject = new OneStar;
			break;
		case L'2':
			pBaseObject = new TwoStar;
			break;
		case L'3':
			pBaseObject = new ThreeStar;
			break;
		}

		for (int i = 0; i < df_LINE; i++)
		{
			if (g_pArray[i] == nullptr)
			{
				g_pArray[i] = pBaseObject;
				break;
			}
		}
	}
}

#include "Logic.h"
#include "Base.h"
void Action()
{
	for (int i = 0; i < df_LINE; i++)
	{
		if (g_pArray[i] != nullptr)
			if (g_pArray[i]->Action())
				g_pArray[i]->Action();
			else
			{
				delete g_pArray[i];
				g_pArray[i] = nullptr;
			}
	}
}

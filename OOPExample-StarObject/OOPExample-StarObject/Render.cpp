#include "Render.h"
#include <cstdio>

void Draw()
{
	for (int i = 0; i < df_LINE; i++)
	{
		if (g_pArray[i] != nullptr)
			g_pArray[i]->Draw();
		wprintf(L"\n");
	}
}
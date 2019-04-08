#include "_config.h"
#include <iostream>

//------------------------------------------------
// TODO: 캐시 친화적인 코드 (Cache Friendly Code)
// # Spatial Locality : 프로그램 실행 시 접근하는 메모리 영역은 이미 접근이 이루어진 영역의 근처일 확률이 높다
//
// 메모리는 선형([0][0]-[0][1]-...-[1][0]-[1][1]...)으로 연결되어 있다.
// 맵, 타일 등의 2차원 배열을 사용 시 [가로][세로]가 아닌 [세로][가로]로 사용한다.
// 이렇게 되어야 가로 축으로 메모리가 연속되므로 순회 시 빠르다.
//------------------------------------------------
WCHAR g_chMap[df_MAP_HEIGHT][df_MAP_WIDTH];

bool InitMap()
{
	for (int i = 0; i < df_MAP_HEIGHT; ++i)
		for (int j = 0; j < df_MAP_WIDTH; ++j)
			g_chMap[i][j] = L'□';
	return true;
}

void DrawMap(void)
{
	for (int i = 0; i < df_MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < df_MAP_WIDTH; ++j)
		{
			if (i == g_iPosY)
			{
				if (j == g_iPosX)
				{
					wprintf(L"◎");
				}
				else
				{
					wprintf(L"%c", g_chMap[i][j]);
				}
			}
			else
				wprintf(L"%c", g_chMap[i][j]);
		}
		wprintf(L"\n");
	}

	wprintf(L"Now Player : %d \n%s", g_iPlayer, g_szMessage);
	memset(g_szMessage, NULL, df_MESSAGE_LEN);
}

void PrintMsg(WCHAR * szMsg)
{
	wcscpy_s(g_szMessage, szMsg);
}
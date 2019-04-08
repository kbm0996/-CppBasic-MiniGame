#include "_config.h"
#include <iostream>

//------------------------------------------------
// TODO: ĳ�� ģȭ���� �ڵ� (Cache Friendly Code)
// # Spatial Locality : ���α׷� ���� �� �����ϴ� �޸� ������ �̹� ������ �̷���� ������ ��ó�� Ȯ���� ����
//
// �޸𸮴� ����([0][0]-[0][1]-...-[1][0]-[1][1]...)���� ����Ǿ� �ִ�.
// ��, Ÿ�� ���� 2���� �迭�� ��� �� [����][����]�� �ƴ� [����][����]�� ����Ѵ�.
// �̷��� �Ǿ�� ���� ������ �޸𸮰� ���ӵǹǷ� ��ȸ �� ������.
//------------------------------------------------
WCHAR g_chMap[df_MAP_HEIGHT][df_MAP_WIDTH];

bool InitMap()
{
	for (int i = 0; i < df_MAP_HEIGHT; ++i)
		for (int j = 0; j < df_MAP_WIDTH; ++j)
			g_chMap[i][j] = L'��';
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
					wprintf(L"��");
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
#include "_config.h"

int g_iPosX;			// ���� Ŀ���� ��ġ
int g_iPosY;
int g_iPlayer = 1;		// 1 or 2
int g_iWinner = 0;		// �¸��ڰ� ���� �� 1 or 2 �� ���� ��.

WCHAR g_szMessage[df_MESSAGE_LEN];	// ��Ÿ �޽��� ��¿�

void CheckClear(void)
{
	int iCnt;
	WCHAR ch;

	if (g_iPlayer == 1)
		ch = df_PLAYER1_PIECE;
	else
		ch = df_PLAYER2_PIECE;

	iCnt = 0;	// -
	for (int i = -4; i < 6; ++i)
	{
		if (g_iPosX + i >= 0 && g_iPosX + i <= df_MAP_WIDTH)
		{
			if (iCnt > 4)
				g_iWinner = g_iPlayer;

			if (g_chMap[g_iPosY][g_iPosX + i] == ch)
				iCnt++;

			if (g_chMap[g_iPosY][g_iPosX + i] != ch)
				iCnt = 0;
		}
	}

	iCnt = 0;	// |
	for (int i = -4; i < 6; ++i)
	{
		if (g_iPosY + i >= 0 && g_iPosY + i <= df_MAP_HEIGHT)
		{
			if (iCnt > 4)
				g_iWinner = g_iPlayer;

			if (g_chMap[g_iPosY + i][g_iPosX] == ch)
				iCnt++;

			if (g_chMap[g_iPosY + i][g_iPosX] != ch)
				iCnt = 0;
		}
	}

	iCnt = 0;	// /
	for (int i = -4; i < 6; ++i)
	{
		if (g_iPosY + i >= 0 && g_iPosY + i <= df_MAP_HEIGHT)
			if (g_iPosX + i >= 0 && g_iPosX + i <= df_MAP_WIDTH)
			{
				if (iCnt > 4)
					g_iWinner = g_iPlayer;

				if (g_chMap[g_iPosY + i][g_iPosX - i] == ch)
					iCnt++;

				if (g_chMap[g_iPosY + i][g_iPosX - i] != ch)
					iCnt = 0;
			}
	}

	iCnt = 0;	// ��
	for (int i = -4; i < 6; ++i)
	{
		if (g_iPosY + i >= 0 && g_iPosY + i <= df_MAP_HEIGHT)
			if (g_iPosX + i >= 0 && g_iPosX + i <= df_MAP_WIDTH)
			{
				if (iCnt > 4)
					g_iWinner = g_iPlayer;

				if (g_chMap[g_iPosY + i][g_iPosX + i] == ch)
					iCnt++;

				if (g_chMap[g_iPosY + i][g_iPosX + i] != ch)
					iCnt = 0;
			}
	}
}
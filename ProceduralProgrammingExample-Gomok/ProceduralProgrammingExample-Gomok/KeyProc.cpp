#include "_config.h"
#include <conio.h>
#include <string>

//--------------------------------------------------------
// 이동 및 바둑돌 놓기에 대한 키 입력이 1회 될때까지 대기 및 반복문을 돈다.
//--------------------------------------------------------
void KeyProcess(void)
{
	WCHAR chKey;

	// TODO : 반복문을 도는 이유
	// 특수키의 경우 getch 함수에 2회에 거쳐서 키 입력이 들어오므로 1회 체크로는 감지가 불가능
	// 따라서, 원하는 키 입력이 확인되었을 때 return
	//
	// 키입력 1회에 그리기 1회의 패턴으로 로직이 돌아가므로
	// 커서이동 키입력에선 좌표만 이동, 엔터를 누르면 해당 위치에 돌을 놓음.

	while (1)
	{
		chKey = _getwch();
		switch (chKey)
		{
		case df_KEY_RIGHT:
			if (g_iPosX < df_MAP_WIDTH - 1)
				g_iPosX++;
			return;

		case df_KEY_LEFT:
			if (g_iPosX > 0)
				g_iPosX--;
			return;

		case df_KEY_UP:
			if (g_iPosY > 0)
				g_iPosY--;
			return;

		case df_KEY_DOWN:
			if (g_iPosY < df_MAP_HEIGHT - 1)
				g_iPosY++;
			return;

		case df_KEY_ENTER:
			if (g_chMap[g_iPosY][g_iPosX] != df_PLAYER1_PIECE && g_chMap[g_iPosY][g_iPosX] != df_PLAYER2_PIECE)
				if (g_iPlayer == 1)
				{
					g_chMap[g_iPosY][g_iPosX] = df_PLAYER1_PIECE;
					CheckClear();
					g_iPlayer = 2;
				}
				else
				{
					g_chMap[g_iPosY][g_iPosX] = df_PLAYER2_PIECE;
					CheckClear();
					g_iPlayer = 1;
				}
			else
			{
				PrintMsg(L"Stone Drop Fail, Retry");
			}
			return;
		}
	}
}
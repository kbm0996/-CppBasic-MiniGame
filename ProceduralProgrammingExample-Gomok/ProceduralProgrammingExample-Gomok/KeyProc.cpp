#include "_config.h"
#include <conio.h>
#include <string>

//--------------------------------------------------------
// �̵� �� �ٵϵ� ���⿡ ���� Ű �Է��� 1ȸ �ɶ����� ��� �� �ݺ����� ����.
//--------------------------------------------------------
void KeyProcess(void)
{
	WCHAR chKey;

	// TODO : �ݺ����� ���� ����
	// Ư��Ű�� ��� getch �Լ��� 2ȸ�� ���ļ� Ű �Է��� �����Ƿ� 1ȸ üũ�δ� ������ �Ұ���
	// ����, ���ϴ� Ű �Է��� Ȯ�εǾ��� �� return
	//
	// Ű�Է� 1ȸ�� �׸��� 1ȸ�� �������� ������ ���ư��Ƿ�
	// Ŀ���̵� Ű�Է¿��� ��ǥ�� �̵�, ���͸� ������ �ش� ��ġ�� ���� ����.

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
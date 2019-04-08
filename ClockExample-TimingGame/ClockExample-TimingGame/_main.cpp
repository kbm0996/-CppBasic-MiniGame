#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")

enum en_TIMING
{
	NONE,
	BAD,
	GOOD,
	GREAT,
	en_MAX_ROUND = 9
};

int g_iTiming[en_MAX_ROUND] = { 5, 10, 14, 17, 20, 25, 29, 31, 33 };	// ��ǥ �ð�
int g_iResult[en_MAX_ROUND];		// ����� ������ �迭
int g_iPos;							// ���� ��ǥ �ð� �ε�����

void main()
{
	timeBeginPeriod(1);

	COORD	pos;		// ���ڸ� ����� �ܼ� ��ġ
	int		iPushCnt;	// ���� Ƚ��

	pos.X = pos.Y = 0;
	iPushCnt = 0;

	while (iPushCnt < en_MAX_ROUND)
	{
		// TODO: �����Ÿ� ����
		/// system("cls");	// system ��ɾ�� ȭ���� ����� ȭ���� �����Ÿ��� ������ �߻�
		// ���� ���۸��� ����Ͽ� �ذ��ؾ�������, �����ϰ� �ܼ��� Ư�� ��ġ���� �ٽ� �׸��� ������ �����Ÿ� ���� �ذ�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		// TODO: _kbhit() // Ű���� ���� Ȯ��
		// ����: Ű�� ���� �� �ܼ�Ű���� ���� ������ ������ ���� ���������� ��� ���� ���� ����
		if (_kbhit())
		{
			_getch();	// ���� ���� Ű�� ASCII ���� �޾ƿ�. _getch() �Լ��� ����Ͽ� �ܼ�Ű �Է��� ���� �� ����.
						// ���� �ڵ忡���� _getch()�� ���� ���� ������� ������ �ܼ�Ű�� ���� ���� �뵵

						// TODO: clock()
						// ���μ����� ���۵� ���� �ð�, 1�ʴ� CLOCKS_PER_SEC ��(1000ms). ���ϰ��� clock_t (long) Ÿ��.
			if (abs(clock() - (g_iTiming[g_iPos] * CLOCKS_PER_SEC)) < 0.3 * CLOCKS_PER_SEC)
			{
				g_iResult[g_iPos] = GREAT;
				// ���� ��ǥ�� ����
				++g_iPos;
			}
			else if (abs(clock() - (g_iTiming[g_iPos] * CLOCKS_PER_SEC)) < 1 * CLOCKS_PER_SEC)
			{
				g_iResult[g_iPos] = GOOD;
				++g_iPos;
			}
			else
			{
				g_iResult[g_iPos] = BAD;
				++g_iPos;
			}
			iPushCnt += 1;
		}

		// ��ǥ �ð����κ��� 1�� ����� ������ BAD
		if (clock() > (g_iTiming[g_iPos] + 1) * CLOCKS_PER_SEC)
		{
			g_iResult[g_iPos] = 1;
			++g_iPos;
			iPushCnt += 1;
		}


		// ��� �ð� ���
		wprintf(L"%02d.%03d sec\n\n", clock() / 1000, clock() % 1000);

		for (int iCnt = 0; iCnt < en_MAX_ROUND; ++iCnt)
		{
			wprintf(L"%02d sec : ", g_iTiming[iCnt]);
			switch (g_iResult[iCnt])
			{
			case BAD:
				wprintf(L"Bad");
				break;
			case GOOD:
				wprintf(L"Good");
				break;
			case GREAT:
				wprintf(L"Great");
				break;
			default:
				break;
			}
			wprintf(L"\n");
		}

		if (clock() > 35 * CLOCKS_PER_SEC)
			break;

		Sleep(1);
	}

	timeEndPeriod(1);
}
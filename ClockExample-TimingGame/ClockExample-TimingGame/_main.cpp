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

int g_iTiming[en_MAX_ROUND] = { 5, 10, 14, 17, 20, 25, 29, 31, 33 };	// 목표 시간
int g_iResult[en_MAX_ROUND];		// 결과를 저장할 배열
int g_iPos;							// 현재 목표 시간 인덱스값

void main()
{
	timeBeginPeriod(1);

	COORD	pos;		// 문자를 출력할 콘솔 위치
	int		iPushCnt;	// 눌림 횟수

	pos.X = pos.Y = 0;
	iPushCnt = 0;

	while (iPushCnt < en_MAX_ROUND)
	{
		// TODO: 깜빡거림 문제
		/// system("cls");	// system 명령어로 화면을 지우면 화면이 깜빡거리는 현상이 발생
		// 더블 버퍼링을 사용하여 해결해야하지만, 간단하게 콘솔의 특정 위치부터 다시 그리는 식으로 깜빡거림 현상 해결
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		// TODO: _kbhit() // 키보드 눌림 확인
		// 주의: 키를 누른 후 콘솔키에서 값을 빼주지 않으면 다음 루프에서도 계속 같은 값을 리턴
		if (_kbhit())
		{
			_getch();	// 현재 눌린 키의 ASCII 값을 받아옴. _getch() 함수를 사용하여 콘솔키 입력을 뽑을 수 있음.
						// 현재 코드에서는 _getch()의 리턴 값은 사용하지 않지만 콘솔키를 빼기 위한 용도

						// TODO: clock()
						// 프로세스가 시작된 후의 시간, 1초는 CLOCKS_PER_SEC 값(1000ms). 리턴값은 clock_t (long) 타입.
			if (abs(clock() - (g_iTiming[g_iPos] * CLOCKS_PER_SEC)) < 0.3 * CLOCKS_PER_SEC)
			{
				g_iResult[g_iPos] = GREAT;
				// 다음 목표로 진행
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

		// 목표 시간으로부터 1초 경과시 강제로 BAD
		if (clock() > (g_iTiming[g_iPos] + 1) * CLOCKS_PER_SEC)
		{
			g_iResult[g_iPos] = 1;
			++g_iPos;
			iPushCnt += 1;
		}


		// 경과 시간 출력
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
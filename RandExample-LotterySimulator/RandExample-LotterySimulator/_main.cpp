#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <clocale>
#include <conio.h>
#pragma comment(lib,"winmm.lib")

// External Function
bool	Lottery_Auto();
bool	Lottery_Manual();

// Internal Function
bool	KeyProcess_Auto();
bool	KeyProcess_Manual();
bool	InputNumber_Auto(int* iInNumber);
bool	InputNumber_Manual(int* iInNumber);
bool	OutputNumber(int* iOutNumber);
int		CheckNumber(int* arr, int* arr2);
void	PrintResult(int* arr, int* arr2);

// Global Variable
int		g_iMode;	// 0 - Auto / 1 - Manual / Anykey - Exit

void main()
{
	timeBeginPeriod(1);
	_wsetlocale(LC_ALL, L"kor");
	
	srand((int)time(NULL));


	// Function Pointer Example
	//  type (*FunctionPointerName)(parameter);
	bool (*FunctionPtr)() = Lottery_Auto;

	while (1)
	{
		if (g_iMode == 0)
			FunctionPtr = Lottery_Auto;
		else if (g_iMode == 1)
			FunctionPtr = Lottery_Manual;
		else
			break;
		
		FunctionPtr();
		Sleep(1000);
	}

	timeEndPeriod(1);
}

bool Lottery_Auto()
{
	int iInNumber[6];
	int iOutNumber[6];

	InputNumber_Auto(iInNumber);
	OutputNumber(iOutNumber);
	PrintResult(iInNumber, iOutNumber);
	KeyProcess_Auto();

	return true;
}

bool Lottery_Manual()
{
	int iInNumber[6];
	int iOutNumber[6];

	InputNumber_Manual(iInNumber);
	OutputNumber(iOutNumber);
	PrintResult(iInNumber, iOutNumber);
	KeyProcess_Manual();

	return true;
}

bool KeyProcess_Auto()
{
	if (_kbhit())			// Checking if the keyboard is pressed
	{
		switch (_getch())	// Checking pressed key
		{
		case '0':
			g_iMode = 0;
			break;
		case '1':
			g_iMode = 1;
			break;
		default:
			g_iMode = 2;
			break;
		}
	}
	return true;
}

bool KeyProcess_Manual()
{
	int iKey;
	wscanf_s(L"%d", &iKey);

	switch (iKey)
	{
	case 0:
		g_iMode = 0;
		break;
	case 1:
		g_iMode = 1;
		break;
	default:
		g_iMode = 2;
		break;
	}
	return true;
}

bool InputNumber_Auto(int* iInNumber)
{
	for (int x = 0; x < 6; x++)
	{
		iInNumber[x] = rand() % 44 + 1;
		if (x != 0)
		{
			for (int y = x; y > 0; y--)
			{
				if (iInNumber[x] == iInNumber[y - 1])
				{
					x -= 1;
				}
			}
		}
	}

	return true;
}

bool InputNumber_Manual(int* iInNumber)
{
	for (int x = 0; x < 6; x++)
	{
		wprintf(L"%d) 숫자 입력(1~45) : ", x + 1);
		wscanf_s(L"%d", &iInNumber[x]);

		if (iInNumber[x] < 1)
		{
			wprintf(L"- 1보다 작은 값을 입력할 수 없습니다. \n");
			x -= 1;
		}
		else if (iInNumber[x] > 45)
		{
			wprintf(L"- 45보다 큰 값을 입력할 수 없습니다. \n");
			x -= 1;
		}
		else if (x != 0)
		{
			for (int y = x; y > 0; y--)
			{
				if (iInNumber[x] == iInNumber[y - 1])
				{
					wprintf(L"- 이미 입력한 번호를 다시 입력할 수 없습니다.\n");
					x -= 1;
				}
			}
		}
	}
	return true;
}

bool OutputNumber(int* iOutNumber)
{
	for (int x = 0; x < 6; x++)
	{
		iOutNumber[x] = rand() % 44 + 1;
		if (x != 0)
		{
			for (int y = x; y > 0; y--)
			{
				if (iOutNumber[x] == iOutNumber[y - 1])
					x -= 1;
			}
		}
	}

	return true;
}

int CheckNumber(int* arr, int* arr2)
{
	int iCount = 0;

	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			if (arr[x] == arr2[y])
				iCount += 1;
		}
	}
	return iCount;
}

void PrintResult(int * iInNumber, int * iOutNumber)
{
	wprintf(L"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	wprintf(L"┃- 입력 번호 : %2d %2d %2d %2d %2d %2d ┃\n", iInNumber[0], iInNumber[1], iInNumber[2], iInNumber[3], iInNumber[4], iInNumber[5]);
	wprintf(L"┃- 당첨 번호 : %2d %2d %2d %2d %2d %2d ┃\n", iOutNumber[0], iOutNumber[1], iOutNumber[2], iOutNumber[3], iOutNumber[4], iOutNumber[5]);
	wprintf(L"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	wprintf(L"┃- 당첨된 번호 갯수 : %d \t ┃\n", CheckNumber(iInNumber, iOutNumber));
	wprintf(L"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	wprintf(L" 0 - 자동 / 1 - 수동 / 기타 - 종료 \n\n");
}
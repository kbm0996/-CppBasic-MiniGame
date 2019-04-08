#include "_config.h"

void main(void)
{
	_wsetlocale(LC_ALL, L"ko-KR");
	InitMap();
	while (1)
	{
		//------------------------------------------------
		// 콘솔 오목은 유저의 키 입력이 없다면 아무것도 할것이 없기 때문에
		// _getch 를 사용하여 키 입력이 오기 전가지는 블럭상태로 멈추는 키 입력을 사용함
		//
		// 그리기 - 키입력 - 돌놓기 - 5개 확인 - 의 반복. 
		//------------------------------------------------
		system("cls");
		DrawMap();
		KeyProcess();
		if (g_iWinner != 0)
			break;
	}
	wprintf(L"%d Player Win!!\n", g_iWinner);
	system("pause");
}
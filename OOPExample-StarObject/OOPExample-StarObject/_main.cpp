#include <Windows.h>
#include <locale.h>
#include "KeySequence.h"
#include "Logic.h"
#include "Render.h"

void main()
{
	_wsetlocale(LC_ALL, L"");
	while (1)
	{
		system("cls");

		KeySequence();
		Action();
		Draw();

		Sleep(100);		// 프레임 제어
	}
}
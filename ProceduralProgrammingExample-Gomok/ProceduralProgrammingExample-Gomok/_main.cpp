#include "_config.h"

void main(void)
{
	_wsetlocale(LC_ALL, L"ko-KR");
	InitMap();
	while (1)
	{
		//------------------------------------------------
		// �ܼ� ������ ������ Ű �Է��� ���ٸ� �ƹ��͵� �Ұ��� ���� ������
		// _getch �� ����Ͽ� Ű �Է��� ���� �������� �����·� ���ߴ� Ű �Է��� �����
		//
		// �׸��� - Ű�Է� - ������ - 5�� Ȯ�� - �� �ݺ�. 
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
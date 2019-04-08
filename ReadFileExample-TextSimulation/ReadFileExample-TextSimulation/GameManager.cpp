#include "GameManager.h"

GameManager::GameManager() : _iEventID(1)
{
	if (!LoadEvent() || !LoadSelect())
	{
		// �ǵ������� Crash
		int *p = nullptr;
		*p = 0;
	}
}

bool GameManager::LoadEvent()
{
	FILE *pFile;
	fopen_s(&pFile, "Event.txt", "rt");
	if (pFile == NULL)
	{
		printf("Event File not found.\n");
		return false;
	}

	char szBuff[en_MAX_STRING];
	char* pszBuff;

	unsigned int uiItem = 0;
	unsigned int uiIndex = 0;
	int pre = 0;

	char szLine[en_MAX_STRING];

	// Event, Select.txt������ `������ȣ, ����, ��������ȣ` �� 3���� �׸�(Item)���� �����Ǿ� ����.
	while (!feof(pFile))	// EOF ������ ������
	{
		fgets(szBuff, sizeof(szBuff), pFile);	// pFile�κ��� NULL���ڳ� �ٹٲ޹��ڱ��� �ִ� szBuffũ�⸸ŭ �о����
		pszBuff = szBuff;

		for (int i = 0; i < en_MAX_STRING; ++i)
		{
			if (szBuff[i] == ',')	// ������
			{
				// ù��° �׸� ���
				if (uiItem == 0)
				{
					strcpy_s(szLine, pszBuff);
					_stEvent[uiIndex]._iEvent = atoi(szLine);

					++uiItem;
					pre = i;
				}

				// �ι�° �׸� ���
				else if (uiItem == 1)
					strncpy_s(_stEvent[uiIndex]._szText, pszBuff, i - pre - 1);

				pszBuff = &szBuff[i + 1];
			}

			// ������ �׸� ��� + ����������
			if (szBuff[i] == '\0')	// NULL ���ڸ� ������ Ž�� ����
			{
				strcpy_s(szLine, pszBuff);
				_stEvent[uiIndex]._iEnding = atoi(szLine);
				++uiItem;
				break;
			}
		}
		uiItem = 0;
		++uiIndex;
	}
	fclose(pFile);
	return true;
}

bool GameManager::LoadSelect()
{
	FILE *pFile;
	fopen_s(&pFile, "Select.txt", "rt");
	if (pFile == NULL)
	{
		printf("Select File not Found.\n");
		return false;
	}

	char szBuff[en_MAX_STRING];
	char* pszBuff;

	unsigned int uiItem = 0;
	unsigned int uiIndex = 0;
	int pre = 0;

	char szLine[en_MAX_STRING];

	while (!feof(pFile))
	{
		fgets(szBuff, sizeof(szBuff), pFile);
		pszBuff = szBuff;

		for (int i = 0; i < en_MAX_STRING; ++i)
		{
			if (szBuff[i] == ',')
			{
				if (uiItem == 0)
				{
					strcpy_s(szLine, pszBuff);
					_stSelect[uiIndex]._iEvent = atoi(szLine);

					++uiItem;
					pre = i;
				}

				else if (uiItem == 1)
					strncpy_s(_stSelect[uiIndex]._szText, pszBuff, i - pre - 1);

				pszBuff = &szBuff[i + 1];
			}

			if (szBuff[i] == '\0')
			{
				strcpy_s(szLine, pszBuff);
				_stSelect[uiIndex]._iSelect = atoi(szLine);
				++uiItem;
				break;
			}
		}
		uiItem = 0;
		++uiIndex;
	}
	fclose(pFile);
	return true;
}

bool GameManager::Running()
{
	// Ending�� ��� false
	if (SceneView(_iEventID))
		return false;

	// Ending�� �ƴ� ��� ������ ���� true
	_iEventID = MoveEvent(_iEventID);
	return true;
}

bool GameManager::SceneView(int EventID)
{

	printf("[EventID:%d] \n\n", EventID);
	for (int i = 0; i < en_MAX_EVENT; ++i)
	{
		if (_stEvent[i]._iEvent == EventID)
		{
			printf("%s \n", _stEvent[i]._szText);
			printf("-------------------------------\n");
			if (_stEvent[i]._iEnding == 0)
				return false;
			else
				return true;
		}
	}
}

int GameManager::MoveEvent(int EventID)
{
	unsigned int iInputNo;
	int iEventNo[en_MAX_SELECT];
	unsigned int uiIndex = 1;
	ZeroMemory(iEventNo, sizeof(iEventNo));

	for (int i = 0; i < en_MAX_SELECT; ++i)
	{
		if (EventID == _stSelect[i]._iEvent)
		{
			printf("%d. %s \n", uiIndex, _stSelect[i]._szText);
			iEventNo[uiIndex] = _stSelect[i]._iSelect;
			++uiIndex;
		}
	}
	uiIndex = 1;
	printf("\n�����ϼ���:");

	// ���� �� ���� �Է��ϱ� ������ ���Է�
	while (1)
	{
		iInputNo = _getch() - 48;
		if (iEventNo[iInputNo] == 0 || iInputNo > en_MAX_SELECT)
			continue;
		else
			break;
	}

	return iEventNo[iInputNo];
}
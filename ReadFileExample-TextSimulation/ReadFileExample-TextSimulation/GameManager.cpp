#include "GameManager.h"

GameManager::GameManager() : _iEventID(1)
{
	if (!LoadEvent() || !LoadSelect())
	{
		// 의도적으로 Crash
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

	// Event, Select.txt파일은 `질문번호, 지문, 목적지번호` 총 3가지 항목(Item)으로 구성되어 있음.
	while (!feof(pFile))	// EOF 만나기 전까지
	{
		fgets(szBuff, sizeof(szBuff), pFile);	// pFile로부터 NULL문자나 줄바꿈문자까지 최대 szBuff크기만큼 읽어오기
		pszBuff = szBuff;

		for (int i = 0; i < en_MAX_STRING; ++i)
		{
			if (szBuff[i] == ',')	// 구분자
			{
				// 첫번째 항목 얻기
				if (uiItem == 0)
				{
					strcpy_s(szLine, pszBuff);
					_stEvent[uiIndex]._iEvent = atoi(szLine);

					++uiItem;
					pre = i;
				}

				// 두번째 항목 얻기
				else if (uiItem == 1)
					strncpy_s(_stEvent[uiIndex]._szText, pszBuff, i - pre - 1);

				pszBuff = &szBuff[i + 1];
			}

			// 마지막 항목 얻기 + 빠져나가기
			if (szBuff[i] == '\0')	// NULL 문자를 문나면 탐색 종료
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
	// Ending일 경우 false
	if (SceneView(_iEventID))
		return false;

	// Ending이 아닐 경우 선택지 띄우고 true
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
	printf("\n선택하세요:");

	// 범위 내 값을 입력하기 전까지 재입력
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
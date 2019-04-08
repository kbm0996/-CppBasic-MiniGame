#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

class GameManager
{
private:
	enum en_CONFIG
	{
		en_MAX_EVENT = 100,
		en_MAX_SELECT = 100,
		en_MAX_STRING = 255
	};

	struct st_EVENT
	{
		int _iEvent;
		char _szText[en_MAX_STRING];
		int _iEnding;
	};

	struct st_SELECT
	{
		int _iEvent;
		char _szText[en_MAX_STRING];
		int _iSelect;
	};
public:
	GameManager();
	virtual ~GameManager() {}

	bool Running();

protected:
	bool LoadEvent();
	bool LoadSelect();

	bool SceneView(int EventID);
	int MoveEvent(int EventID);

private:
	st_EVENT	 _stEvent[en_MAX_EVENT];
	st_SELECT	 _stSelect[en_MAX_SELECT];

	int _iEventID;
};

#endif
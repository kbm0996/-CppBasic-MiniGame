#ifndef __CONFIG_H__
#define __CONFIG_H__

// HEADER
#include <Windows.h>
#include <string>
#include "Map.h"
#include "KeyProc.h"
#include "Logic.h"

/* MAP */
#define df_MAP_WIDTH	10
#define df_MAP_HEIGHT	10
extern WCHAR g_chMap[df_MAP_HEIGHT][df_MAP_WIDTH];

/* PIECE */
#define df_PLAYER1_PIECE L'●'
#define df_PLAYER2_PIECE L'○'

/* LOGIC */
#define df_KEY_LEFT		0x4b
#define df_KEY_RIGHT	0x4d
#define df_KEY_UP		0x48
#define df_KEY_DOWN		0x50
#define df_KEY_ENTER	0x0d
#define df_MESSAGE_LEN	30
extern WCHAR g_szMessage[df_MESSAGE_LEN];

#endif // !__CONFIG_H__
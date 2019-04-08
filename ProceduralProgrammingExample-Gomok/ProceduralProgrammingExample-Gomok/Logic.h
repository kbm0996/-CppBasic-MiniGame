#ifndef __LOGIC_H__
#define __LOGIC_H__

// 오목 클리어 여부 체크
void CheckClear(void);

// 현재 커서의 위치
extern int g_iPosX;
extern int g_iPosY;

// 플레이어1 플레이어2
extern int g_iPlayer;

// 최종 승리 플레이어
extern int g_iWinner;


#endif // !__LOGIC_H__
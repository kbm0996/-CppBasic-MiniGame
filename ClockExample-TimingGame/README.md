# 타이밍 게임
## 📢 개요
  목표 시간에 맞춰 아무 키나 누르면 정확도에 따라 등급을 매기는 게임
  
  >![capture](https://user-images.githubusercontent.com/18212066/49537145-8c622980-f90b-11e8-802e-c46643502ae8.jpg)

  
 **figure 1. Timing Game*


## 📌 주요 레퍼런스

 #### ☑ 화면 지우기 ①
 
 콘솔 화면을 지우는 가장 간단한 방법
 
   - 함수 원형
   >int system(const char *cmd); 
   
   시스템 명령 실행
   
  - 소스 코드
  
          system("cls");	// cls는 화면을 지우는 시스템 명령어


 #### ☑ 화면 지우기 ②
 
  system("cls")로 화면을 지울 경우 깜빡임 현상이 너무 지나치게 일어남. 이를 해결하기 위해  사용
  
   - 함수 원형
   
  >BOOL WINAPI SetConsoleCursorPosition(
  _In_ HANDLE hConsoleOutput,
  _In_ COORD  dwCursorPosition
);
 
 지정된 콘솔 화면 버퍼의 커서 위치를 설정
 
   - 소스 코드
  
          COORD	pos;		// 문자를 출력할 콘솔 위치
          pos.X = pos.Y = 0;
          while ( ... )
          {
            /// system("cls");	// system 명령어로 화면을 지우면 화면이 깜빡거리는 현상이 발생
            // 더블 버퍼링을 사용하여 해결해야하지만, 간단하게 콘솔의 특정 위치부터 다시 그리는 식으로 깜빡거림 현상 해결
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            ...
          }
        
 #### ☑ 프로세스 실행 시간 구하기
 
  타이밍 계산을 위한 함수
  
   - 함수 원형
   
  >clock_t clock( void );  
 
 프로세스의 시작 시 CRT 초기화 이후 경과 된 시간. ms 단위 반환
 
   - 소스 코드
  
          ...
          // clock()
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
          ...

 #### ☑ 키보드 눌림 감지
 
  키가 눌린 시간을 얻기 위해 사용
 
  - 함수 원형
  >int _kbhit(void);

 키보드가 눌리면 0이 아닌 값을 반환한다.    

  #### ☑ 눌린 키 값 반환
  
   눌린 키 값 자체가 필요하진 않음. _kbhit()가 다음 루프에서 같은 값을 리턴하는 현상을 방지하기 위해 값을 빼주기 위해 사용
    
   - 함수 원형
   >int _getch(void);
 
  _kbhit()에서 감지한 키를 아스키코드 정수형으로 반환한다. 

 
  - 소스 코드
 
          ...
 
          if (_kbhit())	
      		{
      			_getch();	
            ...
          }
 
          ...

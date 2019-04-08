# 복권 시뮬레이터
## 📢 개요
  1 이상 45 이하의 숫자 중 서로 다른 6개의 숫자를 선택하여 맞추는 것


## 📑 설명
  수동 모드는 비교할 6개의 숫자를 사용자가 직접 입력해야하고, 자동 모드는 이 숫자들 또한 무작위 값으로 뽑아서 당첨 숫자들과 비교한다.

  >![capture_manual](https://user-images.githubusercontent.com/18212066/49331476-da5ff000-f5e0-11e8-8a70-941dbaba3ea4.png) ![capture_auto](https://user-images.githubusercontent.com/18212066/49331475-da5ff000-f5e0-11e8-811a-d2345e20ca99.png)
  
 **figure 1, 2. (left)manual, (right)auto*


## 📌 주요 레퍼런스
#### ☑ 함수 포인터

 함수 이름이 함수의 메모리 주소임을 이용한 방법. 포인터에 이를 저장하여 해당 함수를 다양한 방법으로 호출할 수 있다.

  - 형식
  >returntype (*FunctionPointerName)(parameter);

  해당 프로그램의 구현에 있어서 반드시 사용해야하는 문법은 아니지만, 개념을 익힌다는 차원에서 간단하게 사용해봄.

  - 소스 코드

          ...
          bool (*FunctionPtr)();
          while (1)
          {
              if (g_iMode == 0)
                FunctionPtr = Lottery_Auto;
              else if (g_iMode == 1)
                FunctionPtr = Lottery_Manual;
              ...
          }
          ...



#### ☑ 난수 생성

 1~45 사이의 무작위 숫자를 생성하기 위해 rand() 함수 사용

 - 함수 원형
 >int rand(void);

 rand() 함수는 `의사 난수(pseudo-random number)`를 생성한다. 이 값은 몇 번을 호출해도 처음 호출했을 때 값이 그대로 반환되는 문제점이 있다.

 >void srand(unsigned int seed);

 srand() 함수는 rand() 함수의 문제점을 해결하기 위해 난수 생성을 위한 씨드(seed) 값을 제공한다.


 - 소스 코드

         ...

         srand((int)time(NULL));

         ...
  
         iInNumber[x] = rand() % 44 + 1;

         ...


 #### ☑ 키보드 눌림 감지
 
  자동 모드에서 키를 입력받을때 이를 논-블록(non-block)으로 감지하기 위해 사용
 
  - 함수 원형
  >int _kbhit(void);

 키보드가 눌리면 0이 아닌 값을 반환한다.

  #### ☑ 눌린 키 값 반환
  
   - 함수 원형
   >int _getch(void);
 
  _kbhit()에서 감지한 키를 아스키코드 정수형으로 반환한다.
  

 
  - 소스 코드
 
          ...
 
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
 
          ...

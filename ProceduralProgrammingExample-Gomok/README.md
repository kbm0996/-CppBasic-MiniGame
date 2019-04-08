# 절차지향형 코드 예제
## 📢 개요
 ``절차적(procedural) 프로그래밍``이 순차적 프로그래밍과 혼동하는 경우가 있다.
 절차지향 프로그래밍에서 'Procedural'은 단어 그대로 '절차지향'을 의미하는 것이 아니라 프로시저 호출(procedure call)을 의미한다.
 여기서 프로시저란 반환값이 없는 함수라고 보면 된다.
  
## 💻 오목
 간단한 오목 게임. _config.h의 define들을 변경하면 말(piece)의 모양, 판(map)의 넓이 등을 변경할 수 있다.
커서의 위치는 방향키를 입력하여 제어 가능하며, 엔터 입력 시 말(piece)을 놓음과 동시에 상대방에게 차례(turn)을 넘긴다.

  ![capture](https://github.com/kbm0996/Procedural-Code-Example/blob/master/capture.jpg?raw=true)
  
  **figure 1. Gomoku*

  ○ - Player1
  ● - Player2
  ◎ - Cursor


## 📐 워크플로우
 객체지향형 프로그램의 구조와 작동 순서

  ![workflow](https://github.com/kbm0996/Procedural-Code-Example/blob/master/workflow.JPG?raw=true)
  
  **figure 2. Workflow*

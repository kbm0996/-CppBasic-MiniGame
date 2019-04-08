# 객체지향형 코드 예제
## 📢 개요
 ``절차(procedural) 프로그래밍``이  프로시저 호출(procedure call)을 중심으로 프로그래밍하는 것을 의미했다면,

``객체지향(object-oriented) 프로그래밍``은 실제 세계처럼 스스로 데이터를 처리하는 객체(object)들이 서로 메세지를 보내고 소통하는 것처럼 프로그래밍하는 것이다.

## 📌 객체지향 프로그래밍 특징
 - **캡슐화(encapsulation)**
 
    코드가 외부로 노출되지 않도록 클래스를 이용하여 모듈화하는 것이다. 이를 통해서 코드가 외부에 드러나지 않는 것을 ``정보 은닉``이라고 한다. 모듈화를 하면서 내부 코드간의 ``응집도``가 향상되는 이점도 얻을 수 있다.

 - **다형성(polymorphism)**
    
    오버로딩(overloading)을 통해서 같은 이름의 함수가 다양한 작업을 할 수 있다. 
 
 - **상속(inheritence)**
    
    자식 클래스가 부모 클래스의 특성과 기능을 물려받는 것을 말한다. 기능의 일부분을 변경해야 할 경우 자식 클래스에서 상속받은 그 기능만을 수정해서 다시 정의하게 되는데, 이러한 작업을 오버라이딩(overriding)이라고 한다.

  
## 💻 프로그램
 객체지향형 프로그램의 간단한 예시. 객체지향형 프로그래밍의 작동 원리, 구조를 간단하게 표현하고자 하였음.

  - '1' 입력시 '*'이 Loop마다 1칸씩 우측으로 이동하고 화면 끝에 닿으면 사라진다.
  
  - '2' 입력시 '**'이 Loop마다 2칸씩 우측으로 이동하고 화면 끝에 닿으면 사라진다.
  
  - '3' 입력시 '***'이 Loop마다 3칸씩 우측으로 이동하고 화면 끝에 닿으면 사라진다.
  
  ![capture](https://github.com/kbm0996/Practice-MiniGames/blob/master/OOPExample-StarObject/figure/capture.gif)
  
  **figure 1. StarObject (animatied gif)*


## 📐 워크플로우
 객체지향형 프로그램의 구조와 작동 순서

  ![workflow](https://github.com/kbm0996/Practice-MiniGames/blob/master/OOPExample-StarObject/figure/flowchart.jpg)
  
  **figure 2. Workflow*


## 🅿 주요 소스 코드

 - **캡슐화(encapsulation)**
 - **상속(inheritence)**
 
       class BaseObject
       {
       protected:
        int _X = 0;

       public:
        virtual bool Action() = 0;
        virtual void Draw() = 0;
       };

       class OneStar : public BaseObject
       {
        bool Action();
        void Draw();
       };
       
       class TwoStar : public BaseObject
       {
        bool Action();
        void Draw();
       };
       
       class ThreeStar : public BaseObject
       {
        bool Action();
        void Draw();
       };

 - **다형성(polymorphism)**
    
       extern BaseObject * g_pArray[df_LINE];
       
       void Action()
       {
        for (int i = 0; i < df_LINE; i++)
        {
         if (g_pArray[i] != nullptr)
          if (g_pArray[i]->Action())
           g_pArray[i]->Action();
          else
          {
           delete g_pArray[i];
           g_pArray[i] = nullptr;
          }
        }
       }

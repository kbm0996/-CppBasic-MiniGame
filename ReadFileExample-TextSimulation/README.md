# 텍스트 시뮬레이션 게임
## 📢 개요
 지문과 그에 따른 선택지에 따라 다양한 결말을 맞이하는 아주 간단한 텍스트 게임. 파일로부터 데이터를 읽어와 게임을 설정할 수 있다
 
  ![capture](https://github.com/kbm0996/Practice-MiniGames/blob/master/ReadFileExample-TextSimulation/figure/run.gif)
  
  **figure 1. Text Simulation (animated gif)*  
  
## 🅿 주요 소스 
- **게임 매니저 클래스**

      class GameManage
      {
      private:
       /* 생략 */
      public:
       GameManager();
       virtual ~GameManager() {}
       
       // 외부에서 호출하는 함수
       bool Running();   

      protected:
      // 생성자에서 호출하는 함수
       bool LoadEvent();  // *Event.txt를 불러오는 함수
       bool LoadSelect(); // *Select.txt를 불러오는 함수
       
       // 내부에서 호출하는 함수
       bool SceneView(int EventID);
       int MoveEvent(int EventID);

      private:
       st_EVENT	 _stEvent[en_MAX_EVENT]; // 이벤트들을 저장하는 구조체
       st_SELECT	 _stSelect[en_MAX_SELECT]; // 선택지들을 저장하는 구조체

       int _iEventID; // 현재 가리키는 이벤트의 식별번호
      };


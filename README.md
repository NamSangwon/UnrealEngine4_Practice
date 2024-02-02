### UMG 사용을 위한 모듈 종속성 구성

*Modules* <br>
|Basic Module||**Core**||
|:---:|:---:|:---:|:---:|
|Basic Module|CoreUObject|Engine|InputCore|
|***For UI***|UMG|SlateCore|Slate|
|CustomModules|Module1|Module2|etc...|

--- 

### UMG를 사용하기 위해서는 아래의 그림과 같이 (프로젝트명).Build.cs 파일의 내용을 변경한다.
![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/fad33125-e0a8-471b-bfe7-b32cc2fd19c7)

---

### 위젯을 입력 받기 위해 PlayerController 컴포넌트를 생성하여 아래와 같이 설정 추가
![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/b164339e-d549-4705-8be4-f228422ce578)

---

### 위젯 블루프린트 생성
![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/c5701565-62db-4cf1-8104-031433739e69)

---

### 레벨이 시작된 후의 메인 메뉴를 로드하는 게임 모드 에셋 구성
1. Menu Game Mode 블루프린트 클래스 생성
  - ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/e022e4f8-d6c0-4911-b04a-334cfadbe5ea)
  - 게임 시작 시 메뉴로 뜨도록 하기 위함<br>
    ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/c7351e31-b329-468d-8065-44a4cf79864a)
  - 메뉴에서 플레이어가 날아다니지 않도록 하기 위함<br>
    ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/94d3aa32-2f79-464f-97a5-a953382d2323)
  - 메인 메뉴에 마우스 커서를 보이도록 하기 위함 <br>
    ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/1ab72f11-cd85-4323-81e8-25c591d41843)




2. 게임 내에서 마우스 커서를 보이게 하기 위한 "플레이어 컨트롤러" 블루프린트 클래스 생성
  - ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/4c82d53c-ab3d-4ae3-ba90-b43a77ed1318)
  - ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/0f221838-f6d0-420f-ad3f-bf370b1f45e1)

3. 게임 시작 후 설정한 블루프린트 클래스가 적용되도록 월드 세팅
  - ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/32f9e63d-eb72-44fc-b0d5-75e49fc2d5e1)

---

### New Game 위젯 구성

- 텍스트 엔트리가 잘되는 지 확인하기 위한 임시 블루프린트 설계
  ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/27b1dc1d-f74e-431d-8584-937792497484)

- (상) 게임 실행 버튼 & (하) 메인 메뉴로의 이동 버튼 블루프린트 구성
  ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/1ff7e4d3-d33a-44d2-8b67-c5ccaa1c7847)

### 기본 맵 세팅
1. `현재 레벨을 다른 이름으로 저장`을 통해 기본 맵 파일 생성 <br>
  ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/7eab641f-1a46-4eaa-829f-008a5f50faba)

2. `에디터 시작 맵`을 생성한 맵으로 하여 에디터 시작 시 생성한 맵을 기본 맵으로 지정 <br>
  ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/55c766fa-6cf5-44fb-bf92-7f3ca35447c6)

---

### Game Mode 설정

- 언리얼 엔진에서 게임의 규칙과 승리 조건등을 정의하는 클래스

- `(프로젝트 명) + ModeBase` 라는 이름의 헤더 파일과 소스 파일 수정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/62cff45a-e709-4ebb-b315-1d57cfa9e2ec)

- 프로젝트에 설정한 게임 모드를 적용 시킬 블루프린트 생성
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/01b96d53-2900-43b8-aed1-9e35186fbfe1)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/bbcbbe24-4b37-45da-bb76-3356ae189d3e)

- 수정한 게임 모드를 적용시킬 수 있도록 설정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/81a91e5c-06e3-4776-b98f-a106f1c968ed)

---

### 캐릭터 클래스 구현

- c++ 클래스 중에서 Character 클래스를 사용하여 생성 (걷기, 뛰기 등과 같은 기본 기능 탑재)

- 해당 클래스를 기반으로 블루프린트 클래스 생성
    + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/4071185d-7453-441f-837a-ea08f1c0d80f)

- 해당 게임 모드에서의 `Defalut Pawn Class`로 지정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/958baf6a-4e1f-4931-8e17-821555385ecb)

---

### 캐릭터 움직임 설정

- 입력 매핑
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/fafc96de-abfd-48bd-818a-3f708bbc5a1c)

- 전후 & 좌우 이동 함수 구현 및 매핑한 입력 키와의 바인딩
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/0f4001b4-5bb5-4c53-95cc-0aa4c1996ca9)

---

### 캐릭터 화면 회전 기능 구현

- 입력 매핑
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/413600b9-3c81-4985-acf7-8ca009f4c242)

- 카메라 회전 함수와 매핑한 입력 키와의 바인딩
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/7c42f0c3-d341-4c18-a843-9bcb03e495af)

---

### 캐릭터 점프 기능 구현

- 입력 매핑 (***매핑 추가 주의!!! 액션 매핑과 축 매핑은 두가지가 있음을 파악해야 함***)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/42f95f54-cff1-491e-9e7b-5a5e50fe0874)

- 점프 구현 함수와 매핑한 입력 키와의 바인딩
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/b54f6d34-379a-4a64-a148-83bf7aa922df)

---

### 캐릭터 메시 추가

- (3인칭) 캐릭터 스켈레탈 메시 추가 (스켈레탈 메시 == 애니메이션을 가지는 메시) (ex. 다른 플레이어 보이기)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/53374c75-3b22-4c78-af3f-59e946e3ca7f)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/d4fa4dc4-4cc2-4f0e-b4d1-2db191a2fccc)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/e3d4db75-7e8e-4f38-aae5-e525984f8e04)
  + Arrow 방향과 Mesh 방향이 일치해야 정상적으로 움직임
    
- (3인칭) 스켈레탈 메시 추가로 인해 카메라에 몸통이 보이는 에러 발생 &rightarrow; 카메라 위치 조정 (캐릭터의 머리 위에 오도록)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/8f483158-9eab-4c39-86d5-ecace91ad228)
  + *위의 그림에서 `Text()`를 `TEXT()`로 변경*

- (1인칭) 캐릭터 메시 추가 (ex. FPS에서의 팔 보이기) 및 카메라에 메시 적용
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/cef24c23-471d-44a6-b4de-c90b2476c299)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/9c5a8b72-764f-4cc5-b0c3-e460bdec1745)

- 3인칭 메시와 그림자가 보이는 에러 발생 &rightarrow; 아래의 그림과 같이 블루프린트에서의 렌더링과 라이팅 수정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/639ebb21-d659-43f4-bf90-fbaead327e6e)



## 기본 맵 세팅
1. `현재 레벨을 다른 이름으로 저장`을 통해 기본 맵 파일 생성 <br>
  ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/7eab641f-1a46-4eaa-829f-008a5f50faba)

2. `에디터 시작 맵`을 생성한 맵으로 하여 에디터 시작 시 생성한 맵을 기본 맵으로 지정 <br>
  ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/55c766fa-6cf5-44fb-bf92-7f3ca35447c6)

---

## Game Mode 설정

- 언리얼 엔진에서 게임의 규칙과 승리 조건등을 정의하는 클래스

- `(프로젝트 명) + ModeBase` 라는 이름의 헤더 파일과 소스 파일 수정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/62cff45a-e709-4ebb-b315-1d57cfa9e2ec)

- 프로젝트에 설정한 게임 모드를 적용 시킬 블루프린트 생성
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/01b96d53-2900-43b8-aed1-9e35186fbfe1)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/bbcbbe24-4b37-45da-bb76-3356ae189d3e)

- 수정한 게임 모드를 적용시킬 수 있도록 설정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/81a91e5c-06e3-4776-b98f-a106f1c968ed)

---

## 캐릭터 클래스 구현

- c++ 클래스 중에서 Character 클래스를 사용하여 생성 (걷기, 뛰기 등과 같은 기본 기능 탑재)

- 해당 클래스를 기반으로 블루프린트 클래스 생성
    + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/4071185d-7453-441f-837a-ea08f1c0d80f)

- 해당 게임 모드에서의 `Defalut Pawn Class`로 지정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/958baf6a-4e1f-4931-8e17-821555385ecb)

---

## 캐릭터 움직임 설정

- 입력 매핑
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/fafc96de-abfd-48bd-818a-3f708bbc5a1c)

- 전후 & 좌우 이동 함수 구현 및 매핑한 입력 키와의 바인딩
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/0f4001b4-5bb5-4c53-95cc-0aa4c1996ca9)

---

## 캐릭터 화면 회전 기능 구현

- 입력 매핑
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/413600b9-3c81-4985-acf7-8ca009f4c242)

- 카메라 회전 함수와 매핑한 입력 키와의 바인딩
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/7c42f0c3-d341-4c18-a843-9bcb03e495af)

---

## 캐릭터 점프 기능 구현

- 입력 매핑 (***매핑 추가 주의!!! 액션 매핑과 축 매핑은 두가지가 있음을 파악해야 함***)
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/42f95f54-cff1-491e-9e7b-5a5e50fe0874)

- 점프 구현 함수와 매핑한 입력 키와의 바인딩
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/b54f6d34-379a-4a64-a148-83bf7aa922df)

---

## 캐릭터 메시 추가

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

---

## 발사체 추가

- 입력 매핑
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/de6cabd4-3f05-46ed-b681-203442da5225)

- 발사체 클래스 추가 (Actor를 부모클래스로 사용)
  + `#include "Components/SphereComponent.h"`와 `#include "GameFramework/ProjectileMovementComponent.h"`를 통해 구체와 발사체 움직임 컴포넌트를 import 한다.
  + 발사체 충돌 변수 및 발사체 움직임 변수 초기화
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/530afebb-079b-471a-afe9-0dcf46f9f5ae)
  + 발사체 발사 함수
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/502b4e64-7d29-4002-a078-c58706786606)
  
- 캐릭터에 발사체 발사 함수 구현
  + 발사체 발사 함수 Fire(), 발사체 스폰 위치 변수, 발사체 클래수 변수 선언 및 초기화
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/21b1a45e-ee88-4a58-8bb2-8cf490ca3a80)
  + 발사체 발사 함수 Fire() 구현
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/44330fc3-04d6-408a-a710-f70da4d867be)
  + 발사 함수와 입력 값 매핑
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/d428efb3-766a-49e8-8743-1da0b38e0175)

- 발사체 이미지 추가
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/7a82eac3-9439-40aa-939d-592890ae5dff)

- 발사체 블루프린트 구성
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/bd5c549a-13e4-43be-bed2-31d584435763)
  + Static Mesh 및 발사체 이미지 추가 (+ 크기 조정)
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/007f7bf6-94e2-4a69-bf57-166318dacbe9)
  + NoCollision으로 콜리전 설정 변경
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/b15da597-9714-4cce-9692-fa6091a2108c)
   
- 캐릭터 블루프린트에 발사체 클래스 매핑 + 발사체 카메라 앞에서 생성되게 설정 변경
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/6521c540-a202-4916-9c0a-1ea23e4b29db)

---

## 발사체 수명과 콜리전 반응 설정

- 발사체 수명 추가
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/ddc828d8-6ed3-4451-a743-428e4f08a8c7)
    
- 발사체 상호 작용 감지
  + 새로운 오브젝트 채널 추가
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/ea2830e5-066d-40ca-bdcc-e0cbd0877fa4) 
  + 프리셋에 새로운 프로파일 추가 (Pawn을 상대로만 충돌 처리)
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/7b135532-e1fd-40bf-a184-9402ab6e8c8b) 
  + 발사체 클래스의 소스파일에 충돌 프로파일 지정
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/34dba766-af3f-4dee-b2e3-07012045922c)

- 충돌 반응 추가
  + OnHit 함수 구현 (발사체에 맞은 액터를 날아가게 함)
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/5ea35bad-712c-4082-84cf-52dc8d350b57)
  + 발사체 클래스의 충돌 처리 변수에 OnHit() 함수 등록
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/377d4b1a-acaa-456c-9af0-2e318e0af46a)
  + 충돌 처리용 인스턴스 생성
    * Physics의 Simulate Physics를 On & Transform의 Mobility를 Movable로 변경 &rightarrow; OnHit 적용
      - ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/91a44a3f-3243-4abd-bcfa-52468a942587)
  + 발사체 블루프린트 조정 (콜리전 프리셋 수정)
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/116e7ff2-bea1-4dbb-8323-ca908004b6ae)

---

## 조준선 추가

- HUD 클래스를 부모로 하는 FPSHUD c++ 클래스 생성
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/41752cda-1d21-497d-bcc4-f57f7b5a0fb5)
  + 해당 클래스에 조준선 그리는 함수 작성
    * ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/0b10fb63-6d3f-4433-9405-4d0541c899de)

- HUD 클래스 기반 블루프린트 클래스 생성
  + 블루프린트 내의 `CrosshairTexture`의 변수에 조준선 이미지 추가

- 해당 조준선을 게임의 기본 HUD로 설정
  + ![image](https://github.com/NamSangwon/UnrealEngine4_Practice/assets/127469500/f0741395-9f19-4e9d-afc7-6e62f346ad69)

---


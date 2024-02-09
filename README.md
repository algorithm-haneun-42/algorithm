# algorithm study

## 문제 제출 방법
1. git clone 으로 해당 레파지토리 복사
2. 해당 회차의 폴더에 개인 이름으로 폴더 생성
3. 문제 번호를 제목으로 소스코드를 업로드
4. git fetch -> git pull 이후 git push
5. 남의 폴더 건들시 죽음

## rule
1. 월요일 목요일 15~16시 모임 (추후 수정 가능)
2. 불참시 컴포즈 커피 전원에게 사야함 (아프면 병원 진단서 필요, 8촌 이내의 경조사, 멤버 다수의 동의를 얻은 사유)
3. 모임 동안 풀어온 문제를 리뷰(코드에 대해서가 아닌 해결 과정 리뷰)
4. 리뷰는 발표 형식이며, 발표자는 그 시간에 랜덤으로 결정함
5. 모임마다 백준에서 세 문제를 풀어야 하며, 문제는 이전 문제들의 리뷰가 끝나고 결정
6. 문제는 반드시 해결할 필요는 없으나, 해결과정이 담긴 결과물은 남겨져있어야 함
7. 없을 시 죽음

### 참고 - 터미널로 컴파일 시 한번에 컴파일 + 실행 + a.out 자동삭제 방법
@ 해당 회차의 본인 폴더 위치에서만 가능합니다. @
1. vim ~./zshrc 명령어를 통해 들어갑니다.
2. alias를 생성합니다. (4, 5번 중 해당하는 대로 작성)
3. c의 경우 : alias ccc="../../.cc.sh"
4. cpp의 경우 : alias cpp="../../.cpp.sh"
5. 나간 후에 source ~/.zshrc 명령어
6. 이제 컴파일을 할 때 c는 ccc로 cpp는 cpp로 컴파일 합니다.
7. 예시) cpp 4949_world.cpp
8. 추가적으로 fsanitize 옵션이나 -g 옵션도 사용가능합니다.
   
---
## 문제 목록
#### 403 forbidden이 뜰 경우에는 주소창 더블클릭 후 https를 http로 바꿔봅니다.

[바킹독 블로그](https://blog.encrypted.gg/category/%EA%B0%95%EC%A2%8C/%EC%8B%A4%EC%A0%84%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98?page=2)

[백준 문제집](https://www.acmicpc.net/workbook/by/BaaaaaaaaaaarkingDog)

### 2024-02-15 8회차 : BFS, DP

메인 4개, 보너스 4개

[골드 3] wall_2206 : [벽 부수고 이동하기](https://www.acmicpc.net/problem/2206)

[실버 1] wine_2156 : [포도주 시식](https://www.acmicpc.net/problem/2156)

[실버 1] ascent_11057 : [오르막 수](https://www.acmicpc.net/problem/11057)

[골드 5] lcs_9251 : [LCS](https://www.acmicpc.net/problem/9251)

[골드 3] make_bridge_2146 : [다리 만들기(보너스)](https://www.acmicpc.net/problem/2146)

[골드 5] coin2_2294 : [동전 2(보너스)](https://www.acmicpc.net/problem/2294)

[골드 4] tile_2133 : [타일 채우기(보너스)](https://www.acmicpc.net/problem/2133)

[골드 3] descent_1520 : [내리막 길(보너스)](https://www.acmicpc.net/problem/1520)

### 2024-02-08 7회차 : DP
[DP 개념 강의](https://youtu.be/5leTtB3PQu0?si=zJODfZ1cvduEbdHv)

[실버 3] plus_123_9095 : [1, 2, 3 더하기](https://www.acmicpc.net/problem/9095)

[실버 1] make_one_12852 : [1로 만들기 2](https://www.acmicpc.net/problem/12852)

[실버 1] sticker_9465 : [스티커](https://www.acmicpc.net/problem/9465)

[골드 5] password_cord_2011 : [암호코드(보너스)](https://www.acmicpc.net/problem/2011)

### 2024-02-05 6회차 : BFS+

[실버 1] 2468_safety_area : [안전영역](https://www.acmicpc.net/problem/2468)

[실버 1] 2667_complex_number : [단지번호붙이기](https://www.acmicpc.net/problem/2667)

[골드 4] 2573_iceberg : [빙산](https://www.acmicpc.net/problem/2573)

[골드 3] 1600_monkey_knight : [말이 되고 싶은 원숭이(보너스)](https://www.acmicpc.net/problem/1600)

### 2024-01-29 5회차 : BFS
* 기업설명회 이슈로 목요일은 4시
  
[BFS 개념 강의(필수시청)](https://www.youtube.com/watch?v=ftOmGdm95XI&t=3s)

[실버 2] 1012_cabage : [유기농 배추](https://www.acmicpc.net/problem/1012)

[실버 1] 7562_knight : [나이트의 이동](https://www.acmicpc.net/problem/7562) 

[골드 5] 7569_tomato : [토마토](https://www.acmicpc.net/problem/7569)

[골드 4] 13913_hide : [숨바꼭질 4(보너스)](https://www.acmicpc.net/problem/13913)

### 2024-01-25 4회차 : 스택
* 문제 소스 변경 (바킹독 문제집)
  
[스택 개념 강의](https://youtu.be/cdjjk-ryPKc)

[실버 4] 4949_world : [균형잡힌 세상](https://www.acmicpc.net/problem/4949)

[실버 4] 2164_goodword : [좋은 단어](https://www.acmicpc.net/problem/3986) 

[실버 2] 10799_stealstick : [쇠막대기](https://www.acmicpc.net/problem/10799)

[골드 5] 2504_parentheses : [괄호의 값(보너스)](https://www.acmicpc.net/problem/2504)

### 2024-01-22 3회차 : 큐, 덱
[실버 4] 10866_deque : [덱](https://www.acmicpc.net/problem/10866)
- 단, 라이브러리를 사용하지 않고 덱을 직접 구현해야 함

[실버 4] 2164_card2 : [카드2](https://www.acmicpc.net/problem/2164) 

[실버 3] 1966_printerqueue : [프린터 큐](https://www.acmicpc.net/problem/1966) 

[골드 4] 3078_goodfriend : [좋은 친구(보너스)](https://www.acmicpc.net/problem/3078)

### 2024-01-18 2회차 : 그리디
[브론즈 1] 4796_camping : [캠핑](https://www.acmicpc.net/problem/4796) 

[실버 4] 11047_coin : [동전 0](https://www.acmicpc.net/problem/11047) 

[실버 1] 1931_meetingroom : [회의실 배정](https://www.acmicpc.net/problem/1931) 

[골드 3] 13904_assignment : [과제(보너스)](https://www.acmicpc.net/problem/13904) 

### 2024-01-15 1회차 : 완전 탐색
[브론즈 1] 2309번 : [일곱 난쟁이](https://www.acmicpc.net/problem/2309)

[실버 3] 2503번 : [숫자 야구](https://www.acmicpc.net/problem/2503)

[실버 2] 1182번 : [부분 집합의 합](https://www.acmicpc.net/problem/1182)

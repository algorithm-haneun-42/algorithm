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

### 2024-04-25 24회차 : 랜덤문제풀이

[레벨 2] magical_elebator : [마법의 엘리베이터](https://school.programmers.co.kr/learn/courses/30/lessons/148653)

[레벨 2] cantor_bit_array : [유사 칸토어 비트열](https://school.programmers.co.kr/learn/courses/30/lessons/148652)

[레벨 2] archery_competition : [카카오 기출문제 : 양궁 대회](https://school.programmers.co.kr/learn/courses/30/lessons/92342)

### 2024-04-25 24회차 : 랜덤문제풀이

[레벨 2] tictactoe : [혼자서 하는 틱택토](https://school.programmers.co.kr/learn/courses/30/lessons/160585)

[레벨 2] find_big_number_behind : [뒤에 있는 큰 수 찾기](https://school.programmers.co.kr/learn/courses/30/lessons/154539)

[레벨 2] emoticon_sale_event : [(보너스)카카오 기출문제 : 이모티콘 할인행사](https://school.programmers.co.kr/learn/courses/30/lessons/150368)

### 2024-04-15 23회차 : 기출문제풀이

[레벨 2] oil_drilling : [pccp 기출문제 : 석유 시추](https://school.programmers.co.kr/learn/courses/30/lessons/250136)

[레벨 2] analog_clock : [pccp 기출문제 : 아날로그 시계](https://school.programmers.co.kr/learn/courses/30/lessons/250135)

[레벨 3] move_cart : [pccp 기출문제 : 수레 움직이기](https://school.programmers.co.kr/learn/courses/30/lessons/250134)

[레벨 3] select_dice : [카카오 기출문제 : 주사위 고르기](https://school.programmers.co.kr/learn/courses/30/lessons/258709)

### 2024-04-11 22회차 : 다익스트라

[다익스트라 개념강의](https://www.youtube.com/watch?v=o9BnvwgPT-o&list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY&index=30&t=1049s)

[골드 5] get_minimum_1916 : [최소비용 구하기](https://www.acmicpc.net/problem/1916)

[골드 4] algospot_1261 : [알고스팟](https://www.acmicpc.net/problem/1261)

[골드 3] party_1238 : [파티](https://www.acmicpc.net/problem/1238)

[골드 2] hoseok_the_captain_of_alley_20183 : [골목 대장 호석 - 효율성 2](https://www.acmicpc.net/problem/20183)

### 2024-04-08 21회차 : 플로이드

[플로이드 개념강의](https://www.youtube.com/watch?v=dDDy2bEZRA8)

[골드 4] seokang_ground_14938 : [서강그라운드](https://www.acmicpc.net/problem/14938)

[골드 4] exercise_1956 : [운동](https://www.acmicpc.net/problem/1956)

[골드 2] floyd_11780 : [플로이드 2](https://www.acmicpc.net/problem/11780)

[골드 2] curious_minho_1507 : [궁금한 민호](https://www.acmicpc.net/problem/1507)


### 2024-04-04 20회차 : 최소 신장 트리

[최소 신장 트리 개념강의](https://www.youtube.com/watch?v=4wA3bncb64E)

[실버 4] sanguen_journey_9372 : [상근이의 여행](https://www.acmicpc.net/problem/9372)

[골드 4] minimum_spaning_tree_1197 : [최소 스패닝 트리](https://www.acmicpc.net/problem/1197)

[골드 4] city_split_plan_1647 : [도시 분할 계회](https://www.acmicpc.net/problem/1647)

[골드 2] electricity_shortage_10423 : [전기가 부족해](https://www.acmicpc.net/problem/10423)


### 2024-04-01 19회차 : 위상 정렬

[위상 정렬 개념강의](https://www.youtube.com/watch?v=Th-gLZUrd04)

[골드 3] line_up_2252 : [줄 세우기](https://www.acmicpc.net/problem/2252)

[골드 3] music_program_2623 : [음악프로그램](https://www.acmicpc.net/problem/2623)

[골드 3] hoseok_21276 : [계보 복원가 호석](https://www.acmicpc.net/problem/21276)

[골드 2] workbook_1766 : [문제집](https://www.acmicpc.net/problem/1766)

### 2024-03-21 18회차 : 이진 탐색 트리

[이진 탐색 트리 개념강의](https://www.youtube.com/watch?v=IKnjzmyk70U&t=1308s)

[골드 4] doubly_priority_queue_7662 : [이중 우선순위 큐](https://www.acmicpc.net/problem/7662)

[골드 2] jewel_thief_1202 : [보석 도둑](https://www.acmicpc.net/problem/1202)

[골드 4] problem_recommend_system_v1_21939 : [문제 추천 시스템 Version 1](https://www.acmicpc.net/problem/21939)

[플래티넘 5] binary_search_tree_1539 : [이진 검색 트리](https://www.acmicpc.net/problem/1539)

### 2024-03-18 17회차 : 그래프

[그래프 개념강의](https://www.youtube.com/watch?v=9iI6fuOLiLg)

[실버 3] virus_2606 : [바이러스](https://www.acmicpc.net/problem/2606)

[실버 1] find_path_11403 : [경로 찾기](https://www.acmicpc.net/problem/11403)

[골드 5] vote_chairman_2660 : [회장뽑기](https://www.acmicpc.net/problem/2660)

[골드 4] lie_1043 : [거짓말](https://www.acmicpc.net/problem/1043)

### 2024-03-14 16회차 : 우선순위 큐

[우선순위 큐 개념강의](https://youtube.com/watch?v=_9mbqoF9qzc)

[실버 2] minimum_heap_1927 : [최소 힙](https://www.acmicpc.net/problem/1927)

[실버 2] Nth_largest_number_2075 : [N번째 큰 수](https://www.acmicpc.net/problem/2075)

[실버 2] maximum_heap_11279 : [최대 힙](https://www.acmicpc.net/problem/11279)

[골드 4] merge_file_3_13975 : [파일 합치기 3](https://www.acmicpc.net/problem/13975)

### 2024-03-11 15회차 : dp 복습

[실버 3] fibonacci_function_1003 : [피보나치 함수](https://www.acmicpc.net/problem/1003)

[실버 3] resign_14501 : [퇴사](https://www.acmicpc.net/problem/14501)

[골드 3] color_circle_2482 : [색상환](https://www.acmicpc.net/problem/2482)

### 2024-03-07 14회차 : BFS 복습

[BFS 개념 강의](https://www.youtube.com/watch?v=ftOmGdm95XI&t=3s)

[실버 1] get_area_2583 : [영역 구하기](https://www.acmicpc.net/problem/2583)

[실버 1] startlink_5014 : [스타트링크](https://www.acmicpc.net/problem/5014)

[골드 3] break_wall_14442 : [벽 부수고 이동하기 2](https://www.acmicpc.net/problem/14442)

[골드 3] cheese_2638 : [치즈(보너스)](https://www.acmicpc.net/problem/2638)

### 2024-03-04 13회차 : 해시

[해시 개념 강의](https://www.youtube.com/watch?v=1-k-D2AYY0I)

[실버 4] find_password_17219 : [비밀번호 찾기](https://www.acmicpc.net/problem/17219)

[실버 3] fashionist_shin_9375 : [패션왕 신해빈](https://www.acmicpc.net/problem/9375)

[실버 3] Number_of_different_substring_strings_11478 : [서로 다른 부분 문자열의 개수](https://www.acmicpc.net/problem/11478)

[골드 5] infinite_sequence_1351 : [무한 수열(보너스)](https://www.acmicpc.net/problem/1351)

### 2024-02-29 12회차 : 백트래킹

[백트래킹 개념 강의](https://www.youtube.com/watch?v=Enz2csssTCs)

[실버 3] NM1_15649 : [N과 M(1)](https://www.acmicpc.net/problem/15649)

[실버 2] NM12_15666 : [N과 M(12)](https://www.acmicpc.net/problem/15666)

[골드 4] NQueen_9663 : [N-Queen](https://www.acmicpc.net/problem/9663)

[골드 5] make_password_1759 : [암호 만들기(보너스)](https://www.acmicpc.net/problem/1759)

### 2024-02-26 11회차 : 시뮬레이션

[시뮬레이션 개념 강의](https://www.youtube.com/watch?v=jZwf4OPlhtk)

[실버 1] truck_13335 : [트럭](https://www.acmicpc.net/problem/13335)

[실버 1] insert_operator_14888 : [연산자 끼워넣기](https://www.acmicpc.net/problem/14888)

[실버 1] start_and_link_14889 : [스타트와 링크](https://www.acmicpc.net/problem/14889)

[골드 3] baby_shark_16236 : [아기 상어](https://www.acmicpc.net/problem/16236)

### 2024-02-22 10회차 : 투 포인터

[투 포인터 개념 강의](https://www.youtube.com/watch?v=I_0aAKzu0m8&t=7s)

[실버 1] rotate_sushi_2531 : [회전 초밥](https://www.acmicpc.net/problem/2531)

[실버 1] hate_dup_20922 : [겹치는 건 싫어](https://www.acmicpc.net/problem/20922)

[골드 5] longest_even_continuous_partial_sequence_22862 : [가장 긴 짝수 연속한 부분 수열](https://www.acmicpc.net/problem/22862)

[골드 3] lets_make_snowman_20366 : [같이 눈사람 만들래?](https://www.acmicpc.net/problem/20366)

### 2024-02-19 9회차 : 이분탐색

[이분탐색 개념 강의](https://www.youtube.com/watch?v=3TkaOKHxHnI)

[실버 4] find_num_1920 : [수 찾기](https://www.acmicpc.net/problem/1920)

[실버 4] num_card_10816 : [숫자 카드 2](https://www.acmicpc.net/problem/10816)

[실버 2] cut_LAN_cable_1654 : [랜선 자르기](https://www.acmicpc.net/problem/1654)

[골드 5] solution_2467 : [용액](https://www.acmicpc.net/problem/2467)

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

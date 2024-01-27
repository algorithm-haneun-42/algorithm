# 공백 미포함
---

## scanf

## cin

- #include <iostream>
- 표준 입력 버퍼에서 개행 문자를 제외한 값을 가져온다.
- 공백이나 개행 입력 시 공백 이전까지의 값만 결과로 받아들인다.
- 개행 문자를 입력 버퍼에 남겨둔다.

```jsx
// 정수
int n;
cin >> n;

// 문자열
string str;
cin >> str;
```

# 공백 포함
---

## cin.get()

<aside>
💡 istream& get(char* s, streamsize n, char delim);

</aside>

## cin.getline()

<aside>
💡 cin.getline(변수 주소, 최대 입력 가능 문자수, 종결 문자);

💡 cin.getline(char str, streamsize n);

💡 cin.getline(char str, streamsize n, char dlim);

</aside>

- #include <istream>
- 문자 배열이며 마지막 글자가 ‘\0’(terminator)인 c-string을 입력 받는데 사용
    - string 타입 사용 불가
- n-1개의 문자 개수만큼 읽어와 str에 저장 (n번째 문자는 NULL(‘\0’)로 바꾼다.)
- 세 번째 인자인 delim은 별도로 지정해주지 않으면 엔터(‘\n’)로 인식
    - delim을 지정해주면 그 제한자(delim)문자 직전까지 읽어서 str에 저장

## getline()

<aside>
💡 getline(입력스트림 오브젝트, 문자열을 저장할 string객체, 종결 문자);

💡 getline(istream& is, string str);

💡 getline(istream& is, string str, char dlim);

</aside>

- #include <iostream>
    - #include <string>
- 최대 문자 수를 입력하지 않아도 됨.
- 원하는 구분자(delimiter)를 만날 때 까지 모든 문자열을 입력 받아 하나의 string 객체에 저장
    - 세 번째 인자인 delim은 별도로 지정해주지 않으면 엔터(‘\n’)로 인식

```jsx
int n;
string str;

getline(cin, str);
```

- 주의! (cin과 getline()을 함께 쓰는 경우)
    
    ```jsx
    int n;
    string str;
    
    cin >> n;
    getline(cin, str);
    ```
    
    위와 같은 상황을 보자. 위 코드대로 실행을 하면 n을 입력 받은 후 문자열을 입력받지 않고 바로 다음 코드로 넘어가게 된다. 이유는 버퍼에 정수 값을 입력한 뒤 누른 엔터(‘\n’)가 그대로 남아있어 getline()에 들어가기 때문이다. 이를 해결하기 위해 **cin.ignore()** 라는 함수를 사용할 수 있다.
    
    ```jsx
    int n;
    string str;
    
    cin >> n;
    cin.ignore();
    getline(cin, str);
    ```
    
    위와 같이 변경하면 cin.ingore()가 입력 버퍼의 모든 내용을 제거해주어 getline()이 정상적으로 동작할 수 있다.
    

### cin.ignore()

<aside>
💡 cin.ignore(읽어들일 문자의 개수, 종결 문자);
    
💡 cin.ignore(int n, char dlim);

</aside>

### 참고

[C++ 입력 함수 - cin, cin.get(), getline() - kwon | kwon's Blog](https://kyu9341.github.io/C-C/2020/01/17/C++getline()/)

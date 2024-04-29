#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    int flag = 0;
    
    while (l > 5){
        if (l % 5 == 3)
            flag = 1;
        l /= 5;
    }
    return answer;
}
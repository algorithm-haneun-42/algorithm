#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;

    for (const auto& innerVector : relation) {
        for (const std::string& str : innerVector) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
	cout << '\n';
    sort(relation.begin(), relation.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1]; // 두 번째 string으로 비교합니다.
    });
    for (const auto& innerVector : relation) {
        for (const std::string& str : innerVector) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    return answer;
}

int main(void) {
	vector<vector<string>> relation;
	relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
	solution(relation);
}
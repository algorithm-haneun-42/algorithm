#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
	stack<string> st;

    return answer;
}

int main()
{
	vector<vector<string>> subject = { {"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}};
	vector<string> ret = solution(subject);
	for(auto a: ret)
		cout << a << endl;
}
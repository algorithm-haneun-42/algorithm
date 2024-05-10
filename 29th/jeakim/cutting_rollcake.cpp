#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
	int st, end, mid = 0;
	int top_st[10001] = {0};
	int top[10001] = {0};

	for (int i = 0; i < topping.size(); i++){
		top[topping[i]]++;
		if (top[topping[i]] == 1)
			end++;
	}
	for (int i = 0; i < topping.size(); i++){
		if(top[topping[i]] == 1)
			end--;
		top[topping[i]]--;
		top_st[topping[i]]++;
		if (top_st[topping[i]] == 1)
			st++;
		if (st == end)
			answer++;
	}
    return answer;
}

int main()
{
	vector<int> topping = {1, 2, 1, 3, 1, 4, 1, 2};
	
	cout << solution(topping) << endl;

	return (0);
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> ans;
	auto it = find(sequence.begin(), sequence.end(), k);
	if ( it != sequence.end()) {
		ans.push_back(it-sequence.begin());
		ans.push_back(it-sequence.begin());
		return ans;
	}
	for(int len = 1; len <= sequence.size(); len++) {
		long long sum = 0;
		for(int i = 0; i < len; i++)
			sum += sequence[i];
		for(int i = len; i < sequence.size(); i++) {
			if (sum == k) {
				ans.push_back(i - len);
				ans.push_back(i - 1);
				return (ans);
			}
			sum = sum - sequence[i - len] + sequence[i];
		}
	}
    return ans;
}

int main(void) {
	vector<int> sequence = {1, 1, 1, 2, 3, 4, 5};
	int k = 5;
	vector<int> ans = solution(sequence, k);
	for(int a : ans)
		cout << a << ' ';
}
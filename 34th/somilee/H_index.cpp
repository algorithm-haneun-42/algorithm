#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cit) {
    sort(cit.begin(), cit.end());
	int n = cit.size();
	for(int i = n-1; i >= 0; i--) {
		if (n-i < cit[i] && n-i > cit[i-1])
			return n-i;
		if (n-i >= cit[i])
			return cit[i];
	}
	return cit[0];
}

int main(void) {
	vector<int> citations = {0,1,2};
	cout << solution(citations) <<'\n';
}
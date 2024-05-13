#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int ans;
	int tmp = 0;
	vector<int> num;
	cards.insert(cards.begin(), 0);
	for(int i = 1; i < cards.size(); i++) {
		if (cards[i] != 0) {
			int cnt = 0;
			int j = i;
			while (cards[j] != 0) {
				cout << cards[j] << '\n';
				int tmp = cards[j];
				cards[j] = 0;
				j = tmp;
				cnt++;
			}
			num.push_back(cnt);
		}
	}
	sort(num.begin(), num.end());
	int n = num.size();
	if (n < 2)
		return (0);
	ans = num[n-1] * num[n-2];
    return ans;
}

int main(void) {
	vector<int> cards;
	cards = {8,6,3,7,2,5,1,4};
	cout << solution(cards) << '\n';
}
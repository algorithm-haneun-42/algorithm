#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int ans = 0;
	for(int i = 0; i < name.length(); i++) {
		ans += min(name[i] - 'A', 26 - name[i] + 'A');
	}
	int i = 0;
	int c_move = 1000;
	while(i < name.length()) {
		int n = 0;
		if (name[i] == 'A') {
			while(name[i] == 'A' && i < name.length()) {
				n++;
				i++;
			}
			int a = i - n;
			int b = name.length() - i;
			if (a == 0) {
				n = b;
			}
			else n = min(2*(a-1) + 1 + (b-1), 1 + 2*(b-1) + 1 + (a-1));
			c_move = min(n, c_move);
		}
		i++;
	}
	if (c_move == 1000) {
		ans += name.length() - 1;
	}
	else ans += c_move;
    return ans;
}
int main(void) {
	cout << solution("AJEROENAA") << '\n';
	cout << solution("BAAAAA") << '\n';
	cout << solution("JEROEN") << '\n';
	
}

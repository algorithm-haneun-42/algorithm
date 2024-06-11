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
			if (a == 0)
				n = b;
			else n = min(2*(a-1) + 1 + (b-1), 1 + 2*(b-1) + 1 + (a-1));
			c_move = min(n, c_move);
			cout << "c_move = " << c_move << ", i = " << i << '\n';
		}
		i++;
	}
	c_move = min((int)name.length() - 1, c_move);
    return (ans + c_move);
}
int main(void) {
    cout << solution("BBBABBB") << endl;
}
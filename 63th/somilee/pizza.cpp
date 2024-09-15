#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int d,n;
stack<int> s;
queue<int> q;
int main(void) {
	cin >> d >> n;
	int tmp = 1000000001;
	for(int i = 0; i < d; i++) {
		int num; cin >> num;
		tmp = min(tmp, num);
		s.push(tmp);
	}
	for(int i = 0; i < n; i++) {
		int num; cin >> num;
		q.push(num);
	}
	while(!q.empty() && !s.empty()) {
		if(s.top() >= q.front())
			q.pop();
		s.pop();
	}
	if(!q.empty())
		cout << "0\n";
	else
		cout << s.size()+1 << "\n";
	return 0;
}

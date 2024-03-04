#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, string> m;
	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		string a, b;
		cin >> a >> b;
		m.insert(make_pair(a, b));
	}
	for (int i = 0; i < M; i++){
		string a;
		cin >> a;
		cout << m.find(a)->second << '\n';
	}
	return (0);
}

#include <iostream>
#include <queue>

using namespace std;

int check_friend(queue<string> q, string s)
{
	int cnt;

	cnt = 0;
	for (int i = 0; i < q.size(); i++)
	{
		if (s.size() == q.front().size())
			cnt ++;
		q.push(q.front());
		q.pop();
	}
	return (cnt);
}

int main()
{
	queue<string> q;
	int N;
	int K;
	string s;
	int cnt;
	int d;

	cin >> N >> K;
	cnt = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> s;
		cnt += check_friend(q, s);
		q.push(s);
	}
	for (int i = 0; i < N - K; i++)
	{
		cin >> s;
		cnt += check_friend(q, s);
		q.pop();
		q.push(s);
	}
	cout << cnt << endl;
	return (0);
}
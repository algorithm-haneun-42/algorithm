#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int find_maxIdx(queue<vector<int> > q, int N, int M)
{
	int max;
	int idx;

	max = q.front()[0];
	idx = 0;
	for (int i = 1; i < q.size(); i++)
	{
		q.push(q.front());
		q.pop();
		if (q.front()[0] > max){
			max = q.front()[0];
			idx = i;
		}
	}
	return (idx);
}

int printer_q(queue<vector<int> > q, int N, int M)
{
	int cnt;
	//int q_M;
	int idx;

	cnt = 0;
	//q_M = find_num(q, N, M);
	while (1)
	{
		idx = find_maxIdx(q, N, M);
		for (int i = 0; i < idx; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cnt++;
		if (q.front()[1] == 1)
			break;
		if (q.size() != 0)
			q.pop();
	}
	return (cnt);
}

int main()
{
	int K;
	int N;
	int M;
	int d;
	queue<vector<int> > q;
	vector<int> v;

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> d;
			v.push_back(d);
			if (j == M)
				v.push_back(1);
			else
				v.push_back(0);
			q.push(v);
			v.clear();
		}
		cout << printer_q(q, N, M) << endl;
		q = queue<vector<int> >();
	}
	return (0);
}
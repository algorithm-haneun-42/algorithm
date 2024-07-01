#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[4001];

int	check_three(vector<int> p)
{
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < v[p[0]].size(); i++){
		if (v[p[0]][i] == p[1])
			flag1 = 1;
		else if (v[p[0]][i] == p[2])
			flag2 = 1;
	}
	if (flag1 != 1 || flag2 != 1)
		return (0);
	for (int i = 0; i < v[p[1]].size(); i++){
		if (v[p[1]][i] == p[2])
			return (1);
	}
	return (0);
}

int	make_three(int n)
{
	int arr[n];
	int temp[n];
	int min_cnt = n * 3;

	for (int i = 1; i <= n; i++)
		arr[i - 1] = i;
	for (int i = 0; i < n - 3; i++)
		temp[i] = 0;
	for (int i = n - 3; i < n; i++)
		temp[i] = 1;
	do {
		vector<int> s;
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (temp[i] == 1)
				s.push_back(arr[i]);
		}
		if (check_three(s) == 1)
		{
			for (int i = 0; i < 3; i++){
				cnt += v[s[i]].size();
			}
			cnt -= 6;
			min_cnt = min(cnt, min_cnt);
		}
		s.clear();
	} while (next_permutation(temp, temp + n));
	return (min_cnt);
}

int main()
{
	int	n, m;
	int	cnt, min;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cnt = make_three(n);
	if (cnt == n * 3)
		cnt = -1;
	cout << cnt << endl;
}

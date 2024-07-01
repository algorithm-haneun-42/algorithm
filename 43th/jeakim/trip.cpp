#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v[301];
int arr[301][301] = {0};
int n, m, k;

int	find_biggest(int st)
{
	int max_num = 0;
	int max_node;
	for (int i = st + 1; i <= n; i++){
		if (max_num < arr[st][i])
			max_node = i;
		max_num = max(max_num, arr[st][i]);
	}
	return (max_node);
}

int main()
{
	int tm = 0;
	int rst = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		arr[a][b] = c;
	}
	int st = 1;
	int eat = 0;
	while (st < n){
		int dst = find_biggest(st);
		
		st = dst;
	}
	return (0);
}

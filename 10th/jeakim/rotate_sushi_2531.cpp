#include <iostream>
#include <cmath>

using namespace std;

int count_kind(int sushi[30000], int N, int d, int k, int c)
{
	int start_idx = 0;
	int max_cnt = 0;

	for (int start_idx = 0; start_idx <= N - k; start_idx++){
		int kind[3001] = {0};
		int cnt = 0;

		for (int sub_idx = start_idx; sub_idx < start_idx + k; sub_idx++){
			if(kind[sushi[sub_idx]] != 0)
				continue;
			kind[sushi[sub_idx]]++;
			cnt++;
		}
		if(kind[c] != 0)
			max_cnt = max(max_cnt, cnt);
	}
	for (int start_idx = N - k + 1; start_idx < N; start_idx++){
		int kind[3001] = {0};
		int cnt = 0;

		for (int sub_idx = start_idx; sub_idx < N; sub_idx++){
			if (kind[sushi[sub_idx]] != 0)
				continue;
			kind[sushi[sub_idx]]++;
			cnt++;
		}
		for (int sub_idx = 0; sub_idx < k - (N - start_idx); sub_idx++){
			if (kind[sushi[sub_idx]] != 0)
				continue;
			kind[sushi[sub_idx]]++;
			cnt++;
		}
		if(kind[c] != 0)
			max_cnt = max(max_cnt, cnt);
	}
	return (max_cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, d, k, c;
	int sushi[30000];
	int coupon_idx;

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
		cin >> sushi[i];
	cout << count_kind(sushi, N, d, k, c) << endl;
	return (0);	
}

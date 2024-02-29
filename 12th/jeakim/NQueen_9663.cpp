#include <iostream>

using namespace std;

int check(int N, int arr[15], int idx)
{
	for (int i = 0; i < idx; i++){
		if (arr[idx] == arr[i])
			return (0);
		if (arr[idx] - arr[i] == idx - i)
			return (0);
		if (arr[i] - arr[idx] == idx - i)
			return (0);
	}
	return (1);
}

void queen(int N, int arr[15], int idx, int &cnt)
{
	if (idx == N){
		cnt++;
		return ;
	}
	for (int i = 0; i < N; i++){
		arr[idx] = i;
		if (check(N, arr, idx) == 1)
			queen(N, arr, idx + 1, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	int arr[15] = {0};
	int cnt = 0;

	cin >> N;
	queen(N, arr, 0, cnt);
	cout << cnt << endl;
}

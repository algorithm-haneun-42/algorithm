#include <iostream>
#include <algorithm>

using namespace std;

void back(int N, int M, int idx, int num[8], int arr[8], int  pst)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return ;
	}
	for(int i = pst; i < N; i++)
	{
		num[idx] = arr[i];
		back(N, M, idx + 1, num, arr, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int num[8]; //출력할 숫자
	int arr[8]; //입력받은 숫자
	int dup[10001] = {0}; //중복 제거
	int cnt = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		int k;
		cin >> k;
		if (dup[k] != 0)
			continue;
		arr[cnt] = k;
		dup[k] = 1;
		cnt++;
	}
	sort(arr, arr + cnt);
	back(cnt, M, 0, num, arr, 0);
}

#include <iostream>
#include <cmath>

using namespace std;

int max_len(int N, int K, int arr[1000000])
{
	int max_len = 0;

	for (int st = 0; st < N; st++){
		int first = st;
		int cnt = 0;
		int len = 0;
		for (int sub = st; sub < N && cnt <= K; sub++){
			if (cnt == 0 && arr[sub] % 2 != 0)
				first = sub;
			if (arr[sub] % 2 != 0)
				cnt++;
			else
				len++;
		}
		max_len = max(max_len, len);
		st = first;
	}
	return (max_len);
}

int main()
{
	int N, K;
	int s[1000000];

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	cout << max_len(N, K, s) << endl;

	return (0);
}

#include <iostream>
#include <cmath>

using namespace std;

int count_max(int N, int K, int arr[200000])
{
	int max_len = 0;
	
	for (int st = 0; st < N; st++){
		int dup[100001] = {0};
		int len = 0;
		for (int sub = st; sub < N; sub++){
			dup[arr[sub]]++;
			if (dup[arr[sub]] > K)
				break;
			len++;
		}
		max_len = max(max_len, len);
	}
	return (max_len);
}

int main()
{
	int N, K;
	int arr[200000];

	cin >>  N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << count_max(N, K, arr) << endl;

	return (0);
}

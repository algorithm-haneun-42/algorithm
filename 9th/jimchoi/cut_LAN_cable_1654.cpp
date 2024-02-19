#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	long long LAN[N];
	for(int i = 0; i < N; i++)
		cin >> LAN[i];
	sort(LAN, LAN + N);

	long long max = *max_element(LAN, LAN + N);
	long long L = 1;
	long long R = max;
	long long ans = 0;
	long long cnt;
	while(L <= R)
	{
		long long mid = (L+R)/2;
		cnt = 0;
		for (int i=0; i < N; i++)
			cnt += LAN[i] / mid;
		if(cnt >= M)
		{
			L = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else
			R = mid - 1;
	}
	cout << ans << endl;
    return 0;

}
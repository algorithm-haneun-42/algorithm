#include <iostream>

using namespace std;

void back(int N, int M, int idx, int dup[9], int num[8])
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << num[i] << ' ';
		cout << '\n';
		return ;
	}
	for(int i = 1; i <= N; i++)
	{
		if(dup[i] == 0)
		{
			num[idx] = i;
			dup[i] = 1;
			back(N, M, idx + 1, dup, num);
			dup[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int dup[9] = {0}; //중복체크
	int num[8]; //실제 숫자

	cin >> N >> M;
	back(N, M, 0, dup, num);
}

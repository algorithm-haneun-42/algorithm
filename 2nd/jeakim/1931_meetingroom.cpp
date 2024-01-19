#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int count_max(int N, vector<vector<int> > &met, int idx)
{
	int i;

	if (idx == N - 1)
		return (1);
	i = idx + 1;
	while (i < N && met[idx][1] > met[i][0])
		i++;
	if (i == N)
		return (0);
	return (count_max(N, met, i) + 1);
}

int main()
{
    int N;
    int n;
	int max;
    vector<vector<int> > met;
    vector<int> m;

    //입력
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        m.push_back(n);
        cin >> n;
        m.push_back(n);
        met.push_back(m);
        m.clear();
    }
    //시작 시간 기준 정렬
    sort(met.begin(), met.end());
	//
	max = 0;
	for (int i = 0; i < N; i++)
	{
		n = count_max(N, met, i);
		if (n > max)
			max = n;
	}
    cout << max << endl;
    return (0);
}

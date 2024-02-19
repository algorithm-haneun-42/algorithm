#include <iostream>
#include <algorithm>
using namespace std;

int N, M;


void binary_search(int *arr, int L, int R, int num)
{
	int i;
	while(1)
	{
		int M = (L+R)/2;
		if (arr[L] == num) 
		{
			i = 0;
			while(arr[i+L] == num)
			{
                i++;
            }
			cout << i<< ' ';
			return;
		}
		else if (arr[R] == num)
		{
			i = 0;
			while(arr[R-i] == num)
			{
                i++;
            }
			cout << i<< ' ';
			return;
		}
		if(arr[M] < num)
			L = M+1;
		else
			R = M;
		if (L >= R)
		{
			cout << 0 << ' ';
            return;
		}
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int card[N];
	for(int i=0; i<N; i++)
	{
		cin >> card[i];
	}
	cin >> M;
	int arr[M];
	for(int i=0; i<M; i++)
    {
		cin >> arr[i];
	}
	sort(card, card+N);

	for(int i=0; i<M; i++)
		binary_search(card, 0, N-1, arr[i]);

}
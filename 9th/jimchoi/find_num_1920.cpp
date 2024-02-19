#include <iostream>
#include <algorithm>
using namespace std;

int n1, n2;


void binary_search(int *arr, int L, int R, int num)
{
	while(1)
	{
		int M = (L+R)/2;
		if (arr[M] == num || arr[L] == num || arr[R] == num) 
		{
			cout << 1 << '\n';
			return;
		}
		if(arr[M] < num)
		    L = M+1;
		else
		    R = M-1;
		if (L > R)
		{
			cout << 0 << '\n';
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
	cin >> n1;
	int arr1[n1];
	for(int i=0; i<n1; i++)
	{
		cin >> arr1[i];
	}
	sort(arr1, arr1+n1);

	cin >> n2;
	int arr2[n2];
	for(int i=0; i<n2; i++)
    {
		cin >> arr2[i];
	}

	for(int i=0; i<n2; i++)
    {
		binary_search(arr1, 0, n1-1, arr2[i]);
	}

}
//ㅠㅠ

#include <stdio.h>

void f(int arr[], int idx);

int n;
int s;
int count;

int main()
{
	int i;
	int j;
	int sum = 0;
	scanf("%d %d", &n, &s);

    int arr[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}   
	// for(i = 0; i < n; i++)
	// {
	// 	printf("%d ", arr[i]);
	// }

	f(arr, 0);
	printf("%d", count);
}
void f(int arr[], int idx)
{
	int sum = 0;
	if (idx == n) // 깊이까지 다 더했는데 정답이 안나옴
		return;
	for(int i = idx; i < n; i++)
	{
		sum += arr[i];
		if (sum > s)
		{
			sum -= arr[i];
			continue;
		}
		if (sum == s)
		{
			count++;
			// f(arr, idx + 1);
		}

		
	}
	f(arr, idx + 1);
}
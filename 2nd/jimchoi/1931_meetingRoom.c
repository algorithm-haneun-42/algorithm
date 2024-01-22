#include <stdio.h>
#include <stdlib.h>

int maxRooms(int arr[][2], int n);

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	if (num1 == num2)
	{
		int num3 = *((int *)(a+4));
		int num4 = *((int *)(b+4));
		if (num3 < num4)
			return -1;
		if (num3 >= num4)
			return 1;
	}
	return 0;
	}

	int main(void) {

	int n;
	scanf("%d", &n);
	int arr[n][2];

	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i][1], &arr[i][0]);
		
	qsort(arr, n, sizeof(arr[0]),compare);

	printf("%d", maxRooms(arr, n));
	}

	int maxRooms(int arr[][2], int n) {
	int max = 0;
	int time = -1;
	for (int i = 0; i < n; i++) {
	if (arr[i][1] >= time) {
		max++;
		time = arr[i][0];
	}
	}
	return (max);
}



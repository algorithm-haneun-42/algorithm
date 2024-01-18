//숫자 야구
#include <stdio.h>

int numArr[] = {1,2,3,4,5,6,7,8,9};
int n;
char result[3];

int checkStrike(int arr[3], int strike)
{

	int s = 0;
	// for(int j=0; j < n; j++)
	// {
		for(int i = 0; i < 3; i++)
		{
			if(arr[i] == numArr[i])
				s++;
		}
		if (s != strike)
			return 0;
	// }
	return 1;
}
int checkBall(int arr[3], int ball)
{
	int b = 0;
	// for(int j=0; j < n; j++)
	// {
		for(int i = 0; i < 3; i++)
		{
			for(int k=0; k < 3; k++)
				{
					if(numArr[i] == arr[k] && k != i)
						b++;
				}
		}
		if (b != ball)
			return 0;
	// }
	return 1;
}


void swap(int *a, int *b ){  //값을 이동하기 위한 함수
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


void permutation(int **arr, int **q, int depth, int n){ //재귀함수 함수
    if( 3 == depth)
	{ 
		for(int j=0; j<n;)
		{
			if (checkStrike(arr[j], q[j][0]) == 0)
				return; 
			if(checkBall(arr[j], q[j][1]) == 0)
				return;

		}
			for(int i=0; i<3; i++)
			{
				result[i] = arr[i] + '0';
			}

			printf("%s\n", result);
			return;
    }
    for(int i=depth; i<9; i++){
        swap(&numArr[i], &numArr[depth]);
        permutation(arr, q, depth+1, n);
        swap(&numArr[i], &numArr[depth]); //배열을 재자리로 보내주기 >위함
    }
}
void makeNum(int **arr, int n, int tmp)
{
	int i= 0;

	while(i < n)
	{
		arr[i][0]= tmp / 100; 
		arr[i][1]= (tmp / 10) - arr[i][0] * 10; 
		arr[i][2]= tmp % 10; 
		i++;
	}
}
int main()
{

	scanf("%d", &n);
	int question[n][2];
	int arr[n][3];
	int i = 0;
	int tmp;
	while(i < n)
	{
		scanf("%d %d %d", &tmp, &question[i][0], &question[i][1]);
		
			arr[i][0]= tmp / 100; 
			arr[i][1]= (tmp / 10) - arr[i][0] * 10; 
			arr[i][2]= tmp - (arr[i][0] * 100 + arr[i][1] * 10); 
			
		i++;
	}
	permutation(arr, question, 0, n);
}


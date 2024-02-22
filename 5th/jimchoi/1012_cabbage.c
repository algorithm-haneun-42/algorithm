
#include <stdio.h>
#include <stdlib.h>

void bfs(int x, int y);

typedef struct	__node {
	int            x;
	int            y;//앞
	int			vis;
}	Q;

int arr[50][50] = {0,};
int vis[50][50] = {0,};
Q	q[2500];
int T, M, N, K, cnt;

int main()
{
	int x; 
	int y;
	int i = 0;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d %d", &M, &N, &K);
        while(i < K)
		{
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
			i++;
		}
		i = 0;
		for(i=0; i< M; i++)
		{
			for(int j=0; j< N; j++)
			{
				if(arr[i][j] == 0 && vis[j][j] == 0)
				{
					q[]
					bfs(x, y);
					cnt++;
				}
			}
		}
	}

}

void bfs(int x, int y)
{
	vis[x][y] = 1;

}


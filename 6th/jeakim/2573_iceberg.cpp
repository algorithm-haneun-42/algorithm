#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int count_year(int board[300][300], queue<pair<int, int> > que, int N, int M)
{
	int year = 0;
	int area;

	pair<int, int> cur = que.front();
	que.pop();
	while(!que.empty()){
		area = 0;
		
	}
	return (year);
}

int main()
{
	int N, M;
	int board[300][300];
	queue <pair<int, int> > que;

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> board[i][j];
			if (board[i][j] > 0)
				que.push(make_pair(i, j));
		}
	}
	int year = 0;
	while (!que.empty()){
		
	}
	cout << year << endl;
	return (0);
}
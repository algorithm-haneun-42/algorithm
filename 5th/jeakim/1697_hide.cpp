#include <iostream>
#include <queue>

using namespace std;

// void print_visit(int visit[100000], int N, int K)
// {
// 	for (int i = 0; i < K * 2; i++)
// 		cout << visit[i] << ' ';
// }

int main()
{
	int N, K;
	queue<int> que;
	int visit[100000];

	cin >> N >> K;
	for (int i = 0; i < 100000; i++)
		visit[i] = -1;
	que.push(N);
	visit[N] = 0;
	while(!que.empty()){
		int cur = que.front();
		if (cur == K)
			break;
		que.pop();
		int plus = cur + 1;
		if (visit[plus] == -1 && 0 <= plus && plus < 100000){
			que.push(plus);
			visit[plus] = visit[cur] + 1;
		}
		int minus = cur - 1;
		if (visit[minus] == -1 && 0 <= minus && minus < 100000){
			que.push(minus);
			visit[minus] = visit[cur] + 1;
		}
		int multi = cur * 2;
		if (visit[multi] == -1 && 0 <= multi && multi < 100000){
			que.push(multi);
			visit[multi] = visit[cur] + 1;
		}
	}
	//print_visit(visit, N, K);
	cout << endl << visit[que.front()] << endl;
	return (0);
}

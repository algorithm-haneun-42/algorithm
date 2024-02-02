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
	int visit[100000] = {0};

	cin >> N >> K;
	que.push(N);
	visit[N] = 1;
	while(!que.empty()){
		int cur = que.front();
		que.pop();
		if (cur == K)
			break;
		int plus = cur + 1;
		if (0 <= plus && plus < 100000 && visit[plus] == 0){
			que.push(plus);
			visit[plus] = visit[cur] + 1;
		}
		int minus = cur - 1;
		if (0 <= minus && minus < 100000 && visit[minus] == 0){
			que.push(minus);
			visit[minus] = visit[cur] + 1;
		}
		int multi = cur * 2;
		if (0 <= multi && multi < 100000 && visit[multi] == 0){
			que.push(multi);
			visit[multi] = visit[cur] + 1;
		}
	}
	//print_visit(visit, N, K);
	cout << visit[K] - 1 << endl;
	return (0);
}

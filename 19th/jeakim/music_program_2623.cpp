#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topology(int n, vector<int> g[1001], int idg[1001])
{
	queue<int> q;
	queue<int> num;

	for (int i = 1; i <= n; i++)
		if (idg[i] == 0)
			q.push(i);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		num.push(cur);
		for (int nxt : g[cur]){
			idg[nxt]--;
			if(idg[nxt] == 0)
				q.push(nxt);
		}
	}
	if (num.size() != n)
		cout << 0 << endl;
	else{
		while (!num.empty()){
			cout << num.front() << endl;
			num.pop();
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> g[1001];
	int idg[1001] = {0};

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int k, a, b;
		cin >> k;
		cin >> a;
		for (int j = 0; j < k - 1; j++){
			cin >> b;
			g[a].push_back(b);
			idg[b]++;
			a = b;
		}
	}
	topology(n, g, idg);
	return (0);
}

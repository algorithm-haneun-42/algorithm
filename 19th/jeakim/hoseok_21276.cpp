#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int find_num(int n, string name[1001], string s)
{
	for (int i = 1; i <= n; i++)
		if (name[i] == s)
			return (i);
	return (0);
}

void topology(int n, vector<int> g[1001], int idg[1001], string name[1001])
{
	queue<int> q;
	int family = 0;
	
	for (int i = 1; i <= n; i++){
		if (idg[i] == 0){
			q.push(i);
			family++;
		}
	}
	cout << family << endl;
	for (int i = 1; i <= n; i++){
		if (idg[i] == 0)
			cout << name[i] << ' ';
	}
	cout << endl;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		if (family <= 0)
			cout << name[cur] << ' ';
		int cnt = 0;
		for (int nxt : g[cur]){
			idg[nxt]--;
			if(idg[nxt] == 0){
				cnt++;
				q.push(nxt);
			}
		}
		if (family <= 0){
			cout << cnt << ' ';
			for (int nxt : g[cur]){
				if (idg[nxt] == 0)
					cout << name[nxt] << ' ';
			}
			cout << endl;
		}
		family--;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> g[1001];
	string name[1001];
	int idg[1001] = {0};

	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		name[i] = s;
	}
	sort(name, name + n);
	cin >> m;
	for (int i = 0; i < m; i++){
		string x, y;
		int a, b;
		cin >> x >> y;
		a = find_num(n, name, x);
		b = find_num(n, name, y);
		g[b].push_back(a);
		idg[a]++;
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << idg[i] << ' ';
	cout << endl;
	topology(n, g, idg, name);
	return (0);
}
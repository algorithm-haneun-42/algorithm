#include <iostream>
#include <vector>

using namespace std;

int n;
char a[6][6];
int vis[36];
pair<int, int> b[3];
int ans;
vector<pair<int, int>> T;
vector<pair<int, int>> S;
vector<pair<pair<int, int>, pair<int, int>>> P;

void make_pair() {
    for (const vector <pair<int, int> >s : S) {
        for (const vector<pair<int, int> >t : T) {
            if (s->first == t->first || s->second == t->second) {
                P.push_back({s, t});
            }
        }
    }
}

int check_ans() {
    vector<pair<pair<int, int>, pair<int, int>>> CP = P;
    for (int i = 0; i < 3; i++) {
        for (auto it = CP.begin(); it != CP.end(); ) {
            pair<int, int> s = it->first;
            pair<int, int> t = it->second;
			if (((s.first == t.first) && (t.first == b[i].first) && ((s.second-b[i].second)*(t.second-b[i].second) < 0)) ||
				((s.second == t.second) && (t.second == b[i].second) && ((s.first-b[i].first)*(t.first-b[i].first) < 0))) {
				it = CP.erase(it);
			} 
			else
				++it;
		}
    }
    if (CP.empty())
		return 1;
	return 0;
}

void func(int k) {
    if (k == 3) {
		ans += check_ans();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'X' && vis[i * 6 + j] == 0) {
                b[k] = {i, j};
                vis[i * 6 + j] = 1;
                func(k + 1);
                vis[i * 6 + j] = 0;
            }
        }
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'T')
                T.push_back({i, j});
            else if (a[i][j] == 'S')
                S.push_back({i, j});
        }
    }
    make_pair();
	func(0);
	if (ans == 0)
		cout << "NO\n";
	else
		cout << "YES\n";
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int n, c;
float m, p;
vector <pair<int, float> > v;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> n >> m;
        if (n == 0 && m == 0.00)
            break;
        for(int i = 0; i < n; i++) {
            cin >> c >> p;
            v.push_back({c, p});
        }
        int cal[5001][100001] = {0};
        int mon[5001][100001] = {0};
        for(int k = 1; k <= 100000; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(v[j].second + mon[k-1][i] <= m && cal[k-1][j])
                }
            }
        }
    }
}
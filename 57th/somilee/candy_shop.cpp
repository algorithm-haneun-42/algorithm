#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n, c;
float m, p;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> n >> m;
        if (n == 0 && m == 0.00)
            break;
		vector <pair<int, float> > V;
		queue<int> Q;
        for(int i = 0; i < n; i++) {
            cin >> c >> p;
            V.push_back({c, p});
			Q.push(i);
        }
		int idx = 1;
		int cal[100005][5005] = {0};
		float money[5005] = {0};
		set <int, greater<int> > max_cal;
		while(!Q.empty()) {
			int q_size = Q.size();
			for(int i = 0; i < q_size; i++) {
				int cur = Q.front(); Q.pop();
				set<pair<int, float> > m_value;
				for(int k = 0; k < n; k++)
					if(money[cur-1]+V[k].second <= m)
						m_value.insert({cal[idx-1][cur]+V[k].first, money[cur]+V[k].second});
				if(!m_value.empty()) {
					cal[idx][cur] = m_value.rbegin()->first;
					money[cur] = m_value.rbegin()->second;
					Q.push(cur);
				}
				else
					max_cal.insert(cal[idx-1][cur]);
			}
			idx++;
		}
		cout << *max_cal.begin() << endl;
    }
}



// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     while(1) {
//         cin >> n >> m;
//         if (n == 0 && m == 0.00)
//             break;
// 		vector <pair<int, float> > v;
//         for(int i = 0; i < n; i++) {
//             cin >> c >> p;
//             v.push_back({c, p});
//         }
//         int cal[5005][100005] = {0};
//         int mon[5005][100005] = {0};
// 		int cal_max = 0;
//         for(int k = 1; k <= 100000; k++) {
// 			bool flag = false;
//             for(int i = 0; i < n; i++) {
//                 for(int j = 0; j < n; j++) {
// 					float m_add = mon[i][k-1] + v[j].second;
// 					int c_add = cal[i][k-1] + v[j].first;
// 					if(m_add <= m) {

// 					}
//                     if(m_add <= m && cal[i][k] < c_add) {
// 						cal[i][k] = c_add;
// 						mon[i][k] = m_add;
// 						flag = true;
// 					}
// 					else {
// 						cal[i][k] = cal[i][k-1];
// 						mon[i][k] = mon[i][k-1];
// 					}
// 					cal_max = max(cal_max, cal[i][k]);
//                 }
//             }
// 			if(!flag)
// 				break;
//         }
// 		cout << cal_max << endl;
//     }
// }
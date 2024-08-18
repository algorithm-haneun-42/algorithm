#include <iostream>
#include <vector>

using namespace std;

char b[6][6];
vector<string> pos;
pair<int, int> p[15] = {{0,1},{0,2},{0,3},{0,4},{0,5},{1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
string sum_result(string sum) {
	string r;
	for(int i = 0; i < 15; i++) {
		int x = p[i].first;
		int y = p[i].second;
		b[x][y] = sum[i];
		b[y][x] = sum[i];
	}
	for(int i = 0; i < 6; i++) {
		int w = 0;
		int l = 0;
		for(int j = 0; j < 6; j++) {
			if (b[i][j] == '1')
				w++;
			if (b[i][j] == '2')
				l++;
		}
		r = r + to_string(w) + to_string(5 - w - l) + to_string(l);
	}
	return r;
}

void func(string sum) {
	if (sum.size() == 15) {
		pos.push_back(sum_result(sum));
		return;
	}
	for (int i = 0; i <= 2; i++) {
		func(sum + to_string(i));
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string sum;
	func(sum);
	for (string a : pos)
		cout << a << endl;
	return 0;
}


// int n;
// int b[6][3];
// int check_pos(int b[6][3]) {
// 	for(int i = 0; i < 6; i++)
// 		if (b[i][0] + b[i][1] + b[i][2] != 5)
// 			return 0;
// 	int w = 0;
// 	int l = 0;
// 	int d = 0;
// 	int f = 0;
// 	for(int i = 0; i < 6; i++) {
// 		w += b[i][0];
// 		l += b[i][2];
// 		if (b[i][1] > 0) {
// 			if (f == 0) {
// 				d += b[i][1];
// 				if (d > 0)
// 					f = -1;
// 			}
// 			else if (f == -1) {
// 				d -= b[i][1];
// 				if (d <= 0)
// 					f = 1;
// 			}
// 		}
// 	}
// 	if (w != l)
// 		return 0;
// 	if (d != 0)
// 		return 0;
// 	return 1;
// }

// int main(void) {
// 	for(int a = 0; a < 4; a++) {
// 		for(int i = 0; i < 6; i++) {
// 			for(int j = 0; j < 3; j++) {
// 				cin >> b[i][j];
// 			}
// 		}
// 		cout << check_pos(b) << ' ';
// 	}
// 	return 0;
// }

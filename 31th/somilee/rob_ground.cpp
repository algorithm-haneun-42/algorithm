#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int b[100005][4];
int solution(vector<vector<int> > land)
{
	int i;
	for(i = 0; i < 4; i++)
		b[0][i] = land[0][i];
	for(i = 1; i < land.size(); i++){
		for(int j =  0; j < 4; j++) {
			b[i][j] = max({land[i][j] + b[i-1][(j+1)%4], land[i][j] + b[i-1][(j+2)%4], land[i][j] + b[i-1][(j+3)%4]});
		}
	}
	return (max({b[i-1][0], b[i-1][1], b[i-1][2], b[i-1][3]}));
}

int main(void) {
	vector<vector<int> > land = {{1,2,3,5}, {5,6,7,8}, {4,3,2,1}};
	cout << solution(land) << '\n';
}
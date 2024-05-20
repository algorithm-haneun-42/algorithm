#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
	int num[100001][4] = {0};

	for (int i = 0; i < 4; i++)
		num[0][i] = land[0][i];
	for (int i = 1; i < land.size(); i++){
		for (int j = 0; j < 4; j++){
			int	m = 0;
			for (int k = 0; k < 4; k++){
				if (j != k)
					m = max(m, num[i - 1][k]);
			}
			num[i][j] = m + land[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
		answer = max(answer, num[land.size() - 1][i]);
	// for (int i = 0; i < land.size(); i++){
	// 	for (int j = 0; j < 4; j++)
	// 		cout << num[i][j] << ' ';
	// 	cout << endl;
	// }
    return answer;
}

int main()
{
	vector<vector<int> > land = {{1,2,3,5}, {5,6,7,8}, {4,3,2,1}};

	cout << solution(land) << endl;

	return (0);
}
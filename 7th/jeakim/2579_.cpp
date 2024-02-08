#include <iostream>
#include <cmath>


using namespace std;
int main()
{
	int stair[301];
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> stair[i];
	}
	long score = stair[1];
	int idx = 1;
	while (idx < N - 1){
		score += max(stair[idx + 1], stair[idx + 2]);
		idx += stair[idx + 1] > stair[idx + 2] ? 1 : 2;
	}
	cout << score << endl;
	return (0);
}

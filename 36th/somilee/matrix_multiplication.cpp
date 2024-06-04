#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> ans;
	ans.resize(arr1.size());
	for(int i = 0; i < arr2[0].size(); i++) {
		for(int j = 0; j < arr1.size(); j++) {
			int sum = 0;
			for(int k = 0; k < arr1[0].size(); k++)
				sum += arr1[j][k] * arr2[k][i];
			ans[j].push_back(sum);
		}
	}
    return ans;
}

int main(void) {
	vector<vector<int>> arr1 = {{1,4}, {3,2}, {4,1}};
	vector<vector<int>> arr2 = {{3,3}, {3,3}};

	for(vector a : solution(arr1, arr2)) {
		for(int b : a) {
			cout << b << ' ';
		}
		cout << endl;
	}
}

/*
1,4  3,3  15,15
3,2  3,3  15,15
4,1       15,15

2,3,2  5,4,3  22,22
4,2,4  2,4,1  36,
3,1,4  3,1,1  29
*/
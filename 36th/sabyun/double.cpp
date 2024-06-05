#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(),0));
	for(int i = 0; i < arr1.size(); i++)
	{
		for(int j = 0; j < arr2[0].size(); j++)
		{
			for(int k = 0; k < arr2.size(); k++)
				answer[i][j] += (arr1[i][k] * arr2[k][j]);
		}
	}
    return answer;
}

int main()
{
	vector<vector<int>> arr1{{1, 4}, {3, 2}, {4, 1}};
	vector<vector<int>> arr2{{3, 3}, {3, 3}};

	solution(arr1,arr2);
}
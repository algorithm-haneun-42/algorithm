#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int max_num (int *land, int num)
{
	int maxre = 0;
	for(int i = 0; i < 4; i++)
	{
		if(i != num)
			maxre= max(land[i],maxre);
	}
	return maxre;
}
int solution(vector<vector<int> > land)
{
	int arr[100002][4];
	int end = 0;
	for(int i = 0; i < land.size(); i++)
	{
		for(int j = 0; j < land[0].size(); j++)
		{
			if( i == 0)
				arr[i][j] = land[i][j];
			else{
				int pre_max = max_num(arr[i-1],j);
				arr[i][j] = pre_max +land[i][j];
			}
		}
		end = i;
	}
    return max_num(arr[end],-1);
}

int main()
{
	vector<vector<int> > arr = {{1,2,3,5},{5,6,7,8},{4,3,2,1}};
	vector<vector<int> > arr2 = {{1,2,3,5}};
	vector<vector<int> > arr3 = {{1,2,3,5},{5,6,7,8},{4,3,2,1},{5,2,1,3}};
	vector<vector<int> > arr4 = {};
	cout << solution(arr) << endl;
	cout << solution(arr2) << endl;
	cout << solution(arr3) << endl;
	cout << solution(arr4) << endl;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int h_max = 0;
	sort(citations.begin(),citations.end());
	int max_int = citations[citations.size()-1];
	for(int i = 1; i < max_int; i++)
	{
		for(int j = 0; j < citations.size(); j++)
		{
			if(citations[j] >= i && citations.size()- j >= i)
				h_max = max(i,h_max);
		}
	}
    return h_max;
}
int main()
{
	vector<int> arr = {3, 0, 6, 1, 5};//3
	vector<int> arr1 = {0};//0
	vector<int> arr2 = {3, 4};//2
	vector<int> arr3 = {1, 2, 3, 5, 6, 7, 10, 11};//5
	vector<int> arr4 = {3, 5, 11, 6, 1, 5, 3, 3, 1, 41};//2
	cout << solution(arr) << endl;
	cout << solution(arr1) << endl;
	cout << solution(arr2) << endl;
	cout << solution(arr3) << endl;
	cout << solution(arr4) << endl;
}
// [0] 0
// [3, 4] 2
// [1, 2, 3, 5, 6, 7, 10, 11] 5
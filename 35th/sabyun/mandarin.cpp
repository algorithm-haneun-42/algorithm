#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <utility>
using namespace std;

vector <pair<int,int>> arr[100005];
int solution(int k, vector<int> tangerine) {
	for(int i = 0; i < tangerine.size(); i++)
	{
		auto a = arr->at(tangerine[i]);
		if(a != arr->end())
		a.first = tangerine[i];
		a.second++;
	}
	for(int i = 0; i < arr->size(); i++)
		cout << arr->at(i).first <<" " <<arr->at(i).second << endl;
	return 1;
}

int main()
{
	vector<int> arr = {1, 3, 2, 5, 4, 5, 2, 3};
	solution(6,arr);
}
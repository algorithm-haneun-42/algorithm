#include <queue>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

struct CompareSecond {
    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) const {
        return p1.second > p2.second;
    }
};

int main()
{
	vector<int> arr;
	int n ; cin >>n;

	vector<int> vi;
	for(int i =0; i < n; i++)
	{
		int a; cin >> a;
		arr.push_back(a);
		vi.push_back(0);
	}
	priority_queue <pair<int,int>,vector<pair<int,int>>,CompareSecond> maze;
	maze.push({0,0});
	vi[0] = 1;
	while(!maze.empty())
	{
		auto a = maze.top(); maze.pop();
		if(a.first == arr.size() -1)
		{
			cout << a.second << endl;
			return 0;
		}
		for(int i = a.first + 1; i <= a.first +arr[a.first]; i++)
		{
			if(i < arr.size() && vi[i] == 0)
			{
				maze.push({i,a.second+1});
				vi[i] = 1;
			}
		}
	}
	cout << "-1" << endl;
}
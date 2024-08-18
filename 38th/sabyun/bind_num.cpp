#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
struct CompareSecond {
    bool operator()(int p1, int p2) {
        return abs(p1) > abs(p2);
    }
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<long> arr;
	vector<long> miner_arr;
	long long answer = 0;
	stack<long> st;
	for(int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if( a > 0)
			arr.push_back(a);
		else
			miner_arr.push_back(a);
	}
	sort(arr.begin(),arr.end(),std::greater<int>());
	sort(miner_arr.begin(), miner_arr.end(), CompareSecond());
	// for(int i = 0; i < miner_arr.size(); i++)
	// 	cout << miner_arr[i] << endl;
	for(int i = 0; i < arr.size(); i++)
	{
		if(st.size() > 0 && st.top() * arr[i] > st.top() + arr[i])
		{
			long a = st.top();
			st.pop();
			answer += (a*arr[i]);
		}
		else
			st.push(arr[i]);
	}
	while(!st.empty())
	{
		answer +=st.top();
		st.pop();
	}
	for(int i = 0; i < miner_arr.size(); i++)
	{
		if(st.size() > 0 && st.top() * miner_arr[i] > st.top() + miner_arr[i])
		{
			long a = st.top();
			st.pop();
			answer += (a* miner_arr[i]);
		}
		else
			st.push(miner_arr[i]);
	}
	while(!st.empty())
	{
		answer +=st.top();
		st.pop();
	}
	cout << answer << endl;
}
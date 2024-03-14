#include <iostream>
#include <queue>
using namespace std;
int main(){
ios::sync_with_stdio(0);
cin.tie(0);

	priority_queue<long, vector<long>, greater<long> > box;
	long t; cin >> t;
	long total_size = 0;
	for (long i = 0; i < t; i++)
	{
		long n;
		cin >> n;
		for (long j = 0; j < n; j++)
		{
			long a;
			cin >> a;
			box.push(a);
		}
		while (box.size() > 1)
		{
			long one = box.top();
			box.pop();
			long two = box.top();
			box.pop();
			box.push(one + two);
			total_size += one+two;
		}
		cout <<total_size << endl;
		total_size = 0;
		while(!box.empty())
			box.pop();
	}
}
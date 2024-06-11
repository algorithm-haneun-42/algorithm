#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> cards) {
	priority_queue <int> num;
	vector<int> vi;
	vi.resize(cards.size());
	for(int i = 0; i < cards.size(); i++)
	{
		if(vi[i] ==1)
			continue;
		int total = 0;
		int idx = i;
		while(idx < vi.size() && vi[idx] != 1)
		{
			vi[idx] = 1;
			idx = cards[idx] -1;
			total++;
		}
		num.push(total);
	}
	if(num.size()<2)
		return 0;
	cout << num.top() << endl;
	int a = num.top();num.pop();
    return a * num.top();
}

int main ()
{
	vector<int> arr = {8,6,3,7,2,5,1,4};
	cout << solution(arr) << endl;
}
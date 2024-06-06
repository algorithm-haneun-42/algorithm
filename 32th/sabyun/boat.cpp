#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
	int vi[50002] = {0};
	sort(people.begin(),people.end(),greater<int>());
	int min = *(people.end()-1);
	int end = 0;
	int i = 0;
	while(i < people.size())
	{
		if(i<people.size() -1 && min + people[i] >= limit)
			answer++;
		else
			end  = i;
		i++;
	}
	if(end == people.size())
		return answer;
	for(int i = end; i < people.size(); i++)
	{
		if(vi[i] == 1)
			continue;
		vi[i] = 1;
		int total = people[i];
		bool f =true;
		for(int j = i+1; j < people.size();)
		{
			if(vi[j] == 1)
				continue;
			if(total + people[j] <= limit)
			{
				if(f == true)
					answer++;
				vi[j] = 1;
				total += people[j];
				f = false;
			}
			else
				break;
		}
	};
    return answer;
}

int main()
{
	vector<int> p = {70, 50, 80, 50};
	vector<int> p1 = {70,80, 50};
	vector<int> p2 = {70, 80, 50, 50 , 30 ,20,50, 10};

	cout << solution(p,100) << endl;
	cout << solution(p1,100) << endl;
	cout << solution(p2,100) << endl;
}
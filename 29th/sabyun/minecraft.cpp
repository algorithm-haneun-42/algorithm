#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
	vector<pair<int,int>> arr;
	int iron =0;
	int stone = 0;
	for(int i = 0; i < minerals.size(); i++)
	{
		if(i != 0 && i%5 == 0)
		{
			arr.push_back(make_pair(iron,stone));
			iron = 0;
			stone = 0;
		}
		if(minerals[i].compare("iron") == 0)
		{
			iron +=1;
			stone += 5;
		}
		if(minerals[i].compare("diamond") == 0)
		{
			iron +=5;
			stone += 25;
		}
		if(minerals[i].compare("stone") == 0)
		{
			iron +=1;
			stone +=1;
		}
	}
	arr.push_back(make_pair(iron,stone));
	sort(arr.begin(),arr.end());
	while(picks[0].size)
	{
		arr.p
	}	
    return answer;
}

1 1 1
5 1 1
25 5 1
1 3 1


 1 1 1 1 1, 1 5 5 5 5, 1
 1 1 5 5 1 ,1 1 1 1 1, 1

ston ston dia dia iron iron dia dia dia dia ston
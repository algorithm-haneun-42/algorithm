#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int solution(int storey)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	pq.push({0,storey});
	while(1)
	{
		auto ahead = pq.top();
		if(ahead.second == 0)
			break;
		pq.pop();
		if (ahead.second % 10 > 0)
		{
			pq.push({ahead.first + (10 - ahead.second % 10) ,(ahead.second + (10 - ahead.second % 10))/10});
			pq.push({ahead.first + ahead.second % 10 , (ahead.second - ahead.second % 10)/10});
		}
		else if (ahead.second % 10 == 0)
		{
			pq.push({ahead.first ,ahead.second/10});	
		}
	}
	return pq.top().first;


}

int main()
{
	printf("%d\n",solution(1600000));
	printf("%d\n",solution(595));
	printf("%d\n",solution(595));
	printf("%d\n",solution(16));
	printf("%d\n",solution(2554));

}




/*ex
16	6
2554	16
*/
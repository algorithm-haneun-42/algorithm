#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	vector<int>day;
	for (int i = 0; i < progresses.size();i++)
	{
		int left = 100- progresses[i];
		int time = 0;

		while(left>0){
			left-=speeds[i];
			time++;
		}
		day.push_back(time);
	}
	int pre_day = day[0];
	int num = 1;
	for(int i = 1; i < day.size(); i++)
	{
		if(day[i] > pre_day)
		{
			answer.push_back(num);
			pre_day = day[i];
			num = 1;
		}
		else
		{
			num++;
		}

		// cout << day[i] << endl;
	}
	answer.push_back(num);

    return answer;
}

int main()
{
	vector<int> progresses = {93, 30, 55};
	vector<int> speeds = {1, 30, 5};
	vector<int> progresses1 = {95, 90, 99, 99, 80, 99};
	vector<int> speeds1 = {1, 1, 1, 1, 1, 1};
	auto a = solution(progresses1,speeds1);
	for(int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

}
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
	for(int i = begin; i<= end; i++)
	{
		if(i == 1)
		{
			answer.push_back(0);
			continue;
		}
		int div_num = sqrt(i);
		int check = 0;
		for(int j = 2; j<=div_num; j++)
		{
			if(i%j == 0)
				{
					answer.push_back(i/j);
					check = 1;
					break;
				}
		}
		if(check ==0)
			answer.push_back(1);
	}
    return answer;
}
using namespace std;

int main ()
{
    vector<int> answer;
	int n = 12;
	int end = 223;
	cout << int(sqrt(6)) << endl;
	answer = solution(n,end);

	// for(int i = 0; i < end-n; i++)
	// 	cout << answer[i] << " ";
	// cout << endl;
	for(int n: answer) {
		cout << n << ' ';
	}
}
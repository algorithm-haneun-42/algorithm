#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer  = "";
	int i = 0;
	while(i < k && number.size() > 1)
	{
		if(number[0] > number[1])
			number.erase(number.begin()+(1));
		else if(number[0] < number[1])
			number.erase(number.begin());
		else
			{
				if (number[2] < number[0])
				{
					answer += number.substr(0, 2);
					// cout << answer <<endl;
					number.erase(number.begin(), number.begin() + 2);
					continue;
				}
				else
					number.erase(number.begin());
			}
		i++;
	}
	answer += number;
    return answer;
}

int main (int argc, char **argv)
{
	string a = argv[1];
	for(int i =1; i < a.size(); i++)
		cout << solution(a,i) << endl;
}
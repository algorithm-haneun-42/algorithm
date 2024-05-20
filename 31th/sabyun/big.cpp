#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers)
{
	struct cmp1
	{
		bool operator()(int a, int b)
		{
			string ab = to_string(a) + to_string(b);
			string ba = to_string(b) + to_string(a);
			return ab > ba ? true : false;
		}
	};
	sort(numbers.begin(),numbers.end(),cmp1());
    string answer = "";
	for(auto a : numbers)
	{
		answer+=to_string(a);
	}
	if(answer[0] == '0')
		return "0";
    return answer;
}

int main()
{
	vector<int> numbers = {0,0,0};
	cout << solution(numbers)<<endl;
	//base  > comp 1 // base < comp -1 base == comp 0
}
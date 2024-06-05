#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
	bool end =true;
	while(1)
	{
		end = true;
		for(int i = 0; i+1 < s.size(); i++)
		{
			if(s[i]==s[i+1])
			{
				s.erase(i,2);
				end= false;
			}
		}
		if(end == true)
			break;
	}
	if(s.empty())
		return 1;
	return 0;
}

int main()
{
	string a = "baabaa";
	string b = "bcbc";
	cout << solution(a) << endl;
	cout << solution(b) << endl;

}
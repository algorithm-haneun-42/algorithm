#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
	int answer =0; 
	bool a = s.find('(') != std::string::npos && s.find(')') != std::string::npos;
	bool b = s.find('{') != std::string::npos && s.find('}') != std::string::npos;
	bool c = s.find('[') != std::string::npos && s.find(']') != std::string::npos;
	if((!a && s.find('(') != std::string::npos || s.find(')') != std::string::npos) || (!b && s.find('{') != std::string::npos || s.find('}') != std::string::npos) || (!c && s.find('[') != std::string::npos || s.find(']') != std::string::npos))
		return 0;
	for(int i =0; i < s.size(); i ++)
	{
		bool all_pos = true;
		if(a && s.find('(') > s.find(')')) 
			all_pos = false;
		if(b && s.find('{') > s.find('}'))
			all_pos = false;
		if(c && s.find('[') > s.find(']'))
			all_pos = false;
		if(( a || b || c )&& all_pos == true)
			answer++;
		s.push_back(s[0]);
		s.erase(0,1);
	}
    return answer;
}
int main()
{
	cout << solution("[]{}()") << endl;
	cout << solution("}}}[]{}") << endl;
}
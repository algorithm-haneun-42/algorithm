#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int  char_num(string &name)
{
	int num = 0;
	for(int i = 0; i < name.size(); i++)
	{
		num += min('Z' - name[i] + 1,name[i] - 'A');
	}
	return num;
}


int dist_num(string &name)
{
	int num = 0;
	int l_num =0;
	int r_num = 0;
	int sr =0;
	int sl = 0;
	for(int i = 0; i < name.size(); i++)
	{
		if(name[i]  != 'A')
		{
			l_num += i - sl;
			sl = i;
		}
	}
	for(int i = name.size(); i >0; i--)
	{
		if(name[i]  != 'A')
		{
			r_num += name.size() - i -sr;
			sr = name.size() - i;
		}
	}
	//cout << l_num << " "<<r_num << endl;
	return min(l_num,r_num);
}

int solution(string name) {
	int num = char_num(name);
	//cout << num <<endl;
	num += dist_num(name);
	return num;

}
int main ()
{
	string name = {"HAAABAAAAAAL"};
	cout << solution(name) << endl;
}
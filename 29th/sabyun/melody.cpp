#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

void make_melody(queue <string> &s, string m, int s_num,int size)
{
	int a = 0;
	for (int j = 0; j < size; j++)
	{
		string tmp;
		if (a >= m.size())
			a = 0;
		tmp.push_back(m[a]);
		s.push(tmp);
		a++;
	}
}

void print_q(queue <string> a)
{
	while(!a.empty())
	{
		cout << a.front() << endl;
		a.pop();
	}
	cout << endl;
}
int is_aaa(queue <string> a, queue <string> b)
{
	string sa;
	string sb;

	while (!a.empty())
	{
		sa += a.front();
		a.pop();
	}
	while (!b.empty())
	{
		sb += b.front();
		b.pop();
	}
	if(sa.find(sb) != string::npos)
		return 1;
	return 0;
}
void replace_chr(string &str)
{
	while(str.find("C#")!= string::npos)
		str.replace(str.find("C#"), 2, "I");
	while(str.find("D#")!= string::npos)
		str.replace(str.find("D#"), 2, "J");
	while(str.find("F#") != string::npos)
		str.replace(str.find("F#"), 2, "K");
	while(str.find("G#") != string::npos)
		str.replace(str.find("G#"), 2, "L");
	while(str.find("A#") != string::npos)
		str.replace(str.find("A#"), 2, "M");
	while(str.find("B#") != string::npos)
		str.replace(str.find("B#"), 2, "O");
}
string solution(string m, vector<string> musicinfos)
{
	string ret;
	int ret_time = 0;
	replace_chr(m);
	queue<string> ori_mel;
	make_melody(ori_mel, m, 0,m.size());
	for (int i = 0; i < musicinfos.size(); i++)
	{
		queue<string> temp;
		string s_time = musicinfos[i].substr(0, musicinfos[i].find(','));
		musicinfos[i].erase(0, s_time.size() + 1);
		string e_time = musicinfos[i].substr(0, musicinfos[i].find(','));
		musicinfos[i].erase(0, e_time.size() + 1);
		string m_name = musicinfos[i].substr(0, musicinfos[i].find(','));
		musicinfos[i].erase(0, m_name.size() + 1);
		string melody = musicinfos[i].substr(0, musicinfos[i].size());
		replace_chr(melody);
		int s_h = stoi(s_time.substr(0, 2).c_str());
		int s_m = stoi(s_time.substr(3, 4).c_str());
		int e_h = stoi(e_time.substr(0, 2).c_str());
		int e_m = stoi(e_time.substr(3, 4).c_str());
		int t_min = ((e_h*60 +e_m) - (s_h *60 + s_m));
		make_melody(temp, melody,0,t_min);
		if (is_aaa(temp, ori_mel) == 1)
		{
			if (ret.empty() == 1)
			{
				ret = m_name;
				ret_time = t_min;
			}
			else
			{
				if (ret_time < t_min)
				{
					ret = m_name;
					ret_time = t_min;
				}
			}
		}
	}
	if (ret.empty()==1)
		ret = "(None)";
	return ret;
}
int main()
{
	vector <string> case1 {"12:00,12:05,Sing,ABCDE"};
	string melody1 = "ACE";
	//cout << solution(melody1,case1) << endl;
	//cout << solution(melody2,case2) << endl;
	//cout << solution(melody3,case3) << endl;
	//cout << solution(melody6,case6) << endl;
	//cout << solution(melody7,case7) << endl;
	//cout << solution(melody10,case10) << endl;
	//cout << solution(melody11,case11) << endl;
	cout << solution(melody1,case1) << endl;
}
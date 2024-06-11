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


void dist_num(vector<pair<int,int>> &arr,string &name)
{
	int num = 0;
	for(int i = 0; i < name.size(); i++)
	{
		if(name[i]  != 'A')
		{
			arr.push_back({i,name.size()- i});
		}
	}
	//cout << l_num << " "<<r_num << endl;
}
//lr *2  + next_r_num < next_l_num
int add_num(vector<pair<int,int>> &arr)
{
	int min_num = 0;
	// for(auto a: arr)
	// {
	// 	cout << "("<<a.first<<", " << a.second << ")" << endl;
	// }
	if(arr.size())
		min_num = min(arr[arr.size()-1].first,arr[0].second);
	for (int i = 0; i +1< arr.size(); i++)
	{
		if((arr[i].first *2 + arr[i+1].second < arr[arr.size()-1].first))
		{
			min_num = min(min_num,arr[i].first *2 + arr[i+1].second);
		}
		if((i > 0 && arr[i].second *2 + arr[i-1].first >= arr[i-1].second))
		{
			min_num = min(min_num,arr[i].second *2 + arr[i-1].first);
		}
	}

//	 cout<< min_num << " " << endl;
	return min_num;
}

int solution(string name) {
	vector<pair<int,int>> arr;
	int num = char_num(name);
//	cout << num <<endl;
	dist_num(arr,name);
	num += add_num(arr);
	return num;

}
int main ()
{
//	for (int i = 0; i < 41; i++)
	while(1)
	{
		string str;
		int num;
		cin >> str >> num;
		if(str.empty())
			break;
		cout << "str  = " << str << " \n"<< solution(str)<< " = " << num << endl;
	}
}

//lr *2  + next_r_num < next_l_num
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

struct CompareFirst {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first > b.first; // 첫 번째 요소가 작은 순으로 정렬
		}
};
struct CompareSecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first; // 첫 번째 요소가 작은 순으로 정렬
		}
};

int make_q(priority_queue<pair<int, int>, vector<pair<int, int>>, CompareFirst> &fq, string &name)
{
	int num = 0;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] != 'A' && name[i] - 77 > 0)
		{
			num += 'Z' - name[i] + 1;
			//cout <<"alpa = " << name[i] << " "<<'Z' - name[i] + 1 << endl; 
		}
		else if (name[i] != 'A' && name[i] - 77 < 0)
		{
			num += name[i] - 'A';
			//cout <<"alpa = " << name[i] << " " << name[i] - 'A'<< endl;
		}
		else if(name[i] != 'A' && name[i] == 'M')
		{
			//cout <<"alpa = M 12" <<endl;
			num += 12;
		}
		if(name[i] != 'A')
		{
			if(i != 0)
				fq.push({i,name.size() - i});
//			cout << "i = " << i << "re_i = " << name.size() - i << endl;
		}
	}
	return num;
}
int solution(string name) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareFirst> fq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecond> bq;
	bool way = true;
	int num = 0;
	num = make_q(fq,name);
	int save = num;
	int now_index = 0;	
	// if(!fq.empty())
	// 	now_index = fq.top().first;
	while(!fq.empty())
	{
		auto a = fq.top();fq.pop();
		if((!fq.empty() && a.second <= fq.top().first) || fq.empty() && a.first > a.second)
		{
			bq.push(a);
			while(!fq.empty())
			{
				auto temp  = fq.top();fq.pop();
				bq.push(temp);
				now_index = 0;
			}
			break;
		}
		else{
			num += a.first - now_index;
			now_index = a.first;
		}
		if(!fq.empty() && fq.top().first - a.first >= fq.top().second + a.first)
		{
			num += a.first;
			while(!fq.empty())
			{
				auto temp  = fq.top();fq.pop();
				bq.push(temp);
				now_index = 0;
			}
			break;
		}

	}
	while(!bq.empty())
	{
		auto a = bq.top();bq.pop();
		num += a.second - now_index;
		now_index = a.second;
	}
	cout << num - save << endl;
	return num;
}
// int is_allequal (string &name, string &str)
// {
// 	for(int i = 0; i < name.size();i++)
// 	{
// 		if(name[i] != str[i])
// 			return 1;
// 	}
// 	return 0;
// }
// int solution(string name) {
//     string str;
// 	str.resize(name.size());
// 	fill(str.begin(),str.end(),'A');
// 	int num = 0;
// 	for(int i = 0; i < name.size();i++)
// 	{
// 		if (i > 0 && name[i] == str[i])
// 			continue;
// 		else if(name[i] != str[i] && name[i] - 77 >= 0)
// 		{
// 			num += 'Z' - name[i] + 1;
// 			//cout <<  i << "  pos num = " << 'Z' - name[i] << endl; 
// 			str[i] = 'Z' - ('Z' - name[i]);
// 		}
// 		else if(name[i] != str[i] && name[i] - 77 < 0)
// 		{
// 			num += name[i] - 'A';
// 		//	cout <<  i << " nag num = " << name[i] - 'A' << endl;
// 			str[i] = 'A' + name[i] - 'A';
// 		}
// 		if (i == 0 && is_allequal(name, str) == 0)
// 		{
// 			i = name.size() - 1;
// 			continue;
// 		}
// 		if (i < name.size() - 1)
// 			num += 1;
// //		cout << "i = "<< i <<  "number = " << num << endl;
// 	}
// /*
// 	cout << num << endl;
// 	for(auto a : str)
// 		cout << a << endl;
// 		*/
// 	return num;
// }

int main ()
{
	string name = {"JAN"};
	cout << solution(name) << endl;
}
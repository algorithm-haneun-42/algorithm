#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int cmp_two(map<string, int> &get, map<string,int> &mart)
{
	for (auto a : get)
	{
		if(a.second > mart[a.first])
			return 0;
	}
	return 1;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
	map <string,int> get;	
	int total = 0;
	int p_num = 0;
	for(int i = 0; i < want.size(); i++)
	{
		get.insert({want[i],number[i]});
		p_num += number[i];
	}
	int i =0;
	map<string,int> mart;
	for(int j = 0; j < p_num; j++)
		++mart[discount[j]];

	while(i+p_num <=discount.size())
	{
		total += cmp_two(get,mart);
		if(i+p_num < discount.size())
			++mart[discount [p_num+i]];
		--mart[discount [i]];
		i++;
	}
    return total;
}

int main()
{
	vector<string> product = {"banana", "apple", "rice", "pork", "pot"};
	vector<int> num = {3, 2, 2, 2, 1};
	vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};
	cout << solution(product,num,discount) << endl;
}
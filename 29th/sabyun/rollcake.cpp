#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
int is_ret(vector<int> &arr, int i, bool &flag)
{
	set<int> a;
	set<int> b;
	for(int j = 0; j<i;j++)
	{
		a.insert(arr[j]);
	}
	for(int j = i; j < arr.size(); j++)
	{
		if (b.size() > a.size())
		{
            return 0;
		}
		b.insert(arr[j]);
	}
	if(a.size() == b.size())
	{
		flag = false;
		return 1;
	}
	return 0;
}

int solution(vector<int> topping) {
	int ret = 0;
	bool flag = true;
	for(int i = 0; i <topping.size(); i++)
	{
		int a = is_ret(topping,i,flag);
		ret += a;
		if(a == 0 && flag == false)
			break;
	}
	return ret;
}

int main()
{
	vector<int> arr = {1, 2, 1, 3, 1, 4, 1, 2};
	vector<int> arr2 = {1, 2, 3, 1, 4};
	cout << solution(arr)<< endl;
	cout << solution(arr2)<< endl;
}
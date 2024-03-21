#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	multiset<pair<int , int>> box;
	int index[100002] = {0};
	int	n; cin >> n;
	for(int i = 0 ; i<n;i++)
	{
		int a,b; cin >> a >> b;
		box.insert({b,a});
		index[a] = b; 
	}
	cin >> n;
	for(int i = 0; i <n ; i++)
	{
		string str; cin >> str;
		if(str == "add")
		{
			int a,b; cin >> a >> b;
			box.insert({b,a});
			index[a] = b;
		}
		//add quest;
		else if(str == "recommend")
		{
			int num; cin >> num;
			if(num == 1)
			{
				auto temp = box.rbegin();
				if(temp != box.rend())
					cout << (--temp.base())->second << endl;
			}
			else if (num == -1)
			{
				auto temp = box.begin();
				if(temp != box.end())
					cout << temp->second <<endl;
			}
		}
		//if 1 lagest number recommand or -1 is lowest number recommend;
		else if(str == "solved")
		{
			int num; cin >> num;
			//auto aa = box.find({index[num],num});
			box.erase({index[num],num});
			index[num] = 0;
		}
		// remove number

	}
}
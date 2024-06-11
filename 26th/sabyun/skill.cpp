#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void make_que(queue<int> &q , string skill)
{
	for(int i = 0; i < skill.size(); i++)
		q.push(skill[i]);
}

int check_remain (queue<int> &q, string &tree)
{
	bool flag = true;
	while (!q.empty())
	{
		if (flag)
		{
			for (int i = 0; i < tree.size(); i++)
			{
				if (q.front() == tree[i])
					flag = false;
			}
		}
		q.pop();
	}
	return flag;
}
int solution(string skill, vector<string> skill_trees)
{
	queue<int>q;
	int num = 0;
	for(auto tree : skill_trees)
	{
		make_que(q,skill);
		for(int i = 0; i < tree.size();i++)
		{
			if(q.front() == tree[i])
				q.pop();
		}
		num += check_remain(q,tree);
	}
    return num;
}

int main ()
{
	string skill = {"CBD"};
	vector<string> skill_tree = {"BACDE", "CBADF", "AECB", "BDA"};
	std::cout << solution(skill,skill_tree)<< std::endl;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check_exist(string skill, char c)
{
    for (int i = 0; i < skill.size(); i++){
		if (skill[i] == c)
			return (1);
	}
    return (0);
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++){
		int flag = 0;
		int k = 0;
		for (int j = 0; j < skill_trees[i].size(); j++){
			if (check_exist(skill, skill_trees[i][j]) == 1){
				if (skill[k] == skill_trees[i][j])
					k++;
				else
					flag = 1;
			}
		}
		if (flag == 0)
			answer++;
	}    
    return answer;
}

int main()
{
	string skill = "CBD";
	vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

	cout << solution(skill, skill_trees) << '\n';
	return (0);
}
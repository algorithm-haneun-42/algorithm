#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_skill(string skill, char s) {
	for(int i = 0; i < skill.length(); i++) {
		if (s == skill[i])
			return (i);
	}
	return (-1);
}

int solution(string skill, vector<string> skill_trees) {
	int ans = 0;
	for(string skills : skill_trees) {
		int b_skill = 0;
		int flag = 0;
		for(int i = 0; i < skills.length(); i++) {
			int is_skill = check_skill(skill, skills[i]);
			if (is_skill == -1)
				continue;
			if (is_skill == b_skill) {
				b_skill++;
				continue;
			}
			flag = 1;
		}
		if (flag == 0)
			ans++;
	}
	return ans;
}

int main(void) {
    vector<string> skill_trees;
    skill_trees.push_back("BACDE");
    skill_trees.push_back("CBADF");
    skill_trees.push_back("AECB");
    skill_trees.push_back("BDA");
    cout << solution("CBD", skill_trees) << '\n';
    return 0;
}
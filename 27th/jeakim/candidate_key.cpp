#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<vector<string>> info;
int row, col;
int cnt = 0;

int check_set(set<vector<string>> &s)
{
	if (row == s.size())
		return (1);
	return (0);
}

void dfs(int dep, int idx)
{
	set<vector<string>> s;

	if (dep == info[0].size())
		return ;
	for (int i = 0; i < row; i++){
		vector<string> v;
		for (int j = idx; j < col && j < idx + dep; j++)
			v.push_back(info[i][j]);
		s.insert(v);
	}
	if (check_set(s) == 1){
		cnt++;
		cout << "dep : " << dep << " idx : " << idx << '\n';
		return ;
	}
	dfs(dep + 1, idx);
}

int solution(vector<vector<string>> relation) {
	info = relation;
    int answer = 0;
	row = relation.size(); col = relation[0].size();
	set<vector<vector<string>> > s;
	for (int i = 0; i < col; i++)
		dfs(1, i);
	answer = cnt;
	if (answer == 0)
		return (1);
    return answer;
}

int main()
{
	vector<vector<string> > relation = { {"a","1","aaa","c","ng"},
			{"a","1","bbb","e","g"},
			{"c","1","aaa","d","ng"},
			{"d","2","bbb","d","ng"}};

	cout << solution(relation) << endl;

	return (0);
}
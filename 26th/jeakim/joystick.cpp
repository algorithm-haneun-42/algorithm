#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> max_string_a(string name)
{
	vector<int> idx_m(3);
	int st, end;

	st = 0;
	while (st < name.size()){
		end = st + 1;
		if (name[st] == 'A'){
			while (end < name.size() && name[end] == 'A')
				end++;
			idx_m[2] = max(idx_m[2], end - st);
			idx_m[0] = idx_m[2] > end - st ? idx_m[0] : st;
			idx_m[1] = idx_m[2] > end - st ? idx_m[1] : end;
		}
		st = end;
	}
	return (idx_m);
}

int solution(string name) {
    int answer = 0;
	int n = name.size();
	vector<int> idx_m = max_string_a(name);	

	for (int i = 0; i < n; i++)
		answer += min(abs(name[i] - 'A'), abs('Z' - name[i] + 1));
	if (idx_m[2] == 0 || idx_m[2] == 1)
		answer += n - 1;
	else if (idx_m[2] == n)
		answer += 0;
	else
		answer += idx_m[2];
    return answer;
}

int main()
{
	cout << solution("BABABABABABBABABAAB") << endl;

	return (0);
}
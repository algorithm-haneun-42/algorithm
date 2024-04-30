#include <string>
#include <vector>
#include <iostream>

using namespace std;

// int front(string name)
// {
// 	int i = 0;
// 	while(i < name.size() && name[i] != 'A'){
// 		i++;
// 	}
// 	while(i < name.size() && name[i] == 'A')
// 		i++;
// 	return (i);
// }

// int from_back(string name)
// {
// 	int i = name.size() - 1;
// 	while(i >= 0 && name[i] != 'A')
// 		i--;
// 	while(i >= 0 && name[i] == 'A')
// 		i--;
// 	return (i);
// }

int max_string_a(string name)
{
	int m = 0;
	int st, end;

	st = 0;
	while (st < name.size()){
		end = st + 1;
		if (name[st] == 'A'){
			while (end < name.size() && name[end] == 'A')
				end++;
			m = max(m, end - st);
		}
		st = end;
	}
	return (m);
}


int solution(string name) {
    int answer = 0;
	int n = name.size();
	int idx_m = max_string_a(name);	

	for (int i = 0; i < n; i++)
		answer += min(abs(name[i] - 'A'), abs('Z' - name[i] + 1));
	if (idx_m == 0)
		answer += n - 1;
	else if (idx_m == n)
		answer += 0;
	else
		answer += idx_m;
    return answer;
}

int main()
{
	cout << solution("JEROEN") << endl;

	return (0);
}
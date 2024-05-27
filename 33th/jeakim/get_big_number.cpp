#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_maxnum(string number, int k, int idx)
{
	int max_idx = idx;

	for (int i = 0; i + idx < number.length() - (k - 1); i++)
		if (number[max_idx] - '0' < number[i + idx] - '0')
			max_idx = i + idx;
	return (max_idx);
}

string solution(string number, int k) {
    string answer = "";
	int	len = number.length() - k;
	int max_idx = 0;

	int idx = -1;
	for (int i = 0; i < number.length() - k; i++)
	{
		idx = find_maxnum(number, len, idx + 1);
		answer += number[idx];
		cout << idx << ' ' << number[idx] << ' ' << answer << endl;
		len--;
	}
    return answer;
}

int main()
{
	cout << solution("4177252841", 4) << endl;

	return (0);
}
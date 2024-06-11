#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	int st = 1;

	while (st <= n){
		int num = st;
		for (int end = st + 1; num <= n; end++)
		{
			if (num == n){
				answer++;
				cout << st << ' ' << end << endl;
				break;
			}
			num += end;
		}
		st++;
	}
    return answer;
}

int main()
{
	cout << solution(16) << endl;

	return (0);
}
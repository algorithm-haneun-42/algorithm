#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long max_com_div(long long n)
{
	long long m;

	if (n == 1)
		return (0);
    if (n % 2 == 0)
        return (n / 2);
	m = 3;
    for (int i = 3; i <= 10000000 && i * i <= n; i = i + 2)
        if (n % i == 0)
            return (n / i);
    return (1);
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for (long long i = begin; i <= end; i++)
        answer.push_back(max_com_div(i));
    return answer;
}

int main()
{
	vector<int> answer = solution(1, 10);
	for (long long i = 0; i < answer.size(); i++){
		cout << answer[i] << ' ';
	}
	return (0);
}
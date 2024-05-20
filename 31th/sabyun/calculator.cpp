#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int x, int y, int n) {
	int answer = y;
	if(y%(2 * x) == 0) y/(2 *x) < answer ? answer =  y/(2 *x) : answer = answer;
	if(y%(3 * x) == 0) y/(3 *x) < answer ? answer =  y/(3 *x) : answer = answer;
	if((y - x) % n == 0) (y - x) / n < answer ? answer =  (y - x) / n : answer = answer;
	if(answer == y)
		return -1;
	return answer;
}

int main ()
{
	cout << solution(10,40,5) << endl;
}
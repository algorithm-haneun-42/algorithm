#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {

    int answer = 1;
	if(n==2)
		return 1;
	for(int i = (n/2)+1; i > 1; i--)
	{
		int total = 0;
		for(int j = i ; total < n && j > 0; j--)
			total+=j;
		if(total == n)
			answer++;
	}
    return answer;
}

int main()
{
	cout << solution(2) <<endl;
	cout << solution(2) <<endl;
	cout << solution(2) <<endl;
	cout << solution(2) <<endl;
	cout << solution(2) <<endl;
	cout << solution(2) <<endl;
	cout << solution(2) <<endl;
	cout << solution(2) <<endl;
}
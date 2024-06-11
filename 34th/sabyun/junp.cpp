#include <string>
#include <vector>
#include <iostream>
using namespace std;


long long solution(int n) {
	int arr[2002];
	arr[1] = 1;
	arr[2] = 2;
	for(int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i-1] + arr[i-2]) %1234567;
	}
    return arr[n];
}

int main()
{
	cout << solution(4) << endl;
}
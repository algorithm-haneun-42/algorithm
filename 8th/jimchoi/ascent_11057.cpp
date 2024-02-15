
#include <iostream> 
using namespace std;

int arr[10][1001];

int n;

int main()
{
	cin >> n;

	for(int i=0; i<n; i++)
		arr[0][i] = 1;
	for(int i=0; i<10; i++)
		arr[i][0] = 1;
	
    for(int i=1; i<10; i++)
	{
        for(int j=1; j<n; j++)
		{
			arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 10007;
		}
	}
	int result =0;
    for(int i=0; i<10; i++)
		result += arr[i][n-1];
	result = result % 10007;
    cout << result << endl;

}
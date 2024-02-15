#include <iostream>
#include <cstring>
using namespace std;

char str1[1002];
char str2[1002];
int d[1001][1001];

int main()
{
	cin >> str1 >> str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
	if (len1 == 0 || len2 == 0)
	{
		cout << 0 << endl;
        return 0;
	}
	for(int i = 1; i <=len1; i++)
	{
		for(int j = 1; j <= len2; j++)
		{
			if(str1[i-1] == str2[j-1])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
			else
				d[i][j] = max(d[i-1][j], d[i][j-1]);
		}
	}
	cout << d[len1][len2] << endl;
}
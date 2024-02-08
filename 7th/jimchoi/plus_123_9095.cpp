#include <iostream>
using namespace std;

int d[12];

int t;
int main()
{
    ios::sync_with_stdio(0);
    cin >> t;
    int n;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int j=0; j<t; j++)
    {
        cin >> n;
        int i = 1;
        while (i <= n)
        {
            if (i > 3)
                d[i] = d[i-1] + d[i-2] + d[i-3];
            i++;
        }
        cout << d[i - 1] << endl;
    }
}


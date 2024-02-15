#include <iostream>
using namespace std;

int n;
int d[10001];
int wine[10001];

int main()
{
    cin >> n;

    for(int i =1; i<= n; i++)
        cin >> wine[i];

    d[1] = wine[1];
    d[2] = d[1] + wine[2];

    for(int i = 3; i<=n; i++)
    {
        d[i] = max(d[i-3] + wine[i-1], d[i-2]) + wine[i];
        d[i] = max(d[i-1], d[i]);
    }

    cout <<  d[n] << endl;
}
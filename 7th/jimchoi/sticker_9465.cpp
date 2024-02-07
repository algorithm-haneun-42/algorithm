
#include <iostream>
using namespace std;

int t;
int n;
int d[3][100001];
int sticker[3][100001];

int main()
{
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> sticker[1][i+1];
        for(int i=0; i<n; i++)
            cin >> sticker[2][i+1];
        d[1][1] = sticker[1][1];
        d[2][1] = sticker[2][1];
        d[1][2] = sticker[1][2] + sticker[2][1];
        d[2][2] = sticker[2][2] + sticker[1][1];
        for(int i=3; i<=n; i++)
        {
            d[1][i] = max(max(d[1][i-2], d[2][i-1]), d[2][i-2]) + sticker[1][i];
            d[2][i] = max(max(d[2][i-2], d[1][i-1]), d[1][i-2]) + sticker[2][i];
        }
        cout << max(d[1][n], d[2][n]) << endl;

    }
}

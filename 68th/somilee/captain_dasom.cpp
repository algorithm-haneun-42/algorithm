#include <iostream>
#include <limits>

using namespace std;

int b[300001];
int main(void) {
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        b[i] = INT_MAX;
    for(int i = 1; i*(i+1)*(i+2) <= 6*n; i++) {
        int term = i*(i+1)*(i+2)/6;
        for(int j = 0; j + term <= n; j ++) {
            for(int k = 1; j + term*k <= n; k++)
                b[j + term*k] = min(b[j + term*k], b[j + term*(k-1)]+1);
        }
    }
    cout << b[n] << endl;
    return 0;
}
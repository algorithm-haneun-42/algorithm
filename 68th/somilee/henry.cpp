#include <iostream>

using namespace std;
int T, a , b;

int getDiv(int a, int b) {
    while(a%b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}

int func(int a, int b) {
    int x;
    for(x = 2; x <= 10000; x++)
        if (b <= a * x)
            break;
    if(b == a * x)
        return x;
    int div = getDiv(a * x - b, b * x);
    a = (a * x - b) / div;
    b = b * x / div;
    if (a == 1)
        return b;
    return func(a, b);
}

int main(void) {
    cin >> T;
    while(T--) {
        cin >> a >> b;
        cout << func(a, b) << endl;
    }
    return 0;
}

// float T, a, b;
// float func(float n) {
//     float i;
//     for(i = 2; i <= 10000; i++)
//         if (1/i <= n)
//             break;
//     if(1/i == n)
//         return i;
//     return func(n - 1/i);
// }
// int main(void) {
//     cin >> T;
//     while(T--) {
//         cin >> a >> b;
//         cout << func(a/b) << endl;
//     }
// }
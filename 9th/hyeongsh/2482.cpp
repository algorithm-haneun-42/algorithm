
#include <iostream>

long long arr[1005][1005];
int n;
int k;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
        arr[1][i] = 1;
    for (int a = 2; a <= k; a++) {
        for (int b = n; b >= 0; b--) {
            arr[a][b] = (arr[a - 1][b + 2] + arr[a][b + 1]) % 1000000003;
        }
    }
    int sum = arr[k][1];
    for (int i = 1; i < n + 1; i++) {
        sum += arr[k][i];
        sum = sum % 1000000003;
    }
    std::cout << sum << std::endl;
    return (0);
}

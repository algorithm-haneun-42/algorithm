#include <algorithm>
#include <iostream>

int K;
int N;
int arr[10000];

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    std::cin >> K;
    std::cin >> N;
    for (int i = 0; i < K; i++) {
        std::cin >> arr[i];
    }
    long long st = 0;
    int en = 2147483647;
    int result;
    while (st <= en) {
        int num = 0;
        long long mid = ((st + en) / 2);
        for (int i = 0; i < K; i++)
            num += arr[i] / mid;
        if (num >= N) {
            st = mid + 1;
            result = mid;
        } else
            en = mid - 1;
    }
    std::cout << result << std::endl;
    return (0);
}

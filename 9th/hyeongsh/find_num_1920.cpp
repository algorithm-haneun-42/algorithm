
#include <algorithm>
#include <iostream>

int arr[100001];
int find_num(int N, int tmp);

int main(void) {
    int N;
    int M;

    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + N);
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        std::cin >> tmp;
        std::cout << find_num(N, tmp) << '\n';
    }
    return (0);
}

int find_num(int N, int tmp) {
    int st = 0;
    int en = N - 1;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (arr[mid] == tmp) {
            return (1);
        } else if (arr[mid] > tmp) {
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return (0);
}
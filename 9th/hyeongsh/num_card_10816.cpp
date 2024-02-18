
#include <algorithm>
#include <iostream>

int N;
int M;
int arr[500001];

int find_st(int tmp);
int find_en(int tmp);

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int tmp;

    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    std::sort(arr, arr + N);
    arr[N] = 10000001;
    std::cin >> M;
    for (int i = 0; i < M - 1; i++) {
        std::cin >> tmp;
        std::cout << find_en(tmp) - find_st(tmp) << ' ';
    }
    std::cin >> tmp;
    std::cout << find_en(tmp) - find_st(tmp) << '\n';
}

int find_st(int tmp) {
    int st = 0;
    int en = N;

    while (st < en) {
        int mid = (st + en) / 2;
        if (arr[mid] < tmp)
            st = mid + 1;
        else
            en = mid;
    }
    return (st);
}

int find_en(int tmp) {
    int st = 0;
    int en = N;

    while (st < en) {
        int mid = (st + en) / 2;
        if (arr[mid] > tmp)
            en = mid;
        else
            st = mid + 1;
    }
    return (en);
}

// -10 -10 2 3 3 6 7 10 10 10

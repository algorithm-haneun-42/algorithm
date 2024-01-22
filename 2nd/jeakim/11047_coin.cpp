#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int K;
    int s;
    int count;
    int div;
    vector<int> num;

    //입력
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        num.push_back(s);
    }
    //
    count = 0;
    for (int i = num.size() - 1; i >= 0 && K >= 0; i--)
    {
        div = K / num[i];
        count += div;
        K -= div * num[i];
    }
    cout << count << endl;
    return (0);
}
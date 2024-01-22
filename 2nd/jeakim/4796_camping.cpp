#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int count_days(vector<int> day)
{
    int div;
    int mod;

    div = day[2] / day[1];
    mod = day[2] % day[1];
    if (mod < day[0])
        return (div * day[0] + mod);
    return (div * day[0] + day[0]);
}

int main()
{
    vector<int> day;
    int n;

    for (int i = 1; ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> n;
            day.push_back(n);
        }
        if (accumulate(day.begin(), day.end(), 0) == 0)
            break;
        cout << "Case " << i << ": " << count_days(day) << endl;
        day.clear();
    }
    return (0);
}
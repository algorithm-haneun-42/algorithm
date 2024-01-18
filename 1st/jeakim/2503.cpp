#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//숫자 n의 strike 구하기
int check_strike(vector<int> n, vector<vector<int> > ex, int N)
{
    int strike;
    
    strike = 0;
    for (int i = 0; i < 3; i++)
        if (n[i] == ex[N][i])
            strike++;
    return (strike);
}

//숫자n의 ball 구하기
int check_ball(vector<int> n, vector<vector<int> > ex, int N)
{
    int ball;

    ball = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (n[i] == ex[N][j] && i != j)
                ball++;
    return (ball);
}

//숫자n이 예제ex와 strike, ball값이 일치하는지 확인
int check_num(vector<int> n, vector<vector<int> > ex, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (check_strike(n, ex, i) != ex[i][3])
            return (0);
        if (check_ball(n, ex, i) != ex[i][4])
            return (0);
    }
    return (1);
}

//9P3 : 123~987까지 모든 수 구하기
int make_allNum(vector<int> num, vector<vector<int> > ex, int N)
{
    int count;
    vector<int> n;

    count = 0;
    do{
        n.clear();
        for (int i = 0; i < 3; i++)
            n.push_back(num[i]);
        if (check_num(n, ex, N) == 1)
            count++;
        reverse(num.begin() + 3, num.end());
    } while (next_permutation(num.begin(), num.end()));
    return (count);
}

// int main()
// {
//     int N;
//     int n;
//     vector<int> num;
//     vector<vector<int> > ex;

//     //input
//     cin >> N;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cin >> n;
//             if (j == 0)
//             {
//                 num.push_back(n / 100);
//                 num.push_back((n % 100) / 10);
//                 num.push_back((n % 10));
//             }
//             else
//                 num.push_back(n);
//         }
//         ex.push_back(num);
//         num.clear();
//     }
//     //순열 permutation
//     for(int i = 1; i < 10; i++)
//         num.push_back(i);
//     sort(num.begin(), num.end());
//     cout << make_allNum(num, ex, N) << endl;

//     return (0);
// }
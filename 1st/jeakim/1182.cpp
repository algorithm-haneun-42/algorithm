#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int check_seq(vector<int> nums, vector<int> sub, int S)
{
	int sum;
    int count;

    count = 0;
	do{
        sum = 0;
		for(int i = 0; i < nums.size(); i++)
			if (sub[i] == 1)
				sum += nums[i];
        if (sum == S)
            count++;
	} while (next_permutation(sub.begin(), sub.end()));
    return (count);
}

// int main()
// {
//     int N;
//     int S;
//     int count;
//     vector<int> nums;
//     vector<int> sub;

//     //input
//     cin >> N >> S;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> count;
//         nums.push_back(count);
//     }
//     //순열 permutation
//     count = 0;
//     for (int i = 1; i <= N; i++)
//     {
//         sub.clear();
//         //i개만큼의 1
//         for (int j = 0; j < i; j++)
//             sub.push_back(1);
//         //N - i개만큼의 0
//         for (int j = 0; j < N - i; j++)
//             sub.push_back(0);
//         sort(nums.begin(), nums.end());
//         sort(sub.begin(), sub.end());
//         count += check_seq(nums, sub, S);
//     }
//     cout << count << endl;
//     return (0);
// }

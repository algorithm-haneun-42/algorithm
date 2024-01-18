#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void ft_print(vector<int> dwarfs, vector<int> seven_dwarfs)
{
	for (int i = 0; i < seven_dwarfs.size(); i++)
		if (seven_dwarfs[i] == 1)
			cout << dwarfs[i] << endl;
}

void find_dwarfs(vector<int> dwarfs, vector<int> seven_dwarfs)
{
	int sum;

	do{
		sum = 0;
		for(int i = 0; i < dwarfs.size(); i++)
			if (seven_dwarfs[i] == 1)
				sum += dwarfs[i];
		if (sum == 100)
		{
			ft_print(dwarfs, seven_dwarfs);
			break;
		}
	} while (next_permutation(seven_dwarfs.begin(), seven_dwarfs.end()));
}

int main()
{
	int n;
    vector<int> dwarfs;
	vector<int> seven_dwarfs;

    //입력
    for (int i = 0; i < 9; i++)
	{
        cin >> n;
		dwarfs.push_back(n);
	}
	for (int i = 0; i < 7; i++)
		seven_dwarfs.push_back(1);
	for (int i = 0; i < 2; i++)
		seven_dwarfs.push_back(0);
    //정렬
    sort(dwarfs.begin(), dwarfs.end());
	sort(seven_dwarfs.begin(), seven_dwarfs.end());
	//7난쟁이 찾기
	find_dwarfs(dwarfs, seven_dwarfs);
    return (0);
}

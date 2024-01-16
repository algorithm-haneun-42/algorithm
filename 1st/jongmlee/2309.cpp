#include <iostream>
#include <algorithm>

using namespace std;

int	main()
{
	int	dwarp[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> dwarp[i];
		sum += dwarp[i];
	}
	sort(dwarp, dwarp + 9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - dwarp[i] - dwarp[j] == 100)
			{
				dwarp[i] = -1;
				dwarp[j] = -1;
				break;
			}
		}
		if (dwarp[i] == -1)
			break;
	}
	for (int i = 0; i < 9; i++)
	{
		if (dwarp[i] != -1)
			cout << dwarp[i] << endl;
	}
}


#include <iostream>

int		array_init(char arr[900][4]);
void	check_correct_num(char num[4], char arr[900][4], int strike, int ball, int k);

int	main(void)
{
	int		question;
	char	num[4];
	int		strike;
	int		ball;
	char	arr[900][4];
	int		k;
	int		sum = 0;

	k = array_init(arr);
	std::cin >> question;
	for (int i = 0; i < question; i++)
	{
		std::cin >> num;
		std::cin >> strike;
		std::cin >> ball;
		check_correct_num(num, arr, strike, ball, k);
	}
	for (int i = 0; i < k; i++)
	{
		if (arr[i][0] != '0')
			sum++;
	}
	std::cout << sum << std::endl;
}

int	array_init(char arr[900][4])
{
	int	k = 0;

	for (int x = 1; x < 10; x++)
	{
		for (int y = 1; y < 10; y++)
		{
			for (int z = 1; z < 10; z++)
			{
				arr[k][0] = '0';
				arr[k][1] = '0';
				arr[k][2] = '0';
				arr[k][3] = 0;
				if (x != y && y != z && z != x)
				{
					arr[k][0] = x + '0';
					arr[k][1] = y + '0';
					arr[k][2] = z + '0';
				}
				k++;
			}
		}
	}
	return (k);
}

void	check_correct_num(char num[4], char arr[900][4], int strike, int ball, int k)
{
	for (int j = 0; j < k; j++)
		{
			int	s = 0;
			int	b = 0;

			if (arr[j][0] == '0')
				continue ;
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					if (num[x] == arr[j][y])
					{
						if (x == y)
							s++;
						else
							b++;
					}
				}
			}
			if (s != strike || b != ball)
				arr[j][0] = '0';
		}
}

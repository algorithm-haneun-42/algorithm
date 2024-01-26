
#include <iostream>
#include <string>
#include <stack>

int	main(void)
{
	int	n;
	int	ans = 0;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::stack<char>	good;
		std::string			word;

		std::cin >> word;
		int	j = -1;
		while (++j < word.size())
		{
			if (word[j] == 'A' && !good.empty() && good.top() == 'A')
				good.pop();
			else if (word[j] == 'A')
				good.push('A');
			if (word[j] == 'B' && !good.empty() && good.top() == 'B')
				good.pop();
			else if (word[j] == 'B')
				good.push('B');
		}
		if (j == word.size() && good.empty())
			ans++;
	}
	std::cout << ans << std::endl;
}

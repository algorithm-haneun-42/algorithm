
#include <iostream>
#include <stack>

int	main(void)
{
	std::string	buf;
	std::stack<char>	stick;
	int	ans = 0;
	int	laser = 0;

	std::cin >> buf;
	for (int i = 0; i < buf.size(); i++)
	{
		if (buf[i] == '(')
		{
			stick.push('(');
			laser = 0;
		}
		if (buf[i] == ')')
		{
			if (laser == 0)
				ans += stick.size() - 1;
			else if (laser == 1)
				ans += 1;
			stick.pop();
			laser = 1;
		}
	}
	std::cout << ans << std::endl;
}

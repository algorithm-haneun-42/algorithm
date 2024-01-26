
#include <iostream>
#include <stack>
#include <string>

int	main(void)
{
	std::string	buf;

	while (42)
	{
		getline(std::cin, buf);
		if (buf[0] == '.' && buf.size() == 1)
			break ;
		int	i = -1;
		std::stack<char>	world;
		while (buf[++i] != '.')
		{
			if (buf[i] == '(')
				world.push('(');
			if (buf[i] == '[')
				world.push('[');
			if (buf[i] == ')' && !world.empty() && world.top() == '(')
				world.pop();
			else if (buf[i] == ')')
				break ;
			if (buf[i] == ']' && !world.empty() && world.top() == '[')
				world.pop();
			else if (buf[i] == ']')
				break ;
		}
		if (buf[i] != '.' || !world.empty())
			std::cout << "no" << std::endl;
		else
			std::cout << "yes" << std::endl;
	}
}

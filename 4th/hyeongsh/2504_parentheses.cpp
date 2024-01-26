
#include <iostream>
#include <stack>
#include <string>
/*
int	main(void)
{
	std::string	str;
	std::stack<int>	pare;
	int	ans;

	std::cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			pare.push(-1);
		if (str[i] == '[')
			pare.push(-2);
		if (str[i] == ')')
		{
			int	num = 0;
			while (!pare.empty() && pare.top() > -1)
			{
				num += pare.top();
				pare.pop();
			}
			if (pare.empty() || pare.top() == -2)
			{
				std::cout << 0 << std::endl;
				return (0);
			}
			pare.pop();
			if (num == 0)
				num = 1;
			pare.push(num * 2);
		}
		if (str[i] == ']')
		{
			int	num = 0;
			while (!pare.empty() && pare.top() > -1)
			{
				num += pare.top();
				pare.pop();
			}
			if (pare.empty() || pare.top() == -1)
			{
				std::cout << 0 << std::endl;
				return (0);
			}
			pare.pop();
			if (num == 0)
				num = 1;
			pare.push(num * 3);
		}
	}
	while (!pare.empty())
	{
		if (pare.top() < 0)
		{
			std::cout << 0 << std::endl;
			return (0);
		}
		ans += pare.top();
		pare.pop();		
	}
	std::cout << ans << std::endl;
	return (0);
}*/

int	main() 
{
	std::string	a;
	std::stack<char>	st;

	std::cin >> a;
	int	sum = 0;
	int	num = 1;
	for (int i = 0; i < a.size(); i++)
	{
		if(a[i] == '(')
		{
			st.push(a[i]);
			num *= 2;
		}
		else if(a[i] == '[')
		{
			st.push(a[i]);
			num *= 3;
		}
		else if (a[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				std::cout << 0 << std::endl;
				return (0);
			}
			if (a[i - 1] == '(')
				sum+=num;
			st.pop();
			num /= 2;
		}
		else
		{
			if (st.empty() || st.top() != '[')
			{
				std::cout << 0 << std::endl;
				return (0);
			}
			if (a[i - 1] == '[')
				sum+=num;
			st.pop();
			num /= 3;
		}
	}
	if (st.empty())
		std::cout << sum << std::endl;
	else 
		std::cout << 0 << std::endl;
	return (0);
}

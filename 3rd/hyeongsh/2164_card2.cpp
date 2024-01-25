
#include <iostream>
#include <deque>

int	main(void)
{
	int				n;
	std::deque<int>	deq;

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		deq.push_back(i);
	while (deq.size() > 1)
	{
		deq.pop_front();
		int	card = deq.front();
		deq.pop_front();
		deq.push_back(card);
	}
	std::cout << deq.front() << std::endl;
	return (0);
}


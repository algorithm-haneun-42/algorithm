
#include <iostream>

typedef	struct s_list
{
	int		x;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

class	Deque
{
	private:
		t_list	*head;
		t_list	*tail;
		int		size;
	
	public:
		Deque()
		{
			head = NULL;
			tail = NULL;
			size = 0;
		}
		~Deque()
		{
			t_list	*tmp;

			for (int i = 0; i < size; i++)
			{
				tmp = head;
				head = head->next;
				delete tmp;
			}
		}
		void	push_front(int num)
		{
			t_list	*tmp = new t_list;
			if (tmp == NULL)
				return ;
			
			tmp->x = num;
			tmp->prev = NULL;
			if (size == 0)
			{
				tmp->next = NULL;
				tail = tmp;
			}
			else
			{
				tmp->next = head;
				head->prev = tmp;
			}
			head = tmp;
			size++;
		}
		void	push_back(int num)
		{
			t_list	*tmp = new t_list;
			if (tmp == NULL)
				return ;
			
			tmp->x = num;
			tmp->next = NULL;
			if (size == 0)
			{
				tmp->prev = NULL;
				head = tmp;
			}
			else
			{
				tmp->prev = tail;
				tail->next = tmp;
			}
			tail = tmp;
			size++;
		}
		void	pop_front()
		{
			t_list	*tmp;

			if (size == 0)
			{
				std::cout << -1 << std::endl;
				return ;
			}
			size--;
			tmp = head;
			if (size == 0)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				head = head->next;
				head->prev = NULL;
			}
			std::cout << tmp->x << std::endl;
			delete tmp;
		}
		void	pop_back()
		{
			t_list	*tmp;

			if (size == 0)
			{
				std::cout << -1 << std::endl;
				return ;
			}
			size--;
			tmp = tail;
			if (size == 0)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			std::cout << tmp->x << std::endl;
			delete tmp;
		}
		void	is_size()
		{
			std::cout << size << std::endl;
		}
		void	empty()
		{
			if (size == 0)
				std::cout << 1 << std::endl;
			else
				std::cout << 0 << std::endl;
		}
		void	front()
		{
			if (size == 0)
				std::cout << -1 << std::endl;
			else
				std::cout << head->x << std::endl;
		}
		void	back()
		{
			if (size == 0)
				std::cout << -1 << std::endl;
			else
				std::cout << tail->x << std::endl;
		}
};

int	main(void)
{
	int		N;
	Deque	deq;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::string	str;

		std::cin >> str;
		if (str == "front")
			deq.front();
		if (str == "back")
			deq.back();
		if (str == "size")
			deq.is_size();
		if (str == "empty")
			deq.empty();
		if (str == "pop_front")
			deq.pop_front();
		if (str == "pop_back")
			deq.pop_back();
		if (str.substr(0, 9) == "push_back")
		{
			int	k;

			std::cin >> k;
			deq.push_back(k);
		}
		if (str.substr(0, 10) == "push_front")
		{
			int	k;

			std::cin >> k;
			deq.push_front(k);
		}
	}
}
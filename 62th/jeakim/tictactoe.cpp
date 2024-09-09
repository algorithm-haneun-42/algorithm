#include <iostream>
#include <vector>

using namespace std;

pair<int, int> count_num(string s)
{
	pair<int, int> cnt;

	cnt.first = 0;
	cnt.second = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'X')
			cnt.first++;
		else if (s[i] == 'O')
			cnt.second++;
	}
	return (cnt);
}

int check_x(string in)
{
	for (int i = 0; i < 3; i++)
	{
		if ((in[i * 3] == 'X') && (in[i * 3 + 1] == 'X') && (in[i * 3 + 2] == 'X'))
			return (1);
		if ((in[i] == 'X') && (in[3 + i] == 'X') && (in[6 + i] == 'X'))
			return (1);
	}
	if ((in[2] == 'X') && (in[4] == 'X') && (in[5] == 'X'))
		return (1);
	if ((in[0] == 'X') && (in[4] == 'X') && (in[8] == 'X'))
		return (1);
	return (-1);
}

int check_o(string in)
{
	for (int i = 0; i < 3; i++)
	{
		if ((in[i * 3] == 'O') && (in[i * 3 + 1] == 'O') && (in[i * 3 + 2] == 'O')) //가로
			return (0);
		if ((in[i] == 'O') && (in[3 + i] == 'O') && (in[6 + i] == 'O')) //세로
			return (0);
	}
	if ((in[0] == 'O') && (in[4] == 'O') && (in[8] == 'O'))
		return (0);
	if ((in[2] == 'O') && (in[4] == 'O') && (in[5] == 'O'))
		return (0);
	return (-1);
}

int	solution(string in)
{
	pair<int, int> cnt;

	cnt = count_num(in);
	// if (abs(cnt.first - cnt.second) > 1)
	// 	return (-1);
	// if (cnt.first < 3)
	// 	return (-1);
	// if (cnt.first < cnt.second)
	// 	return (-1);
	// if (check_o(in) == 0 && (cnt.first > cnt.second))
	// 	return (-1);
	// if (check_x(in) == 1 && check_o(in) == 0)
	// 	return (-1);
	// if (check_x(in) == -1 && check_o(in) == 0 && ((cnt.first + cnt.second) == 9))
	// 	return (-1);
	// if (check_x(in) == -1 && check_o(in) == -1 && cnt.first < 5)
	// 	return (-1);
	if (check_x(in) == 1 && check_o(in) == -1 && (cnt.first == (cnt.second + 1)))
		return (1);
	if (check_x(in) == -1 && check_o(in) == 0 && (cnt.first == cnt.second))
		return (1);
	if (check_x(in) == -1 && check_o(in) == -1 && (cnt.first == 5) && (cnt.second == 4))
		return (1);
	return (-1);
}

int main()
{
	while (42)
	{
		string in;
	
		cin >> in;
		if (in.compare("end") == 0)
			break ;
		if (solution(in) == -1)
			cout << "invalid" << endl;
		else
			cout << "valid" << endl;
	}
	return (0);
}
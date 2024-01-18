#include <iostream>
#include <algorithm>

using namespace std;

int	get_longest_width(char **board, int i, int j);
int	get_longest_height(char **board, int i, int j);
void	move_right(char **board, int i, int j);
void	move_down(char **board, int i, int j);
int	get_max_len(char **board, int i, int j, int len);

int n;
int main()
{
	int len, width, height;
	cin >> n;
	char **board = new char*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[n];
	}
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	len = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			len = get_max_len(board, i, j, len);
			if (j + 1 < n) {
				move_right(board, i, j);
				len = get_max_len(board, i, j, len);
				height = get_longest_height(board, i, j + 1);
				len = max(len, height);
				move_right(board, i, j);
			}
			if (i + 1 < n) {
				move_down(board, i, j);
				len = get_max_len(board, i, j, len);
				width = get_longest_width(board, i + 1, j);
				len = max(len, width);
				move_down(board, i, j);
			}
		}
	}
	cout << len << endl;
	return 0;
}

int	get_max_len(char **board, int i, int j, int len)
{
	int width = get_longest_width(board, i, j);
	int height = get_longest_height(board, i, j);
	return max(max(width, height), len);
}

int	get_longest_width(char **board, int i, int j)
{
	int	cnt = 0;
	for (int x = j; x < n; x++) {
		if (board[i][x] != board[i][j]) {
			break ;
		}
		cnt++;
	}
	for (int x = j - 1; x >= 0; x--) {
		if (board[i][x] != board[i][j]) {
			break ;
		}
		cnt++;
	}
	return cnt;
}

int	get_longest_height(char **board, int i, int j)
{
	int	cnt = 0;
	for (int x = i; x < n; x++) {
		if (board[x][j] != board[i][j]) {
			break ;
		}
		cnt++;
	}
	for (int x = i - 1; x >= 0; x--) {
		if (board[x][j] != board[i][j]) {
			break ;
		}
		cnt++;
	}
	return cnt;
}

void	move_right(char **board, int i, int j)
{
	char tmp = board[i][j];
	board[i][j] = board[i][j + 1];
	board[i][j + 1] = tmp;
}

void	move_down(char **board, int i, int j)
{
	char tmp = board[i][j];
	board[i][j] = board[i + 1][j];
	board[i + 1][j] = tmp;
}


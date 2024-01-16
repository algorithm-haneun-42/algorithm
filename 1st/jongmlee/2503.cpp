#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool	is_dup_card(int n);
bool	compare(int backup_card, int cur_card, int s, int b);
int	main()
{
	int	n, cards, s, b;

	vector<int> v;
	for (int i = 123; i <= 987; i++) {
		if (!is_dup_card(i)) // 중복 숫자 카드인지 검사
			v.push_back(i);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cards >> s >> b;
		for (int j = 0; j < v.size(); j++) {
			if (!compare(v.at(j), cards, s, b)) {
				v.erase(v.begin() + j);
				j--;
			}
		}
	}
	cout << v.size() << endl;
}

bool	is_dup_card(int n)
{
	int n1 = n / 100; // 100의 자리 수
	int n2 = (n % 100) / 10; // 10의 자리 수
	int n3 = (n % 10); // 1의 자리 수

	if (n1 == 0 || n2 == 0 || n3 == 0)
		return true;
	if (n1 != n2 && n2 != n3 && n1 != n3)
		return false;
	return true;
}

bool	compare(int backup_card, int cur_card, int s, int b)
{
	int bc[3];
	bc[0] = backup_card / 100;
	bc[1] = (backup_card % 100) / 10;
	bc[2] = backup_card % 10;
	int	cc[3];
	cc[0] = cur_card / 100;
	cc[1] = (cur_card % 100) / 10;
	cc[2] = cur_card % 10;
	
	int	strike = 0;
	int	ball = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (bc[i] == cc[j]) {
				if (i == j)
					strike++;
				else
					ball++;
			}
		}
	}
	if (strike == s && ball == b) {
		return true;
	}
	return false;
}

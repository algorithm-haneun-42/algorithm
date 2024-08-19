#include <iostream>
#include <vector>

using namespace std;

int n, m;
double m_d;
int arr[5001][5001] = {0};

int main()
{
	while (42)
	{
		int n, m;
		double m_d;
		cin >> n >> m_d;
		if (n == 0 && m_d == 0.00)
			break ;
		m = m_d * 100 + 0.5;

		vector<pair<int, int> > candy;
		for (int i = 0; i < n; i++){
			int c;
			double p;
			cin >> c >> p;
			candy.push_back({c, p * 100 + 0.5});
		}
		for (int i = 0; i < n; i++){
			for (int j = 1; j <= m; j++)
			{
				int cur_weight = candy[i - 1].first;
				int cur_val = candy[i - 1].second;

				if (cur_weight <= j)
					arr[i][j] = max(arr[i - 1][j - cur_weight] + cur_val, arr[i - 1][j]);
				else
					arr[i][j] = arr[i - 1][j];
			}
		}
		cout << arr[n][m] << endl;
	}

	return (0);  
}
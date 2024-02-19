#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	pair<long, long> min_pair;
	vector<long> alkali;
	vector<long> acid;
	long n, k;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		if (k < 0)
			alkali.push_back(k);
		else
			acid.push_back(k);
	}
	for (int i = 0; i < alkali.size(); i++)
	{
		pair<long, long> upper;
		upper = make_pair(alkali[i], upper_bound(acid.begin(), acid.end(), -alkali[i]));
		pair<long, long> lower;
		lower = make_pair(alkali[i], lower_bound(acid.begin(), acid.end(), -alkali[i]));

		pair<long, long> cur;
		cur.first = (abs(upper.first + upper.second) > abs(lower.first + lower.second) ? lower.first : upper.first);
		cur.second = (abs(upper.first + upper.second) > abs(lower.first + lower.second) ? lower.second : upper.second);

		pair<long, long> temp;
		temp.first = (abs(cur.first + cur.second) > abs(min_pair.first + min_pair.second) ? min_pair.first : cur.first);
		temp.second = (abs(cur.first + cur.second) > abs(min_pair.first + min_pair.second) ? min_pair.second : cur.second);

		min_pair.first = temp.first;
		min_pair.second = temp.second;
	}
	//
	if (alkali.size() >= 2)
	{
		pair<long, long> temp;
		temp.first = (abs(alkali[alkali.size() - 1] + alkali[alkali.size() - 2]) > abs(min_pair.first + min_pair.second) ? min_pair.first : alkali[alkali.size() - 2]);
		temp.second = (abs(alkali[alkali.size() - 1] + alkali[alkali.size() - 2]) > abs(min_pair.first + min_pair.second) ? min_pair.second : alkali[alkali.size() - 1]);
		min_pair.first = temp.first;
		min_pair.second = temp.second;
	}
	if (acid.size() >= 2)
	{
		pair<long, long> temp;
		temp.first = (abs(acid[acid.size() - 1] + acid[acid.size() - 2]) > abs(min_pair.first + min_pair.second) ? min_pair.first : acid[acid.size() - 2]);
		temp.second = (abs(acid[acid.size() - 1] + acid[acid.size() - 2]) > abs(min_pair.first + min_pair.second) ? min_pair.second : acid[acid.size() - 1]);
		min_pair.first = temp.first;
		min_pair.second = temp.second;
	}
	cout << min_pair.first << ' ' << min_pair.second << '\n';
	return (0);
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
	vector<int> t_num;
	for(int a : topping)
		if (find(t_num.begin() , t_num.end(), a) == t_num.end())
			t_num.push_back(a);
	if (t_num.size()%2 == 1)
		return (0);
	vector<int> f_cnt;
	int n = 0;
	for(int i = 0; i < topping.size(); i++) {
		cout << "i = " << i << '\n';
		if (find(f_cnt.begin() , f_cnt.end(), topping[i]) == f_cnt.end())
			f_cnt.push_back(topping[i]);
		if (f_cnt.size() >= t_num.size()/2) {
			vector<int> b_cnt = {0};
			for(int j = i+1; j < topping.size(); j++)
				if (find(b_cnt.begin() , b_cnt.end(), topping[j]) == b_cnt.end())
					b_cnt.push_back(topping[j]);
			if (f_cnt.size() == b_cnt.size()-1)
				n++;
		}
	}
	return n;
}

int main(void) {
	vector<int> topping;
	topping = {1, 2, 1, 3, 1, 4, 1, 2};
	cout << solution(topping) << '\n';
}
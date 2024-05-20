#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
	bool operator() (string a, string b) {
		if (b.size() > a.size())
			a += a[a.size()-1];
		else if (b.size() < a.size())
			b += b[b.size()-1];
		return (a < b);
	}
};

// struct cmp{
// 	bool operator() (string a, string b) {
// 		if (a.size() == b.size())
// 			return (a < b);
// 		else if (b.size() > a.size()) {
// 			if ((a[a.size()-1] == b[b.size()-1]) && a[a.size()-1] > a[0])
// 				a += a[a.size()-1]+1;
// 			else a += a[a.size()-1];
// 			return (a < b);
// 		}
// 		else{
// 			if ((b[b.size()-1] == a[a.size()-1]) && b[b.size()-1] > b[0])
// 				b += a[a.size()-1]+1;
// 			else b += b[b.size()-1];
// 			return (a < b);
// 		}
// 	}
// };

string solution(vector<int> numbers) {
	priority_queue<string, vector<string>, cmp > num;
	int zero = 0;
	for(int n : numbers) {
		if (n != 0)
			zero = 1;
		num.push(to_string(n));
	}
	// while(!num.empty()) {
	// 	cout << num.top() << ' ';
	// 	num.pop();
	// }
	// cout << '\n';
	if (zero == 0)
		return ("0");
	string ans;	
	while(!num.empty()) {
		ans += num.top();
		num.pop();
	}
	return (ans);
}

int main(void) {
	vector<int> numbers = {555, 565, 566, 55, 56, 5, 59, 599, 549};
	cout << solution(numbers) << '\n';
}

//1000, 111, 110, 101, 100, 11, 10, 1, 0
//555, 565, 566, 55, 56, 5, 59, 599, 549

// 566 56 565 55 555 5 549 544 54
// 56656 565 55 555 5 549 54 544

/*
111 1 11 110 101 1000 100 10 0
111 1 11 110 101 10 100 1000 0

59 599 56 566 565 55 555 5 549 
599 59 566 56 565 55 555 5 549
*/
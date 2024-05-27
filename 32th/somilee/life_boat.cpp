#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
	sort(people.begin(), people.end());
	while (!people.empty()) {
		int i;
		for(i = people.size()-1; i > 0; i--) {
			if (people[0] + people[i] <= limit)
				break;
		}
		if (i != 0)
			people.erase(people.begin()+i);
		people.erase(people.begin());
		answer++;
	}
    return answer;
}

int main(void) {
	vector<int> people = {70, 80, 50};
	int limit = 100;
	cout << solution(people, limit) << endl;
}
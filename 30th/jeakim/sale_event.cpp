#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_zero(vector<int> number)
{
	for (int i = 0; i < number.size(); i++){
		if (number[i] != 0)
			return (0);
	}
	return (1);
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
	int turn = 0;

	for (int i = 0; i < discount.size() && i < 10; i++){
		for (int j = 0; j < want.size(); j++){
			if (discount[i] == want[j]){
				number[j]--;
				break;
			}
		}
	}
	if (check_zero(number) == 1)
		answer++;
	for (int i = 0, j = 10; i < discount.size() - 10 && j < discount.size(); i++, j++){
		for (int k = 0; k < want.size(); k++){
			if (discount[i] == want[k]){
				number[k]++;
				break;
			}
		}
		for (int k = 0; k < want.size(); k++){
			if (discount[j] == want[k]){
				number[k]--;
				break;
			}
		}
		if (check_zero(number) == 1)
			answer++;
	}
    return answer;
}

int main()
{
	vector<string> want = {"banana", "apple", "rice", "pork", "pot"};
	vector<int> number = {3, 2, 2, 2, 1};
	vector<string> discount = {"apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana", "chicken", "apple"};

	cout << solution(want, number, discount) << endl;

	return (0);
}
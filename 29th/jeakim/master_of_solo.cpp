#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// int count_second(vector<int> cards, int visited_first[101], int st)
// {
// 	int visited_second[101] = {0};
// 	int second = 1;
// 	int flag = cards[st] - 1;

// 	visited_second[st] = 1;
// 	while(visited_first[flag] == 0 && visited_second[flag] == 0)
// 	{
// 		visited_second[flag] = 1;
// 		flag = cards[flag] - 1;
// 		second++;
// 	}
// 	return (second);
// }

// int count_score(vector<int>  cards, int st)
// {
// 	int first = 1;
// 	int second = 0;
// 	int visited_first[101] = {0};
// 	int flag = cards[st] - 1;

// 	visited_first[st] = 1;
// 	while(flag != st)
// 	{
// 		visited_first[flag] = 1;
// 		flag = cards[flag] - 1;
// 		first++;
// 	}
// 	if (first == cards.size())
// 		return (0);
// 	for (int i = 0; i < cards.size(); i++)
// 		if (visited_first[i] == 0)
// 			second = max(second, count_second(cards, visited_first, i));
// 	return (first * second);
// }

// int solution(vector<int> cards) {
//     int answer = 0;

// 	for (int i = 0; i < cards.size(); i++)
// 		answer = max(answer, count_score(cards, i));

//     return answer;
// }

int solution(vector<int> cards) {
    int answer = 0;
	int score[101] = {0};

	for (int i = 0; i < cards.size(); i++)
		score[i] = count_score(cards);

    return answer;
}

int main()
{
	vector<int> cards = {8, 6, 3, 7, 2, 5, 1, 4};

	cout << solution(cards) << endl;

	return (0);
}
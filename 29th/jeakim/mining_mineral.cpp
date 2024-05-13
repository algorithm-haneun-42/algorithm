#include <string>
#include <vector>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
	int pickax = 0;
	int point[10][3] = {0};
	//dia, iron, stone
	for (int i = 0; i < picks.size(); i++)
		pickax++;
	for (int i = 0; i < pickax && minerals.size()

    return answer;
}
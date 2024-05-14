#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int prgs = 0;

    for (int d = 0; prgs < progresses.size(); d++){
        for (int i = 0; i < progresses.size(); i++)
            progresses[i] += speeds[i];
        int p = 0;
        while(prgs < progresses.size() && progresses[prgs] >= 100){
            p++;
            prgs++;
        }
        if (p > 0)
            answer.push_back(p);
    }
	
    return answer;
}

int main()
{
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    vector<int> answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';

    return (0);
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(string s1, string s2){
        int i = 0;
        while (i < s1.size() && i < s2.size()){
            if (s1[i] != s2[i])
                break;
            i++;
        }
        if (i >= s1.size()){
            s1[i] = s2[0];
            if (s1[i] == s2[i])
                return (s1.length() < s2.length());
        }
        if (i >= s2.size()){
            s2[i] = s1[0];
            if (s1[i] == s2[i])
                return (s1.length() < s2.length());
        }
        return (s1[i] < s2[i]);
    }
};

int check_zero(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '0')
            return (0);
    return (1);
}

string solution(vector<int> numbers) {
    string answer = "";
	priority_queue<string, vector<string>, cmp> pq;

    for (int i = 0; i < numbers.size(); i++)
        pq.push(to_string(numbers[i]));
    while (!pq.empty()){
        answer += pq.top();
        pq.pop();
    }
    if (check_zero(answer) == 1)
        answer = "0";
    return answer;
}

int main()
{
    //vector<int> numbers = {979, 97, 978, 81, 818, 817};
    vector<int> numbers = {110, 1};
    cout << solution(numbers) << endl;

    return (0);
}
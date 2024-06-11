#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct s_time{
	double h;
	double m;
	double s;
}t_time;

s_time getTime(int h, int m, int s){
	s_time t;

	t.h = 5 * h + m / 12 + s / 60;
	t.m = m + s / 60;
	t.s = s;
	return (t);
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
	s_time str = getTime(h1, m1, s1);
	s_time end = getTime(h2, m2, s2);
	s_time cur = {(double)h1, (double)m1, (double)s1};

	while (str.h != end.h || str.m != end.m || str.s != end.s){
		if (str.h == str.s && str.m == str.s)
			answer++;
		else if (str.h == str.s)
			answer++;
		else if (str.m == str.s)
			answer++;
		cur.s++;
		if (cur.s == 60){
			cur.s = 0;
			cur.m++;
		}
		if (cur.m == 60){
			cur.m = 0;
			cur.h++;
		}
		str = getTime(cur.h, cur.m, cur.s);
	}
    return answer;
}

int main()
{
	int h1, m1, s1, h2, m2, s2;

	h1 = 1; m1 = 5; s1 = 5;
	h2 = 1; m2 = 5; s2 = 6;

	cout << solution(h1, m1, s1, h2, m2, s2) << endl;

	return (0);
}
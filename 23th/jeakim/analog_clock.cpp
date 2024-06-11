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

	t.h = 5 * (h % 12) + m * (1 / 12.0) + s * (1 / 60.0 / 12.0);
	t.m = m + s * (1 / 60.0);
	t.s = s;
	return (t);
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
	s_time before = getTime(h1, m1, s1);
	s_time after;

	while (h1 != h2 || m1 != m2 || s1 != s2){
		before = getTime(h1, m1, s1);
		s1++;
		after = getTime(h1, m1, s1);
		if (before.s <= before.m && after.s > after.m)
			answer++;
		if (before.s <= before.h && after.s > after.h && before.h != before.m)
			answer++;
		if (s1 == 60){
			s1 = 0;
			m1++;
		}
		if (m1 == 60){
			m1 = 0;
			h1++;
		}
	}
    if (after.m == after.s) answer++;
    return answer;
}
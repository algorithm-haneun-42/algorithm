#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;

	int h, m, s, cnt;

	h = 5 * h + m1 / 12 + s / 60;
	m = m1 + s / 60;
	s = s1;

	while (h != h2 && m != m2 && s != s2){
		if (h == s && m == s)
			answer++;
		else if (h == s)
			answer++;
		else if (m == s)
			cnt++;
		if (s == 60){
			s == 0;
			m++;
		}
		if (m == 60){
			m == 0;
			h++;
		}
		s++;
	}

    return answer;
}

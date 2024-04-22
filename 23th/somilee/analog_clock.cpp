#include <iostream>
#include <string>
#include <vector>

using namespace std;

double h = 1.0/120;
double m = 1.0/10;
double s = 6.0;
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
	double h_num = (h2 - h1)/12.0;
	double m_num = h_num * 12.0 + (m2 - m1)/60.0;
	double s_num = m_num * 60.0 + (s2 - s1)/60.0;

	int num = int(s_num - h_num) + int(s_num - m_num);
	double h_start = (h1*60*60 + m1*60 + s1)*h - s1*s;
	double h_end = (h2*60*60 + m2*60 + s2)*h - s2*s;
	double m_start = (m1*60 + s1)*m - s1*s;
	double m_end = (m2*60 + s2)*m - s2*s;
	//cout << num << '\n';
	//cout << h_start << ' ' << h_end << ' ' << m_start << ' ' << m_end << '\n';
	if (h_start == 0.0 || h_start == 360.0)
		num++;
	if (h_end == 0.0 || h_end == 360.0)
		num++;
	if (m_start == 0.0 || m_start == 360.0)
		num++;
	if (m_end == 0.0 || m_end == 360.0)
		num++;
	//cout << num << '\n';
	if (int(s_num - h_num) < 1 && h_start * h_end < 0)
		num++;
	if (int(s_num - m_num) < 1 && m_start * m_end < 0)
		num++;
	//cout << num << '\n';
	if (h1 == 0 && m1 == 0 && s1 == 0)
		num--;
	if (h1 == 12 && m1 == 0 && s1 == 0)
		num--;
	if (h1 < 12 && h2 >= 12)
		num--;
	//cout << h_num << ' ' << m_num << ' ' << s_num << '\n';
	//cout << num << '\n';
	if (num == 0)
		return -1;
    return num;
}

int main(void)
{
	solution(0,0,0,23,59,59);
}
/*
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;

	double t_sec = (h2 - h1)*60*60 + (m2 - m1)*60 + s2 - s1;
	if (h1*h >= s1*s)
		double f_hs = (h1*h - s1*s)*120/719;
	else
		double f_hs = (h1*h - s1*s + 360)*120/719;
	if (m1*m >= s1*s)
		double f_ms = (m1*m - s1*s)*10/59;
	else
		double f_ms = (m1*m - s1*s + 360)*10/59;
    return answer;
}
*/
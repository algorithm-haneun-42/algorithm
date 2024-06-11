#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get_set(int n, int num)
{
	
}
int get_idx(int n, int num)
int get_bit(int n, int num)
int solution(int n, long long l, long long r) {
	pow(5,n);
	l  = 3
	r = 16;

	l = 1;
	r = 2;
    int answer = 0;
    return answer;
} 
// n = 2	l = 4	r = 17	 ret = 8



/*
solution(n, l, r):
	l_set(nth), l_num, l_bit <- get_set(n - 1, l);
	r_set(nth), l_num, l_bit <- get_set(n - 1, r);

	return get_sum(l_bit, l_num, 4)
		+ solution(n - 1, l_set + 1, r_set - 1) * 4
		+ get_sum(r_bit, 0, r_num)



*/
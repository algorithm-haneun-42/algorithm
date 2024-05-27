#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int ans = 0;
	for(int i = 1; i <= floor(n/2)+1; i++) {
		if (i%2 == 0){
			if ((n%(i/2) == 0) && ((n/(i/2)-1)%2 == 0) && ((n/(i/2)-1)/2 - (i/2-1) > 0)) {
				ans++;
				// cout << "i = " << i << ", ans = " << ans <<'\n';
			}
		}
		else
			if (n%i == 0)
			ans++;
	}
    return ans;
}

int main(void) {
	cout << solution(6) << '\n';
}

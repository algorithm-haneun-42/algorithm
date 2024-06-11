#include <string>
#include <vector>
#include <iostream>
using namespace std;

int binary(int n)
{
	int ret = 0;
	if(n == 0)
		return ret;
    while (n > 0) {
		(n % 2 == 0 ? ret+=0 : ret++);
        n /= 2;
    }
    return ret;
}

int solution(int n) {
	
	if(n == 1)
		return 2;
	int i = n +1;
	int cmpnum = binary(n);	
	while(1)
	{
		if (cmpnum == binary(i))
			break;
		i++;
	}
	return i;
}

int main(int argc, char** argv)
{

	cout  << solution(atoi(argv[1])) << endl;
}
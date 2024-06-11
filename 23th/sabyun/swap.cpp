#include <iostream>
using namespace std;
void swap (int *(&ptr),int *(&ptr2))
{
	int *temp;

	temp = ptr;
	ptr = ptr2;
	ptr2 = temp;
}
int main()
{
	int num = 5;
	int *ptr = &num;

	int num2 = 10;
	int *ptr2 = &num2;

	cout << *ptr << endl;
	cout << *ptr2 << endl;
	swap(ptr,ptr2);

	cout << *ptr << endl;
	cout << *ptr2 << endl;
	return 0;
}
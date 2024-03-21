#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_set <int> box;
	int n; cin >> n;
	long long total = 0;
	int pre = 0;	
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		box.insert(a);
		cout << "buket count " << box.bucket_count() << "buket size "<< box.bucket_size(0) << endl;
		cout << box. << endl;
	}
	for(int i = 0; i < 11; i++)
	{
		cout << "buket size "<< box.bucket_size(i) << endl;
	}
	cout << total << endl;
}
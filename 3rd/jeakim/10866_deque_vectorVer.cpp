#include <iostream>
#include <vector>

using namespace std;

class Deque
{
private:
	vector<int> v;
public:
	void push_front(int d){
		v.insert(v.begin(), d);
	}
	void push_back(int d){
		v.push_back(d);
	}
	void pop_front(){
		if (v.size() == 0)
			cout << "-1" << endl;
		else
		{
			cout << v.front() << endl;
			v.erase(v.begin());
		}
	}
	void pop_back(){
		if (v.size() == 0)
			cout << "-1" << endl;
		else
		{
			cout << v.back() << endl;
			v.erase(v.end() - 1);
		}
	}
	void issize(){
		cout << v.size() << endl;
	}
	void empty(){
		if (v.empty())
			cout << '1' << endl;
		else
			cout << '0' << endl;
	}
	void front(){
		if (v.size() == 0)
			cout << "-1" << endl;
		else
			cout << v[0] << endl;
	}
	void back(){
		if (v.size() == 0)
			cout << "-1" << endl;
		else
			cout << v.back() << endl;
	}
};

void deque_function(string s, Deque &deque)
{
	int d;

	if (s.compare("push_front") == 0)
	{
		cin >> d;
		deque.push_front(d);
	}
	else if (s.compare("push_back") == 0){
		cin >> d;
		deque.push_back(d);
	}
	else if (s.compare("pop_front") == 0)
		deque.pop_front();
	else if (s.compare("pop_back") == 0)
		deque.pop_back();
	else if (s.compare("size") == 0)
		deque.issize();
	else if (s.compare("empty") == 0)
		deque.empty();
	else if (s.compare("front") == 0)
		deque.front();
	else if (s.compare("back") == 0)
		deque.back();
}

int main()
{
	int N;
	Deque deque;
	string s;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> s;
		deque_function(s, deque);
	}
	return 0;
}

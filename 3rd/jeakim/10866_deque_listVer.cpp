#include <iostream>
#include <vector>

using namespace std;

struct node
{
	node* prev;
	node* next;
	int data;
};

class Deque
{
private:
	node* head;
	node* tail;
	size_t size;
public:
	Deque()
	{
		this->head = init(NULL);
		this->tail = init(NULL);
		this->head->next = this->tail;
		this->tail->prev = this->head;
		this->size = 0;
	} 
	node* init(int d){
		node* newNode = (node *)malloc(sizeof(node));
		newNode->prev = NULL;
		newNode->next = NULL;
		newNode->data = d;
	}
	void push_front(int d){
		node* newNode = init(d);
		newNode->next = this->head->next;
		this->head->next = newNode;
		newNode->prev = this->head;
		newNode->next->prev = newNode;
		size_plus();
	}
	void push_back(int d){
		node* newNode = init(d);
		newNode->prev = this->tail->prev;
		newNode->next = this->tail;
		newNode->prev->next = newNode;
		this->tail->prev = newNode;
		size_plus();
	}
	//여기부터 수정 필요
	void pop_front(){
		if (this->size == 0)
			cout << "-1" << endl;
		else
		{
			cout << v.front() << endl;
			v.erase(v.begin());
			size_minus();
		}
	}
	void pop_back(){
		if (this->size == 0)
			cout << "-1" << endl;
		else
		{
			cout << v.back() << endl;
			v.erase(v.end() - 1);
			size_minus();
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
	void size_plus(){
		this->size++;
	}
	void size_minus(){
		this->size--;
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
	string s;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> s;
		deque_function(s, deque);
	}
	return 0;
}

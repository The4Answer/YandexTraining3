//#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <ctime>



using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

//Nodes for every element of dequeue
struct Node {
	int value;
	Node* next = NULL;
	Node* prev = NULL;
};

//My dequeue
class Dequeue {
	Node* head;
	Node* tail;
public:
	Dequeue() {
		head = NULL;
		tail = NULL;
	};
	void push_front(int value);
	void push_back(int value);
	void pop_front();
	void pop_back();
	int front();
	int back();
	int size();
	void clear();
	void Exit();
	bool empty();
	~Dequeue();
};

bool Dequeue::empty() {
	return head == NULL;
}

void Dequeue::push_front(int value) {
	Node* tmp = new Node;
	tmp->value = value;
	if (head == NULL) {
		tail = tmp;
	}
	else {
		tmp->next = head;
		head->prev = tmp;
	}
	head = tmp;
}

void Dequeue::push_back(int value) {
	Node* tmp = new Node;
	tmp->value = value;
	if (head == NULL) {
		head = tmp;
	}
	else {
		tmp->prev = tail;
		tail->next = tmp;
	}
	tail = tmp;
}

void Dequeue::pop_front() {
	Node* tmp;
	tmp = head;
	head = head->next;
	if (!empty())					//Проверяем не пустой ли дэк, чтобы не пытаться в пустой ячейке забыть ссылку 
		head->prev = NULL;			//Надо удалить ссылку к блоку памяти, который мы собираемся удалить, иначе он будет туда обращаться, а там ничего не будет
	delete tmp;
}

void Dequeue::pop_back() {
	Node* tmp;
	tmp = tail;
	tail = tail->prev;
	if (!empty())					//Проверяем не пустой ли дэк, чтобы не пытаться в пустой ячейке забыть ссылку 
		tail->next = NULL;			//Надо удалить ссылку к блоку памяти, который мы собираемся удалить, иначе он будет туда обращаться, а там ничего не будет
	delete tmp;
}

int Dequeue::front() {
	return head->value;
}

int Dequeue::back() {
	return tail->value;
}

int Dequeue::size() {
	int ans = 0;
	Node* tmp = head;
	while (tmp) {
		ans++;
		tmp = tmp->next;
	}
	return ans;
}

void Dequeue::clear() {
	while (head) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
}

void Dequeue::Exit() {
	cout << "bye";
	exit(0);
}

Dequeue::~Dequeue() {
	while (head) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
}


int main() {
	Dequeue a;
	string s;
	while (cin >> s) {
		if (s == "push_front") {
			int tmp;
			cin >> tmp;
			a.push_front(tmp);
			cout << "ok" << "\n";
		}
		else if (s == "push_back") {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
			cout << "ok" << "\n";
		}
		else if (s == "pop_front") {
			if (a.empty())
				cout << "error" << "\n";
			else {
				cout << a.front() << "\n";
				a.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (a.empty())
				cout << "error" << "\n";
			else {
				cout << a.back() << "\n";
				a.pop_back();
			}
		}
		else if (s == "front") {
			if (a.empty())
				cout << "error" << "\n";
			else
				cout << a.front() << "\n";
		}
		else if (s == "back") {
			if (a.empty()) 
				cout << "error" << "\n";
			else
				cout << a.back() << "\n";
		}
		else if (s == "size") {
			cout << a.size() << "\n";
		}
		else if (s == "clear") {
			a.clear();
			cout << "ok" << "\n";
		}
		else if (s == "exit") {
			a.Exit();
		}
		else {
			cout << "Oooppss ERROR!!!";
			return 0;
		}
	}
	return 0;
}

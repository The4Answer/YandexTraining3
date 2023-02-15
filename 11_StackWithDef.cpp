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


int main() {
	stack <int> a;
	string s;
	while (s != "exit") {
		cin >> s;
		if (s == "push") {
			int tmp;
			cin >> tmp;
			a.push(tmp);
			cout << "ok" << "\n";
		}
		else if (s == "size") {
			cout << a.size() << "\n";
		}
		else if (s == "clear") {
			stack <int> emp;
			a = emp;
			cout << "ok" << "\n";
		}
		else if (s == "pop") {
			if (!a.empty()) {
				cout << a.top() << "\n";
				a.pop();
			}
			else {
				cout << "error" << "\n";
			}
		}
		else if (s == "back") {
			if (!a.empty()) {
				cout << a.top() << "\n";
			}
			else {
				cout << "error" << "\n";
			}
		}
		else
		{
			cout << "bye";
			return 0;
		}
	}

	return 0;
}

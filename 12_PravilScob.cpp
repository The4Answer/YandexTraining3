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
	stack <char> a;
	char t;
	while (cin >> t) {
		if (t == ')') {
			if (!a.empty() && a.top() == '(')
				a.pop();
			else {
				cout << "no";
				return 0;
			}
		}
		else if (t == ']') {
			if (!a.empty() && a.top() == '[')
				a.pop();
			else {
				cout << "no";
				return 0;
			}
		}
		else if (t == '}') {
			if (!a.empty() && a.top() == '{')
				a.pop();
			else {
				cout << "no";
				return 0;
			}
		}
		else 
			a.push(t);
		
	}
	if (a.empty())
		cout << "yes";
	else
		cout << "no";
	return 0;
}

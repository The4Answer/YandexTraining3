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
	stack <long long> a;
	string t;
	while (cin >> t) {
		if (t == "+") {
			int f = a.top();
			a.pop();
			int s = a.top();
			a.pop();
			f += s;
			a.push(f);
		} else if (t == "-") {
			int f = a.top();
			a.pop();
			int s = a.top();
			a.pop();
			s -= f;
			a.push(s);
		} else if (t == "*") {
			int f = a.top();
			a.pop();
			int s = a.top();
			a.pop();
			f *= s;
			a.push(f);
		}
		else {
			long long tmp = stoi(t);
			a.push(tmp);
		}
	}

	if (a.size() == 1)
		cout << a.top();
	else
		cout << "Error =(";

	return 0;
}

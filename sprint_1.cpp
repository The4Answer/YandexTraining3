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

int n, m;

struct st {
	int caunt;
	string name;
};

int main() {
	stack<st>a;
	map<string, long long> M;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "add") {
			st temp;
			cin >> temp.caunt >> temp.name;
			M[temp.name] += temp.caunt;
			a.push(temp);
		}
		else if (s == "delete") {
			int val;
			cin >> val;
			while (val > 0) {
				st temp = a.top();
				a.pop();
				if (temp.caunt > val) {
					temp.caunt -= val;
					a.push(temp);
					M[temp.name] -= val;
					val -= val;
				}
				else {
					val -= temp.caunt;
					M[temp.name] -= temp.caunt;
				}
			}
		}
		else if (s == "get") {
			string t;
			cin >> t;
			cout << M[t] << "\n";
		}
		else {
			cout << "Error";
			return 0;
		}
	}

	return 0;
}

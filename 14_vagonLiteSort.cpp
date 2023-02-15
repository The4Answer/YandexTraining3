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

int cur = 1;
stack <int> a;

void getGoods() {
	while (!a.empty()) {
		if (a.top() == cur) {
			a.pop();
			cur++;
		}
		else
			return;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		a.push(tmp);
		getGoods();
	}
	if (a.empty())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}

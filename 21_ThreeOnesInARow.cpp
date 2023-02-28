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

struct st {
	int x;
	int y;
};

int main() {
	int n;
	cin >> n;
	vector <int> zer(n);
	vector <int> one(n);
	zer[0] = 1;
	one[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (i == 1) {
			zer[i] += zer[i - 1] + one[i - 1];
			one[i] += zer[i - 1] + one[i - 1];
		}
		else {
			zer[i] += zer[i - 1] + one[i - 1];
			one[i] += zer[i - 1] + zer[i - 2];
		}
	}
	cout << zer[n - 1] + one[n - 1];
	return 0;
}

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
vector <vector<int>> a;
vector<int> used;
bool mark = false;

void dfs(int ind, int color) {
	used[ind] = color;
	for (int i = 0; i < a[ind].size(); ++i) {
		if (used[a[ind][i]] == color)
			mark = true;
		if (used[a[ind][i]] == 0) {
			dfs(a[ind][i], 3 - color);
		}
	}
}

int main() {
	cin >> n >> m;
	a.resize(n + 1);
	used.resize(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		int f, s;
		cin >> f >> s;
		a[f].push_back(s);
		a[s].push_back(f);
	}
	for (int i = 1; i <= n; ++i) {
		if (used[i] == 0) 
			dfs(i, 1);
	}
	if (mark)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}

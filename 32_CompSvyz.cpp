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
vector <int> ans;

void dfs(int ind) {
	used[ind] = 1;
	ans.push_back(ind);
	for (int i = 0; i < a[ind].size(); ++i) {
		if (used[a[ind][i]] == 0) {
			dfs(a[ind][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	a.resize(n + 1);
	used.resize(n + 1, 0);
	vector<vector<int>> forOut;
	for (int i = 0; i < m; ++i) {
		int f, s;
		cin >> f >> s;
		a[f].push_back(s);
		a[s].push_back(f);
	}
	for (int i = 1; i <= n; ++i) {
		ans.resize(0);
		if (used[i] == 0) 
			dfs(i);
		if (ans.size() != 0) 
			forOut.push_back(ans);
	}
	cout << forOut.size() << "\n";
	for (int i = 0; i < forOut.size(); ++i) {
		cout << forOut[i].size() << "\n";
		for (int j = 0; j < forOut[i].size(); ++j) 
			cout << forOut[i][j] << " ";
		cout << "\n";
	}
	return 0;
}

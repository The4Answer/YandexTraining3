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

void dfs(int ind) {
	used[ind] = 1;
	for (int i = 1; i <= n; ++i) {
		if (used[i] == 0 && a[ind][i] == 1) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;
	a.resize(n + 1);
	used.resize(n + 1, 0);
	for (int i = 0; i <= n; ++i)
		a[i].resize(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		int f, s;
		cin >> f >> s;
		a[f][s] = 1;
		a[s][f] = 1;
	}
	dfs(1);
	vector<int> ans;
	for (int i = 0; i <= n; ++i)
		if (used[i] == 1)
			ans.push_back(i);
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	return 0;
}

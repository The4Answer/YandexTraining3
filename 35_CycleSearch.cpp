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
int remember = 0;

void dfs(int ind, int prev) {
	used[ind] = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[ind][i] == 1) {
			if (used[i] == 0) {
				dfs(i, ind);
			}
			if (i != prev && i != ind && used[i] == 1 && remember == 0) {
				remember = i;
				break;
			}
		}
		if (ans.size() > 0)
			break;
	}
	if (remember != 0)
		ans.push_back(ind);
	if (remember == ind)
		remember = 0;
	used[ind] = 2;
}

int main() {
	cin >> n;
	a.resize(n + 1);
	used.resize(n + 1, 0);
	for (int i = 0; i <= n; ++i)
		a[i].resize(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		if (used[i] == 0) {
			dfs(i, 0);
			if (ans.size() > 0)
				break;
		}
	}
	if (ans.size() > 0) {
		cout << "YES" << "\n";
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << " ";
	}
	else {
		cout << "NO";
	}

	return 0;
}

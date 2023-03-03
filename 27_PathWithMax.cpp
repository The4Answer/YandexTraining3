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
	int a;
	int b;
	int c;
};

int main() {
	int n, m;
	int inf = 100000000;
	cin >> n >> m;
	vector < vector<int> > dp(n);
	vector < vector<int> > prev(n);
	vector < vector<int> > a(n);
	for (int i = 0; i < n; ++i) {
		dp[i].resize(m, -1);
		prev[i].resize(m, -1);
		a[i].resize(m, inf);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	dp[0][0] = a[0][0];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (i > 0 )
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
			if (j > 0)
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
		}
	cout << dp[n - 1][m - 1] << "\n";
	vector <char> ans;
	for (int z = 0, i = n - 1, j = m - 1; z < 20000; ++z) {
		if (i == 0 && j == 0)
			break;
		if (i > 0 && dp[i - 1][j] == dp[i][j] - a[i][j]) {
			i--;
			ans.push_back('D');
		}
		else {
			j--;
			ans.push_back('R');
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << " ";
	return 0;
}

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
	vector < vector<int> > a(n);
	for (int i = 0; i < n; ++i) {
		dp[i].resize(m, inf);
		a[i].resize(m, inf);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	dp[0][0] = a[0][0];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (i > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
			if (j > 0)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
		}
	cout << dp[n - 1][m - 1];

	return 0;
}

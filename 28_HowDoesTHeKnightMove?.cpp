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
	int n, m;
	cin >> n >> m;
	vector <vector <int>> dp(n);
	for (int i = 0; i < n; ++i)
		dp[i].resize(m, 0);
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 1 && j > 0) {
				dp[i][j] += dp[i - 2][j - 1];
			}
			if (i > 0 && j > 1)
				dp[i][j] += dp[i - 1][j - 2];
		}
	}
	cout << dp[n - 1][m - 1];

	return 0;
}

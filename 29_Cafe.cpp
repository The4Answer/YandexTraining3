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
	int n;
	int inf = 100000000;
	cin >> n;
	if (n == 0) {
		cout << "0" << "\n" << 0 << " " << 0;
		return 0;
	}
	int m = 2 * n;
	vector <vector <int>> dp(n);
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		dp[i].resize(m, inf);
		cin >> a[i];
	}
	if (a[0] <= 100)
		dp[0][0] = a[0];
	else
		dp[0][1] = a[0];
	/// ////////////////////////
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i] > 100) {
				if (j > 0)
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i]);
				if (j < m - 1)
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
			}
			else {
				if (j < m - 1)
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
			}
		}
	}
	int ind = m - 1;
	int k1 = 0;
	for (int i = m-1; i >=0; --i)
		if (dp[n - 1][i] < dp[n - 1][ind])
			ind = i;
	cout << dp[n - 1][ind] << "\n";
	k1 = ind;
	vector<int> ans;
	for (int i = n-1; i > 0; --i) {
		if (a[i] > 100) {
			if (ind > 0 && dp[i][ind] == dp[i - 1][ind - 1] + a[i]) {
				ind--;
			}
			else {
				ind++;
				ans.push_back(i + 1);
			}
		}
		else {
			if (ind + 1 < n && dp[i][ind] == dp[i - 1][ind + 1]) {
				ind++;
				ans.push_back(i + 1);
			}
		}
	}
	cout << k1 << " " << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << "\n";
	return 0;
}

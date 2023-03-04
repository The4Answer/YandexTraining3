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
	cin >> n;
	vector <vector <int>> dp(n);
	vector<int> f(n);
	for (int i = 0; i < n; ++i)
		cin >> f[i];
	cin >> m;
	vector<int> s(m);
	for (int i = 0; i < m; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		dp[i].resize(m, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (f[i] == s[j]) {
				if (i > 0 && j > 0)
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = 1;
			}
			else {
				if (i > 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				if (j > 0)
					dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
		}
	}
	vector<int> ans;
	int in = n - 1, im = m - 1;
	for (int i = 0; i < n + m + 2; ++i) {
		if (f[in] == s[im]) {
			ans.push_back(f[in]);
			if (in > 0 && im > 0) {
				in--;
				im--;
			}
			else
				break;
		}
		else {
			if (in > 0 && im > 0) {
				if (dp[in - 1][im] > dp[in][im - 1])
					in--;
				else
					im--;
			}
			else if (in > 0)
				in--;
			else if (im > 0) 
				im--;
			else
				break;
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << " ";
	return 0;
}

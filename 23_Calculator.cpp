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
	int k;
	int inf = 10000000;
	cin >> n >> k;
	vector <int> dp(n + 1, inf);
	vector <int> prev(n + 1, 0);
	dp[0] = 0;
	dp[1] = 0;
	prev[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3])
				prev[i] = i / 3;
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2])
				prev[i] = i / 2;
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i - 1 > 0) {
			if (dp[i] > dp[i - 1])
				prev[i] = i - 1;
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}
	}
	cout << dp[n] << "\n";
	int id = n;
	vector <int> ans;
	for (int i = n; i > 0; --i) {
		if (i == id) {
			ans.push_back(i);
			id = prev[i];
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << " ";
	return 0;
}

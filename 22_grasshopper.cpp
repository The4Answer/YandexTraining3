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
	cin >> n >> k;
	vector <int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (i - j >= 0)
				dp[i] += dp[i - j];
		}
	}
	cout << dp[n-1];
	return 0;
}

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
	cin >> n;
	vector <int> dp(n);
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a.begin(), a.end());
	dp[0] = 100000000;
	dp[1] = a[1] - a[0];
	for (int i = 2; i < n; ++i) {
		int tmp = a[i] - a[i - 1];
		dp[i] = min(dp[i - 1] + tmp, dp[i - 2] + tmp);
	}
	cout << dp[n - 1];

	return 0;
}

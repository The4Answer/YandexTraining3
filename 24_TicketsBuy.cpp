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
	int n;
	cin >> n;
	vector <int> dp(n);
	vector <st> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].a >> a[i].b >> a[i].c;

	dp[0] = a[0].a;
	if (n > 1)
		dp[1] = min(dp[0] + a[1].a, a[0].b);
	if(n > 2)
		dp[2] = min(min(a[2].a + dp[1], a[1].b + dp[0]), a[0].c);
	for (int i = 3; i < n; ++i) {
		dp[i] = min(dp[i - 1] + a[i].a, min(dp[i - 2] + a[i - 1].b, dp[i - 3] + a[i - 2].c));
	}
	cout << dp[n - 1];
	return 0;
}

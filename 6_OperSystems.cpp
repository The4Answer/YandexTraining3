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
	int m, n;
	cin >> m >> n;
	vector <st> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;

	vector <st> check;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		bool isGood = true;
		for (int j = 0; j < check.size(); ++j) {
			if (check[j].x <= a[i].x && a[i].x <= check[j].y)
			{
				isGood = false;
				break;
			}
			if (check[j].x <= a[i].y && a[i].y <= check[j].y)
			{
				isGood = false;
				break;
			}
			if (a[i].x <= check[j].y && check[j].y <= a[i].y)
			{
				isGood = false;
				break;
			}
			if (a[i].x <= check[j].x && check[j].x <= a[i].y)
			{
				isGood = false;
				break;
			}
		}
		if (isGood) {
			ans++;

		}
		check.push_back(a[i]);
	}
	cout << ans;
	return 0;
}

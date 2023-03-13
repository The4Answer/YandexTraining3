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

int n, m;

struct st {
	int z;
	int i;
	int j;
};

int main() {
	cin >> n;
	vector <vector<vector<char>>>a(n);
	vector <vector<vector<int>>>ans(n);
	st t;
	for (int z = 0; z < n; ++z) {
		a[z].resize(n);
		ans[z].resize(n);
		for (int i = 0; i < n; ++i) {
			a[z][i].resize(n);
			ans[z][i].resize(n, -1);
		}
	}
	for (int z = 0; z < n; ++z)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> a[z][i][j];
				if (a[z][i][j] == 'S')
					t.z = z, t.i = i, t.j = j;
			}
	vector<vector<st>> dist(n * n * n+2);
	dist[0].push_back(t);
	ans[t.z][t.i][t.j] = 0;
	for (int i = 0; i < dist.size(); ++i) {
		for (int j = 0; j < dist[i].size(); ++j) {
			st temp;
			t = dist[i][j];
			if (t.z > 0 && a[t.z - 1][t.i][t.j] == '.' && ans[t.z - 1][t.i][t.j] < 0) {
				temp = t;
				temp.z = t.z - 1;
				dist[i + 1].push_back(temp);
				ans[t.z - 1][t.i][t.j] = i + 1;
			}
			if (t.z < n-1 && a[t.z + 1][t.i][t.j] == '.' && ans[t.z + 1][t.i][t.j] < 0) {
				temp = t;
				temp.z = t.z + 1;
				dist[i + 1].push_back(temp);
				ans[t.z + 1][t.i][t.j] = i + 1;
			}
			if (t.i > 0 && a[t.z][t.i - 1][t.j] == '.' && ans[t.z][t.i - 1][t.j] < 0) {
				temp = t;
				temp.i = t.i - 1;
				dist[i + 1].push_back(temp);
				ans[t.z][t.i - 1][t.j] = i + 1;
			}
			if (t.i < n -1 && a[t.z][t.i + 1][t.j] == '.' && ans[t.z][t.i + 1][t.j] < 0) {
				temp = t;
				temp.i = t.i + 1;
				dist[i + 1].push_back(temp);
				ans[t.z][t.i + 1][t.j] = i + 1;
			}
			if (t.j > 0 && a[t.z][t.i][t.j - 1] == '.' && ans[t.z][t.i][t.j - 1] < 0) {
				temp = t;
				temp.j = t.j - 1;
				dist[i + 1].push_back(temp);
				ans[t.z][t.i][t.j - 1] = i + 1;
			}
			if (t.j < n - 1 && a[t.z][t.i][t.j + 1] == '.' && ans[t.z][t.i][t.j + 1] < 0) {
				temp = t;
				temp.j = t.j + 1;
				dist[i + 1].push_back(temp);
				ans[t.z][t.i][t.j + 1] = i + 1;
			}
		}
	}
	t.z = 0, t.i = 0, t.j = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ans[0][t.i][t.j] > ans[0][i][j] && ans[0][i][j] != -1 || ans[0][t.i][t.j] == -1) {
				t.i = i;
				t.j = j;
			}
		}
	}
	cout << ans[t.z][t.i][t.j];

	return 0;
}

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


int main() {
	cin >> n;
	vector <vector<int>>a(n);
	vector <int>ans(n, -1);
	for (int i = 0; i < n; ++i) 
		a[i].resize(n, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	int s, e;
	cin >> s >> e;
	s--; e--;
	vector<vector<int>> dist(n * n+1);
	dist[0].push_back(s);
	ans[s] = 0;
	for (int i = 0; i < dist.size(); ++i) {
		for (int j = 0; j < dist[i].size(); ++j) {
			for (int z = 0; z < n; ++z) {
				if (ans[z] <= -1 && a[dist[i][j]][z] == 1) {
					dist[i + 1].push_back(z);
					ans[z] = i + 1;
				}
			}
		}
	}
	cout << ans[e];
	return 0;
}

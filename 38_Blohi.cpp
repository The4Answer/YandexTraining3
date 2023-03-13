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
	cin >> n >> m;
	vector <vector<int>>ans(n + 1);
	for (int i = 0; i <= n; ++i) 
		ans[i].resize(m + 1, -1);
	int s, t;
	cin >> s >> t;
	vector<vector<pair<int, int>>> dist(n * m+2);
	dist[0].push_back(make_pair(s, t));
	ans[s][t] = 0;
	for (int i = 0; i < dist.size(); ++i) {
		for (int j = 0; j < dist[i].size(); ++j) {
			pair<int, int> temp = dist[i][j];
			if (temp.first > 2) {	//-2
				if (temp.second > 1 && ans[temp.first -2][temp.second -1] < 0) {
					dist[i + 1].push_back(make_pair(temp.first - 2, temp.second - 1));
					ans[temp.first - 2][temp.second - 1] = i + 1;
				}
				if (temp.second < m && ans[temp.first - 2][temp.second + 1] < 0) {
					dist[i + 1].push_back(make_pair(temp.first - 2, temp.second + 1));
					ans[temp.first - 2][temp.second + 1] = i + 1;
				}
			}
			if (temp.first > 1) {	//-1
				if (temp.second > 2 && ans[temp.first - 1][temp.second - 2] < 0) {
					dist[i + 1].push_back(make_pair(temp.first - 1, temp.second - 2));
					ans[temp.first - 1][temp.second - 2] = i + 1;
				}
				if (temp.second < m-1 && ans[temp.first - 1][temp.second + 2] < 0) {
					dist[i + 1].push_back(make_pair(temp.first - 1, temp.second + 2));
					ans[temp.first - 1][temp.second + 2] = i + 1;
				}
			}
			if (temp.first < n - 1) {//+2
				if (temp.second > 1 && ans[temp.first + 2][temp.second - 1] < 0) {
					dist[i + 1].push_back(make_pair(temp.first + 2, temp.second - 1));
					ans[temp.first + 2][temp.second - 1] = i + 1;
				}
				if (temp.second < m && ans[temp.first + 2][temp.second + 1] < 0) {
					dist[i + 1].push_back(make_pair(temp.first + 2, temp.second + 1));
					ans[temp.first + 2][temp.second + 1] = i + 1;
				}
			}
			if (temp.first < n) {	//+1
				if (temp.second > 2 && ans[temp.first + 1][temp.second - 2] < 0) {
					dist[i + 1].push_back(make_pair(temp.first + 1, temp.second - 2));
					ans[temp.first + 1][temp.second - 2] = i + 1;
				}
				if (temp.second < m - 1 && ans[temp.first + 1][temp.second + 2] < 0) {
					dist[i + 1].push_back(make_pair(temp.first + 1, temp.second + 2));
					ans[temp.first + 1][temp.second + 2] = i + 1;
				}
			}
		}
	}
	
	int q;
	cin >> q;
	int sum = 0;
	for (int i = 0; i < q; ++i) {
		int id1, id2;
		cin >> id1 >> id2;
		if (ans[id1][id2] < 0) {
			cout << -1;
			return 0;
		}
		sum += ans[id1][id2];
	}
	cout << sum;
	return 0;
}

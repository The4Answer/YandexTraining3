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
	int time;
	int val;
	int ind;
	int cont;
};

bool cmp(st f, st s) {
	if (f.time == s.time)
		return f.val > s.val;
	else
		return f.time < s.time;
}

int main() {
	int n, w;
	cin >> n >> w;
	vector<st> a;
	for (int i = 0; i < n; ++i) {
		st temp;
		int cont;
		cin >> temp.time >> cont;
		cont--;
		temp.ind = i + 1;
		temp.cont = cont;
		temp.val = 1;
		a.push_back(temp);
		temp.time += cont;
		temp.val = -1;
		a.push_back(temp);
	}
	sort(a.begin(), a.end(), cmp);
	int current = 0;
	int maxAns = 0;
	vector<vector<int>> ans(1);
	set < pair<int, int>> ansHelp;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i].val > 0) {
			current++;
			if (ans.size()-1 < current) {
				ans.push_back(vector<int> (1,a[i].ind));
				ansHelp.insert(make_pair(a[i].time + a[i].cont, current));
			}
			else {
				pair<int,int> temp = *ansHelp.begin();
				ansHelp.erase(temp);
				ans[temp.second].push_back(a[i].ind);
				temp.first = a[i].time + a[i].cont;
				ansHelp.insert(temp);
			}
		}
		else
			current--;
		if (maxAns < current)
			maxAns = current;
	}
	cout << maxAns << "\n";
	for (int i = 1; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
	}
	return 0;
}

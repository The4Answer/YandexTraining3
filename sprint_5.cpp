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
	int i;
	int j;
};

struct str {
	int caunt;
	map<int, int> direction;
};

int main() {
	
	//input files and etc
	
	int inf = 100000000;
	cin >> n >> m;
	vector<vector<char>> a(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	int si, sj;
	cin >> sj >> si;
	sj--; si--;
	si = (n - 1) - si;
	int ti, tj;
	cin >> tj >> ti;
	ti = n - ti;
	tj--;
	vector <vector<str>> ans(n);
	str tmp;
	tmp.caunt = inf;
	for (int i = 0; i < n; ++i)
		ans[i].resize(m, tmp);

	//solution

	vector<vector<st>> dist(n * n + 2);
	st temp;
	temp.i = si, temp.j = sj;
	dist[0].push_back(temp);
	ans[si][sj].caunt = 1;
	ans[si][sj].direction[1] = 1;
	ans[si][sj].direction[2] = 1;
	ans[si][sj].direction[3] = 1;
	ans[si][sj].direction[4] = 1;
	ans[si][sj].direction[5] = 1;
	ans[si][sj].direction[6] = 1;
	ans[si][sj].direction[7] = 1;
	ans[si][sj].direction[8] = 1;
	//solution
	for (int k = 0; k < dist.size(); ++k) {
		for (int z = 0; z < dist[k].size(); ++z) {
			temp = dist[k][z];						//Node that has been reached with bfs
			str curDirec = ans[temp.i][temp.j];
			if (temp.i > 0) {					//1
				if (a[temp.i - 1][temp.j] == '.') {
					if (curDirec.direction[1] == 1 ) {
						if (ans[temp.i - 1][temp.j].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i - 1][temp.j].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i - 1][temp.j].direction[1] = 1;
							st tm = temp;
							tm.i--;
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i - 1][temp.j].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i - 1][temp.j].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i - 1][temp.j].direction[1] = 1;
							st tm = temp;
							tm.i--;
							dist[k + 1].push_back(tm);
						}
					}
				}
			}
			if (temp.i > 0 && temp.j < m - 1) {	//2
				if (a[temp.i - 1][temp.j + 1] == '.') {
					if (curDirec.direction[2] == 1) {
						if (ans[temp.i - 1][temp.j + 1].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i - 1][temp.j + 1].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i - 1][temp.j + 1].direction[2] = 1;
							st tm = temp;
							tm.i--;
							tm.j++;
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i - 1][temp.j + 1].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i - 1][temp.j + 1].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i - 1][temp.j + 1].direction[2] = 1;
							st tm = temp;
							tm.i--;
							tm.j++;
							dist[k + 1].push_back(tm);
						}
					}
				}
			}
			if (temp.j < m - 1) {				//3
				if (a[temp.i][temp.j + 1] == '.') {
					if (curDirec.direction[3] == 1) {
						if (ans[temp.i ][temp.j + 1].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i][temp.j + 1].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i][temp.j + 1].direction[3] = 1;
							st tm = temp;
							tm.j++;
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i][temp.j + 1].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i][temp.j + 1].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i][temp.j + 1].direction[3] = 1;
							st tm = temp;
							tm.j++;
							dist[k + 1].push_back(tm);
						}
					}
				}
			}
			if (temp.i < n - 1 && temp.j < m - 1) {	//4	
				if (a[temp.i + 1][temp.j + 1] == '.') {
					if (curDirec.direction[4] == 4) {
						if (ans[temp.i + 1][temp.j + 1].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i + 1][temp.j + 1].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i + 1][temp.j + 1].direction[4] = 1;
							st tm = temp;
							tm.i++;
							tm.j++;
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i + 1][temp.j + 1].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i + 1][temp.j + 1].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i + 1][temp.j + 1].direction[4] = 1;
							st tm = temp;
							tm.i++;
							tm.j++;
							dist[k + 1].push_back(tm);
						}
					}
				}
			}
			if (temp.i < n - 1) {					//5
				if (a[temp.i + 1][temp.j] == '.') {
					if (curDirec.direction[5] == 1) {
						if (ans[temp.i + 1][temp.j].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i + 1][temp.j].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i + 1][temp.j].direction[5] = 1;
							st tm = temp;
							tm.i++;
							
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i + 1][temp.j].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i + 1][temp.j].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i + 1][temp.j].direction[5] = 1;
							st tm = temp;
							tm.i++;

							dist[k + 1].push_back(tm);
						}
					}
				}
			}
			if (temp.i < n - 1 && temp.j > 0) {		//6
				if (a[temp.i + 1][temp.j - 1] == '.') {
					if (curDirec.direction[6] == 1) {
						if (ans[temp.i + 1][temp.j - 1].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i + 1][temp.j - 1].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i + 1][temp.j - 1].direction[6] = 1;
							st tm = temp;
							tm.i++;
							tm.j--;
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i + 1][temp.j - 1].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i + 1][temp.j - 1].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i + 1][temp.j - 1].direction[6] = 1;
							st tm = temp;
							tm.i++;
							tm.j--;
							dist[k + 1].push_back(tm);
						}
					}
				}
			}
			if (temp.j > 0) {						//7
				if (a[temp.i][temp.j - 1] == '.') {
					if (curDirec.direction[7] == 1 ) {
						if (ans[temp.i][temp.j - 1].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i][temp.j - 1].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i][temp.j - 1].direction[7] = 1;
							st tm = temp;
							
							tm.j--;
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i][temp.j - 1].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i][temp.j - 1].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i][temp.j - 1].direction[7] = 1;
							st tm = temp;

							tm.j--;
							dist[k + 1].push_back(tm);
						}
					}
				}
			}
			if (temp.i > 0 && temp.j > 0) {			//8
				if (a[temp.i - 1][temp.j - 1] == '.') {
					if (curDirec.direction[8] == 1) {
						if (ans[temp.i - 1][temp.j - 1].caunt > ans[temp.i][temp.j].caunt) {
							ans[temp.i - 1][temp.j - 1].caunt = ans[temp.i][temp.j].caunt;
							ans[temp.i - 1][temp.j - 1].direction[8] = 1;
							st tm = temp;
							tm.i--;
							tm.j--;
							dist[k + 1].push_back(tm);
						}
					}
					else {
						if (ans[temp.i - 1][temp.j - 1].caunt > ans[temp.i][temp.j].caunt + 1) {
							ans[temp.i - 1][temp.j - 1].caunt = ans[temp.i][temp.j].caunt + 1;
							ans[temp.i - 1][temp.j - 1].direction[8] = 1;
							st tm = temp;
							tm.i--;
							tm.j--;
							dist[k + 1].push_back(tm);
						}
					}
				}
			}
		}
	}
	if (ans[ti][tj].caunt >= inf) {
		cout << -1;
		return 0;
	}
	cout << ans[ti][tj].caunt;

	return 0;
}

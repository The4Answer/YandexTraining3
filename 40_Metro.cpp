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
	cin >> n >> m;
	vector<vector<int>> NtoM(n + 1);			//to which lines belongs each ni station
	vector<vector<int>> MwithN(m + 1);	//which stations contains each mi line
	for (int i = 1; i <= m; ++i) {
		int size;
		cin >> size;
		MwithN[i].resize(size);
		for (int j = 0; j < size; ++j) {
			cin >> MwithN[i][j];
			NtoM[MwithN[i][j]].push_back(i);
		}
	}
	int s, e;
	cin >> s >> e;
	vector<int> ans(n + 1, -1);
	ans[s] = 0;
	vector<vector<int>> dist(n * n+2);
	dist[0].push_back(s);
	for (int i = 0; i < NtoM[s].size(); ++i) {
		for (int j = 0; j < MwithN[NtoM[s][i]].size(); ++j) {
			if (ans[MwithN[NtoM[s][i]][j]] < 0) {
				ans[MwithN[NtoM[s][i]][j]] = 0;
				dist[0].push_back(MwithN[NtoM[s][i]][j]);
			}
		}
	}
	//solution
	for (int k = 0; k < dist.size(); ++k) {
		for (int z = 0; z < dist[k].size(); ++z) {
			int station = dist[k][z];
			//check all lines
			for (int i = 0; i < NtoM[station].size(); ++i) {
				//add all stations that belongs to our node's lines
				for (int j = 0; j < MwithN[NtoM[station][i]].size(); ++j) {
					if (ans[MwithN[NtoM[station][i]][j]] < 0) {
						ans[MwithN[NtoM[station][i]][j]] = k + 1;
						dist[k+1].push_back(MwithN[NtoM[station][i]][j]);
					}
				}
			}
		}
	}
	cout << ans[e];

	return 0;
}

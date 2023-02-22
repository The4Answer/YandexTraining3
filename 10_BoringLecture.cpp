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
	string s;
	cin >> s;
	map <char, long long> M;
	set <char> ss;
	for (int i = 0; i < s.size(); ++i) {
		M[s[i]] += (i + 1) * (s.size() - i);
		ss.insert(s[i]);
	}
	int n = ss.size();
	for (int i = 0; i < n; ++i) {
		char t = *ss.begin();
		ss.erase(ss.begin());
		cout << t << ": " << M[t] << "\n";
	}
	return 0;
}

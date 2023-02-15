//#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <ctime>



using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");


int main() {
	//string s;
	//getline(cin, s);
	vector <char> symb;
	map <char, int> count;
	int MAX = 0;
	/*while (getline(cin, s)) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' ')
				continue;
			if (count[s[i]] < 1) {
				symb.push_back(s[i]);
			}
			count[s[i]]++;
			if (count[s[i]] > MAX)
				MAX = count[s[i]];
		}
		getline(cin, s);
	}*/
	char t;
	while (cin >> t) {
		if (t == ' ')
			continue;
		if (count[t] < 1) {
			symb.push_back(t);
		}
		count[t]++;
		if (count[t] > MAX)
			MAX = count[t];
	}
	sort(symb.begin(), symb.end());

	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < symb.size(); ++j) {

			if (count[symb[j]] >= MAX - i)
				cout << "#";
			else
				cout << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < symb.size(); ++i)
		cout << symb[i];
	return 0;
}

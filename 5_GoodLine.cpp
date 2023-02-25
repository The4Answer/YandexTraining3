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
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int zeros = 0;
	int inf = 1000000009;
	long long ans = 0;
	while (zeros < n) {
		long long nice = 0;
		long long minim = a[0];
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] > 0 && a[i] > 0)
				nice++;
			else if (minim != inf) {
				ans += nice * minim;
				for (int j = i - nice - 1; j < i; ++j)
					a[j] -= minim;
				minim = inf;
				nice = 0;
			}
			if (a[i] < minim && a[i] != 0)
				minim = a[i];
		}
		if (nice > 0) {
			ans += nice * minim;
			for (int j = n - nice - 1; j < n; ++j)
				a[j] -= minim;
			minim = inf;
			nice = 0;
		}
		zeros++;
	}
	cout << ans;
	return 0;
}

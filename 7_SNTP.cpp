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

int toInt(char f, char s) {
	int fir = f - '0';
	int sec = s - '0';
	return fir * 10 + sec;
}

int main() {
	string A, B, C;
	cin >> A >> B >> C;
	int s = toInt(C[6], C[7]) - toInt(A[6], A[7]);
	int mins = 0;
	int hours = 0;
	if (s < 0)
	{
		s += 60;
		mins--;
	}
	mins += toInt(C[3], C[4]) - toInt(A[3], A[4]);
	if (mins < 0)
	{
		mins += 60;
		hours--;
	}
	hours += toInt(C[0], C[1]) - toInt(A[0], A[1]);
	if (hours < 0)
		hours += 24;
	
	
	int time = hours * 60 * 60 + mins * 60 + s;
	if (time % 2 != 0) 
		time++;
	time /= 2;
	hours = time / 3600;
	time -= hours * 3600;
	mins = time / 60;
	time -= mins * 60;
	s = time;

	s += toInt(B[6], B[7]);
	if (s > 59) {
		s -= 60;
		mins++;
	}
	mins += toInt(B[3], B[4]);
	if (mins > 59) {
		mins -= 60;
		hours++;
	}
	hours += toInt(B[0], B[1]);
	if (hours > 23)
		hours -= 24;
	if (hours < 10) {
		cout << "0" << hours << ":";
	}
	else
		cout << hours << ":";
	if (mins < 10)
		cout << "0" << mins << ":";
	else
		cout << mins << ":";
	if (s < 10)
		cout << "0" << s;
	else
		cout << s;
	return 0;
}

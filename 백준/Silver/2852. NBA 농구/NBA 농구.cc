#include <bits/stdc++.h>
using namespace std;

int teamScore[3];
string prevTime = "00:00";
string winningTime[3] = { "00:00", "00:00", "00:00" };

int toTime(const string& str) {
	int MM = stoi(str.substr(0, 2));
	int SS = stoi(str.substr(3, 2));
	return (MM * 60 + SS);
}

string toString(int time) {
	stringstream ss;
	ss << setfill('0') << setw(2) << time / 60 << ':' << setfill('0') << setw(2) << time % 60;
	return ss.str();
}

string addTime(const string& t1, const string& t2) { return toString(toTime(t1) + toTime(t2)); }

string subtractTime(const string& t1, const string& t2) { return toString(toTime(t2) - toTime(t1)); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int teamNum;
		string goalTime;
		cin >> teamNum >> goalTime;

		if (teamScore[1] != teamScore[2]) {
			string timeLag = subtractTime(prevTime, goalTime);
			if (teamScore[1] > teamScore[2]) winningTime[1] = addTime(winningTime[1], timeLag);
			else winningTime[2] = addTime(winningTime[2], timeLag);
		}

		teamScore[teamNum]++;
		prevTime = goalTime;
	}

	string finalTime = "48:00";
	if (teamScore[1] != teamScore[2]) {
		string timeLag = subtractTime(prevTime, finalTime);
		if (teamScore[1] > teamScore[2]) winningTime[1] = addTime(winningTime[1], timeLag);
		else winningTime[2] = addTime(winningTime[2], timeLag);
	}

	cout << winningTime[1] << '\n' << winningTime[2] << '\n';
	return 0;
}
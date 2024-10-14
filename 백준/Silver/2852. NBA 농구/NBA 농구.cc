#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int teamScore[3];
string prevTime = "00:00";
string winningTime[3] = { "00:00", "00:00", "00:00" };

pii toTime(const string& str) {
	int MM = stoi(str.substr(0, 2));
	int SS = stoi(str.substr(3, 2));
	return { MM, SS };
}

string toString(const pii& time) {
	stringstream ss;
	ss << setfill('0') << setw(2) << time.first << ':' << setfill('0') << setw(2) << time.second;
	return ss.str();
}

string addTime(const string& t1, const string& t2) {
	pii time1 = toTime(t1);
	pii time2 = toTime(t2);
	int newMM = time2.first + time1.first;
	int newSS = time2.second + time1.second;
	if (newSS >= 60) { newMM += 1; newSS -= 60; }
	return toString({ newMM, newSS });
}

string subtractTime(const string& t1, const string& t2) {
	pii from = toTime(t1);
	pii to = toTime(t2);
	int newMM = to.first - from.first;
	int newSS = to.second - from.second;
	if (newSS < 0) { newMM -= 1; newSS += 60; }
	return toString({ newMM, newSS });
}

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
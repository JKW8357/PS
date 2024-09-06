#include <bits/stdc++.h>
using namespace std;

map<string, bool> visited;
string cur[40];

bool check() {
	for (int i = 1; i < 36; i++) {
		if (visited[cur[i]]) return false;
		else {
			bool check1 = abs(cur[i][0] - cur[i - 1][0]) == 1 && abs(cur[i][1] - cur[i - 1][1]) == 2;
			bool check2 = abs(cur[i][0] - cur[i - 1][0]) == 2 && abs(cur[i][1] - cur[i - 1][1]) == 1;
			if (!(check1 || check2)) return false;
			visited[cur[i]] = true;
		}
	}

	bool check1 = abs(cur[0][0] - cur[35][0]) == 1 && abs(cur[0][1] - cur[35][1]) == 2;
	bool check2 = abs(cur[0][0] - cur[35][0]) == 2 && abs(cur[0][1] - cur[35][1]) == 1;
	return (check1 || check2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 36; i++) cin >> cur[i];
	cout << (check() ? "Valid\n" : "Invalid\n");
	return 0;
}
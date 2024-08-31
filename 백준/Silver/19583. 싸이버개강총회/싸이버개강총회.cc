#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> um;

int calctime(string time) {
	int h = stoi(time.substr(0, 2));
	int s = stoi(time.substr(3, 2));
	return 60 * h + s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, e, q;
	cin >> s >> e >> q;

	int start = calctime(s);
	int end = calctime(e);
	int stream = calctime(q);

	int cnt = 0;
	string time, name;

	while (cin >> time >> name) {
		int t = calctime(time);
		if (t <= start) um[name] = true;
		if (t >= end && t <= stream && um[name]) {
			um.erase(name);
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}
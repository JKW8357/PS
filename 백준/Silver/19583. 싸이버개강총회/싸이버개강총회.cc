#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string start, end, stream;
	cin >> start >> end >> stream;

	int cnt = 0;
	string time, name;

	while (cin >> time >> name) {
		if (time <= start) um[name] = true;
		if (time >= end && time <= stream && um[name]) {
			um.erase(name);
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}
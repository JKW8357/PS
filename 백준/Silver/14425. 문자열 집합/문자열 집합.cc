#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	while (n--) {
		string str;
		cin >> str;
		s.insert(str);
	}

	int cnt = 0;
	while (m--) {
		string str;
		cin >> str;
		if (s.find(str) != s.end()) cnt++;
	}

	cout << cnt;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		s.insert(name);
	}
	for (int i = 0; i < n - 1; i++) {
		string name; cin >> name;
		s.erase(name);
	}
	cout << *s.begin() << '\n';

	return 0;
}
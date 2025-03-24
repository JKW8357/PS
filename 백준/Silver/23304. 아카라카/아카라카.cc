#include <bits/stdc++.h>
using namespace std;

bool isAkaraka(string& s) {
	if (s.size() == 1) return true;

	string left = s.substr(0, s.size() / 2);
	string right = s.substr((s.size() + 1) / 2);

	return left == right && isAkaraka(left) && isAkaraka(right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s; cin >> s;
	cout << (isAkaraka(s) ? "AKARAKA\n" : "IPSELENTI\n");

	return 0;
}
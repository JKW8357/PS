#include <bits/stdc++.h>
using namespace std;

int n;

bool check(const string& str) {
	int size = (int)str.size();
	for (int i = 1; i <= size / 2; i++)
		if (str.substr(size - i * 2, i) == str.substr(size - i, i)) return false;
	return true;
}

void solve(const string& str, int depth) {
	if (depth == n) {
		cout << str << '\n';
		exit(0);
	}

	for (char c : { '1', '2', '3'}) {
		if (!check(str + c)) continue;
		solve(str + c, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve("", 0);

	return 0;
}
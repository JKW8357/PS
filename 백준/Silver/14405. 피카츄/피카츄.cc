#include <bits/stdc++.h>
using namespace std;

bool check(const string& str) {
	int idx = 0, size = str.size();
	while (idx < size) {
		if (str.find("pi", idx) == idx) idx += 2;
		else if (str.find("ka", idx) == idx) idx += 2;
		else if (str.find("chu", idx) == idx) idx += 3;
		else return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	cout << (check(str) ? "YES\n" : "NO\n");

	return 0;
}
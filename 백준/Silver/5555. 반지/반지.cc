#include <bits/stdc++.h>
using namespace std;

bool check(const string& target, string& str) {
	str += str;
	if (str.find(target) != string::npos) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string target;
	int n;
	cin >> target >> n;

	int cnt = 0;
	while (n--) {
		string str;
		cin >> str;
		if (check(target, str)) cnt++;
	}

	cout << cnt << '\n';
	return 0;
}
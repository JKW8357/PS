#include <bits/stdc++.h>
using namespace std;

bool akaraka(string& str) {
	int size = str.size();
	if (size == 1) return true;

	string tmp(str);
	reverse(tmp.begin(), tmp.end());
	if (str != tmp) return false;

	string s1 = str.substr(0, size / 2);
	string s2 = str.substr(size - size / 2, size);

	return (akaraka(s1) && akaraka(s2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	cout << (akaraka(str) ? "AKARAKA\n" : "IPSELENTI\n");

	return 0;
}
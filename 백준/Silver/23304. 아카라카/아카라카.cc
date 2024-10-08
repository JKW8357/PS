#include <bits/stdc++.h>
using namespace std;

bool akaraka(string& str) {
	if (str.size() == 1) return true;

	int size = str.size();

	string s1 = str.substr(0, size / 2);
	string revS1 = s1;
	reverse(revS1.begin(), revS1.end());

	string s2 = str.substr(size - size / 2, size);
	string revS2 = s2;
	reverse(revS2.begin(), revS2.end());

	if (s1 != revS1 || s2 != revS2) return false;

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
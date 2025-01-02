#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	bitset<100000> a(s1);
	bitset<100000> b(s2);
	cout << (a & b) << '\n'
		<< (a | b) << '\n'
		<< (a ^ b) << '\n'
		<< ~a << '\n'
		<< ~b << '\n';

	return 0;
}
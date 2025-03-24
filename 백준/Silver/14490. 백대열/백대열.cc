#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s; cin >> s;
	int splitIdx = s.find(':');
	int n = stoi(s.substr(0, splitIdx));
	int m = stoi(s.substr(splitIdx + 1));

	int GCD = gcd(n, m);
	n /= GCD; m /= GCD;

	cout << n << ':' << m << '\n';

	return 0;
}
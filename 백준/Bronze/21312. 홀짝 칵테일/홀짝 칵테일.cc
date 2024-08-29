#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	if (a % 2 != b % 2) return a % 2 > b % 2;
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> v = { a, b, c, a * b, a * c, b * c, a * b * c };
	sort(v.begin(), v.end(), cmp);
	cout << v[0] << '\n';

	return 0;
}
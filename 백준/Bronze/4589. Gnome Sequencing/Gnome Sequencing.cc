#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c) {
	return (a < b && b < c) || (a > b && b > c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << "Gnomes:\n";
	int n; cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << (check(a, b, c) ? "Ordered\n" : "Unordered\n");
	}

	return 0;
}
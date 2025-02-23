#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	cout << (n % 7 != 0 && n % 7 != 2 ? "SK" : "CY") << '\n';

	return 0;
}
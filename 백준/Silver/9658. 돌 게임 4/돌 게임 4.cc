#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	cout << (n % 7 != 1 && n % 7 != 3 ? "SK" : "CY") << '\n';

	return 0;
}
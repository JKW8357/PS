#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unsigned long long x; cin >> x;
	cout << popcount(x) << '\n';
	return 0;
}
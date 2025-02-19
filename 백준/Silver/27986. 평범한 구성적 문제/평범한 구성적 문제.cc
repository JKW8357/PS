#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int w = INT_MAX;
	while (m--) {
		int l, r;
		cin >> l >> r;
		w = min(w, r - l + 1);
	}

	for (int i = 0; i < n; i++) 
		cout << i % w + 1 << ' ';

	return 0;
}
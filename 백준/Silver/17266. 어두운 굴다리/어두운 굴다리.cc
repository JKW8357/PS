#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[100005];

bool param(int cur) {
	for (int i = 0; i < m - 1; i++)
		if (x[i] + cur < x[i + 1] - cur)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> x[i];
	
	int lo = max(x[0], n - x[m - 1]) - 1, hi = 100001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (param(mid)) hi = mid;
		else lo = mid;
	}

	cout << hi << '\n';
	return 0;
}
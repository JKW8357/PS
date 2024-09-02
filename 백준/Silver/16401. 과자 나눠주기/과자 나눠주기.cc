#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
int arr[1000005];

bool param(ll num) {
	ll sum = 0;
	for (int i = 0; i < n; i++) sum += arr[i] / num;
	return sum >= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	ll lo = 0, hi = 1e10 + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (param(mid)) lo = mid;
		else hi = mid;
	}

	cout << lo << '\n';
	return 0;
}
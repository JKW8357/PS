#include <bits/stdc++.h>
using namespace std;

int sensor[10005];
int gap[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> sensor[i];
	sort(sensor, sensor + n);
	for (int i = 0; i < n - 1; i++) gap[i] = sensor[i + 1] - sensor[i];
	sort(gap, gap + n - 1, greater<int>());
	int sum = accumulate(gap + min(n, k) - 1, gap + n - 1, 0);
	cout << sum << '\n';

	return 0;
}
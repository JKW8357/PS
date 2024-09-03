#include <bits/stdc++.h>
using namespace std;

int n, s;
int ans = 0;
int arr[25];

void solve(int depth, int sum) {
	if (depth == n) {
		if (sum == s) ans++;
		return;
	}

	solve(depth + 1, sum);
	solve(depth + 1, sum + arr[depth]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	solve(0, 0);
	cout << (s == 0 ? ans - 1 : ans) << '\n';

	return 0;
}
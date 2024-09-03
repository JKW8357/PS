#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
bool isused1[40]; // 열 방향 탐색
bool isused2[40]; // 대각선 탐색 1
bool isused3[40]; // 대각선 탐색 2

void solve(int depth) {
	if (depth == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[i - depth + n - 1] || isused3[i + depth]) continue;
		isused1[i] = true;
		isused2[i - depth + n - 1] = true;
		isused3[i + depth] = true;
		solve(depth + 1);
		isused1[i] = false;
		isused2[i - depth + n - 1] = false;
		isused3[i + depth] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve(0);
	cout << ans << '\n';

	return 0;
}
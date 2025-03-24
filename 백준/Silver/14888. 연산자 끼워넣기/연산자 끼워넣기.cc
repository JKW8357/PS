#include <bits/stdc++.h>
using namespace std;

int n;
int mx = INT_MIN;
int mn = INT_MAX;
int arr[12];
int op[4];

void solve(int idx, int val) {
	if (idx == n) {
		mx = max(mx, val);
		mn = min(mn, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0) solve(idx + 1, val + arr[idx]);
			if (i == 1) solve(idx + 1, val - arr[idx]);
			if (i == 2) solve(idx + 1, val * arr[idx]);
			if (i == 3) solve(idx + 1, val / arr[idx]);
			op[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> op[i];

	// 불필요한 예외 처리 방지를 위해 2번째 수부터 연산 수행
	solve(1, arr[0]);
	cout << mx << '\n' << mn << '\n';
	
	return 0;
}
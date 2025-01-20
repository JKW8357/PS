#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int cnt = 0;
int hp[8];
int atk[8];

void solve(int cur) {
	if (cur == n) {
		ans = max(ans, cnt);
		return;
	}

	if (hp[cur] <= 0 || cnt == n - 1) {
		solve(cur + 1);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (hp[i] <= 0 || i == cur) continue;
		hp[i] -= atk[cur];
		hp[cur] -= atk[i];
		if (hp[i] <= 0) cnt++;
		if (hp[cur] <= 0) cnt++;
		solve(cur + 1);
		if (hp[i] <= 0) cnt--;
		if (hp[cur] <= 0) cnt--;
		hp[i] += atk[cur];
		hp[cur] += atk[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> hp[i] >> atk[i];

	solve(0);
	cout << ans << '\n';

	return 0;
}
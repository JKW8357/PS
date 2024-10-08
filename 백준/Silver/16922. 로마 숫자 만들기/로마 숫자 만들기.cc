#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int num[4] = { 1, 5, 10, 50 };
bool res[1005];

void solve(int idx, int depth, int ans) {
	if (depth == n) {
		if (!res[ans]) {
			res[ans] = true;
			cnt++;
		}
		return;
	}
	
	for (int i = idx; i < 4; i++)
		solve(i, depth + 1, ans + num[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	solve(0, 0, 0);
	cout << cnt << '\n';

	return 0;
}
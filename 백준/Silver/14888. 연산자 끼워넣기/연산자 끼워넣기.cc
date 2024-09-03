#include <bits/stdc++.h>
using namespace std;

int n;
int max_val = INT_MIN, min_val = INT_MAX;
int arr[15];
int cal[4];

void solve(int cur, int depth) {
	if (depth == n) {
		max_val = max(max_val, cur);
		min_val = min(min_val, cur);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cal[i] == 0) continue;
		cal[i]--;
		
		if (i == 0) solve(cur + arr[depth], depth + 1);
		else if (i == 1) solve(cur - arr[depth], depth + 1);
		else if (i == 2) solve(cur * arr[depth], depth + 1);
		else solve(cur / arr[depth], depth + 1);
		cal[i]++; // 사용한 연산자를 복원해야 나머지 재귀 과정도 정상적으로 수행 가능(backtracking)
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> cal[i];
	solve(arr[0], 1);
	cout << max_val << '\n' << min_val << '\n';

	return 0;
}
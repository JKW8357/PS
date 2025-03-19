#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
bool vis[10];
vector<int> arr;
vector<int> vec;

void solve(int depth) {
	if (depth == n) {
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
			sum += abs(vec[i] - vec[i + 1]);
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		vec.push_back(arr[i]);
		vis[i] = true;

		solve(depth + 1);

		vis[i] = false;
		vec.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	solve(0);
	
	cout << ans << '\n';
	return 0;
}
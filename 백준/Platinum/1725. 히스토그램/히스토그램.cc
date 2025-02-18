#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int h; cin >> h;
		int idx = i;
		while (!st.empty() && st.top().first >= h) {
			ans = max(ans, (i - st.top().second) * st.top().first);
			idx = st.top().second;
			st.pop();
		}
		st.push({ h, idx });
	}

	while (!st.empty()) {
		ans = max(ans, (n - st.top().second) * st.top().first);
		st.pop();
	}

	cout << ans << '\n';
	return 0;
}

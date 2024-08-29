#include <bits/stdc++.h>
using namespace std;

int ans[500005];
stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;
		while (!st.empty() && st.top().first < height) st.pop();
		ans[i] = (!st.empty() ? st.top().second : 0);
		st.push({ height, i });
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}
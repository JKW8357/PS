#include <bits/stdc++.h>
using namespace std;

int ans[1000005];
pair<int, int> tower[1000005];
stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tower[i].first;
		tower[i].second = i;
	}

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && st.top().first < tower[i].first) st.pop();
		ans[i] = (!st.empty() ? st.top().second : 0);
		st.push(tower[i]);
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}
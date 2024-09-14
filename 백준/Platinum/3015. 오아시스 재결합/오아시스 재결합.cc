#include <bits/stdc++.h>
using namespace std;

int arr[500005];
stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		while (!st.empty() && st.top().first <= arr[i]) {
			ans += st.top().second;
			if (st.top().first == arr[i]) cnt += st.top().second;
			st.pop();
		}
		if (!st.empty()) ans++;
		st.push({ arr[i], cnt });
	}

	cout << ans << '\n';
	return 0;
}
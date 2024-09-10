#include <bits/stdc++.h>
using namespace std;

int arr[200005];
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int ans = 0;
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && st.top() < arr[i]) {
			st.pop();
			ans++;
		}
		if (!st.empty()) ans++;
		st.push(arr[i]);
	}

	cout << ans << '\n';
	return 0;
}
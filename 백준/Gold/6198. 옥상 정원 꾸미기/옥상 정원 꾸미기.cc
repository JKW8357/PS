#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;
		while (!st.empty() && st.top() <= height) st.pop();
		ans += st.size();
		st.push(height);
	}

	cout << ans << ' ';
	return 0;
}
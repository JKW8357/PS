#include <bits/stdc++.h>
using namespace std;

long long buildings[80005];
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> buildings[i];
		while (!st.empty() && st.top() <= buildings[i]) st.pop();
		ans += st.size();
		st.push(buildings[i]);
	}

	cout << ans << ' ';
	return 0;
}
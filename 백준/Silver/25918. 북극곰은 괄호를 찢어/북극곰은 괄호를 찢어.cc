#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;

	int ans = 0;
	for (char c : s) {
		if (st.empty() || st.top() == c) {
			st.push(c);
			ans = max(ans, (int)st.size());
		}
		else st.pop();
	}

	cout << (st.empty() ? ans : -1) << '\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

stack<char> st;
vector<char> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	string str; cin >> str;
	for (char c : str) {
		while (!st.empty() && st.top() < c && k > 0) { st.pop(); k--; }
		st.push(c);
	}

	while (k--) st.pop();
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i];
	return 0;
}